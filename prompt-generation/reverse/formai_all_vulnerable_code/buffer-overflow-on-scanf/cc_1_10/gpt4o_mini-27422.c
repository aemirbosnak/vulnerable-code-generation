//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu() {
    printf("\n***** E-Book Reader *****\n");
    printf("1. Add New Book\n");
    printf("2. Read a Book\n");
    printf("3. List All Books\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    
    printf("Enter book title: ");
    getchar(); // Consume newline
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    printf("Enter book content: ");
    fgets(newBook.content, MAX_CONTENT_LENGTH, stdin);
    newBook.content[strcspn(newBook.content, "\n")] = 0; // Remove newline
    
    library[*bookCount] = newBook;
    (*bookCount)++;
    
    printf("Book added successfully!\n");
}

void readBook(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available to read.\n");
        return;
    }

    printf("\nSelect a book to read (1 to %d): ", bookCount);
    int bookIndex;
    scanf("%d", &bookIndex);
    
    if (bookIndex < 1 || bookIndex > bookCount) {
        printf("Invalid book selection.\n");
        return;
    }
    
    // Display book details
    Book selectedBook = library[bookIndex - 1];
    printf("\n***** Reading: %s *****\n", selectedBook.title);
    printf("Author: %s\n", selectedBook.author);
    printf("\n%s\n", selectedBook.content);
}

void listBooks(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\n***** List of Books *****\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                readBook(library, bookCount);
                break;
            case 3:
                listBooks(library, bookCount);
                break;
            case 4:
                printf("Exiting the E-Book Reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}