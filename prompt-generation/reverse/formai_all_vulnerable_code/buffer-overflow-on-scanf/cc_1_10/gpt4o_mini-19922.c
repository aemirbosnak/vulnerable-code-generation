//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the book
typedef struct {
    char title[100];
    char author[100];
    char content[1000];
} Book;

// Function prototypes
void displayBook(Book book);
void readEbook(const char *filename, Book *book);
void searchWordInBook(Book book, const char *word);
void displayMenu();

int main() {
    printf("🌟 Welcome to the Surprise Ebook Reader! 📚\n\n");

    Book myBook;
    const char *filename = "sample_ebook.txt";

    // Read the ebook from file
    readEbook(filename, &myBook);
    
    // Display the book information
    displayBook(myBook);

    // Provide user options
    char choice;
    do {
        displayMenu();
        printf("Choose an option (1-3 or q to quit): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                printf("You chose to read the book again!\n");
                displayBook(myBook);
                break;
            case '2': {
                char word[50];
                printf("Enter a word to search in the book: ");
                scanf("%s", word);
                searchWordInBook(myBook, word);
                break;
            }
            case '3':
                printf("Thank you for using the Surprise Ebook Reader! 📖✨\n");
                break;
            case 'q':
                printf("Quitting the program... Goodbye! 👋\n");
                break;
            default:
                printf("🚫 Invalid option! Please try again.\n");
        }
    } while (choice != '3' && choice != 'q');

    return 0;
}

// Function to display a book's title, author, and content
void displayBook(Book book) {
    printf("\n📖 Title: %s\n", book.title);
    printf("✍️ Author: %s\n", book.author);
    printf("💬 Content:\n%s\n", book.content);
}

// Function to read the ebook from a file
void readEbook(const char *filename, Book *book) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fgets(book->title, sizeof(book->title), file);
    fgets(book->author, sizeof(book->author), file);
    fgets(book->content, sizeof(book->content), file);
    fclose(file);
}

// Function to search for a word in the book's content
void searchWordInBook(Book book, const char *word) {
    if (strstr(book.content, word) != NULL) {
        printf("🔍 The word '%s' was found in the book!\n", word);
    } else {
        printf("🚫 The word '%s' was NOT found in the book.\n", word);
    }
}

// Function to display available options to the user
void displayMenu() {
    printf("\n🎈 Menu: 🎈\n");
    printf("1. Read the book again\n");
    printf("2. Search for a word in the book\n");
    printf("3. Exit the application\n");
}

// Note: Make sure to create a 'sample_ebook.txt' with the following content before running the program:
// Title: My Surprise Book
// Author: A Surprised Author
// Content: This is a very surprising ebook meant to bring joy and surprises to readers!