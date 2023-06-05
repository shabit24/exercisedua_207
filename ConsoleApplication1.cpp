#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Author; // Forward declaration

class Publisher
{
private:
    string publisherName;
    vector<Author*> authors;

public:
    Publisher(const string& name) : publisherName(name) {}

    void addAuthor(Author* author)
    {
        authors.push_back(author);
    }

    string getName() const
    {
        return publisherName;
    }

    void listAuthors()
    {
        cout << "List of authors at the publishing house \"" << publisherName << "\":\n";
        for (const auto& author : authors)
        {
            cout << author->getName() << "\n";
        }
        cout << endl;
    }
};

class Author
{
private:
    string authorName;
    vector<string> books;

public:
    Author(const string& name) : authorName(name) {}

    void addBook(const string& book)
    {
        books.push_back(book);
    }

    string getName() const
    {
        return authorName;
    }

    void listBooks()
    {
        cout << "List of books authored by \"" << authorName << "\":\n";
        for (const auto& book : books)
        {
            cout << book << "\n";
        }
        cout << std::endl;
    }
};

int main() {
    // Create publishers
    Publisher gamaPress("Gama Press");
    Publisher intanPariwara("Intan Pariwara");

    // Create authors
    Author joko("Joko");
    Author lia("Lia");
    Author giga("Giga");
    Author asroni("Asroni");

    // Create books
    joko.addBook("Physics");
    joko.addBook("Algorithm");
    lia.addBook("Database");
    asroni.addBook("Basic Programming");
    giga.addBook("Mathematics");
    giga.addBook("Multimedia 1");

    // Associate authors with publishers
    gamaPress.addAuthor(&joko);
    gamaPress.addAuthor(&lia);
    gamaPress.addAuthor(&giga);
    intanPariwara.addAuthor(&giga);
    intanPariwara.addAuthor(&asroni);

    // List authors at Gama Press
    gamaPress.listAuthors();

    // List authors at Intan Pariwara
    intanPariwara.listAuthors();

    // List publishers followed by Giga
    cout << "List of publishers followed by \"Giga\":\n";
    cout << gamaPress.getName() << "\n";
    cout << intanPariwara.getName() << "\n\n";

    // List books authored by Joko
    joko.listBooks();

    // List books authored by Lia
    lia.listBooks();

    // List books authored by Asroni
    asroni.listBooks();

    // List books authored by Giga
    giga.listBooks();

    return 0;
}
