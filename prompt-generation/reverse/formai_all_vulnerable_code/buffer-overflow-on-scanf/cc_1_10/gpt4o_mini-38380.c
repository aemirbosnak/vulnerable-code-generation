//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_CONTENT_LENGTH 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Book;

void displayMenu();
void addBook(Book *library, int *bookCount);
void viewBooks(Book *library, int bookCount);
void readBook(const Book *book);
void clearBuffer();

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                printf("Exiting the reader. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\n--- E-Book Reader Menu ---\n");
    printf("1. Add a new book\n");
    printf("2. View books\n");
    printf("3. Exit\n");
}

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Can't add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // Remove the newline character
    printf("Enter the author of the book: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n"); // Remove the newline character
    printf("Enter the content of the book (max 1024 characters): ");
    fgets(newBook.content, MAX_CONTENT_LENGTH, stdin);
    strtok(newBook.content, "\n"); // Remove the newline character

    library[*bookCount] = newBook; // Add new book to library
    (*bookCount)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book *library, int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Press Enter to read...\n");
        getchar(); // Wait for user to press Enter
        readBook(&library[i]);
    }
}

void readBook(const Book *book) {
    printf("\n--- Reading Book: %s ---\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Content:\n%s\n", book->content);
    printf("Press Enter to go back to menu...\n");
    getchar(); // Wait for user to press Enter
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}