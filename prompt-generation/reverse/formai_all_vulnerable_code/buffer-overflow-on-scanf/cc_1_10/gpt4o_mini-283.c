//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Function prototypes
void addBook(Library *library);
void displayBooks(Library *library);
void searchBook(Library *library);
void clearInputBuffer();

int main() {
    Library library;
    library.count = 0;
    int choice;

    do {
        printf("\nLibrary Database System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear newline character from input buffer.

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                displayBooks(&library);
                break;
            case 3:
                searchBook(&library);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(Library *library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    clearInputBuffer();

    printf("Enter Book Title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    library->books[library->count++] = newBook;
    printf("Book added successfully!\n");
}

void displayBooks(Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library->books[i].id, library->books[i].title, library->books[i].author);
    }
}

void searchBook(Library *library) {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < library->count; i++) {
        if (library->books[i].id == id) {
            printf("Book Found: ID: %d, Title: %s, Author: %s\n", library->books[i].id, library->books[i].title, library->books[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No book found with ID %d.\n", id);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}