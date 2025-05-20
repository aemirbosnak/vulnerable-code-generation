//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

Library library;

void initLibrary() {
    library.count = 0;
}

void addBook() {
    if (library.count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book newBook;
    newBook.id = library.count + 1;

    printf("Enter title of the book: ");
    scanf(" %[^\n]s", newBook.title);
    printf("Enter author of the book: ");
    scanf(" %[^\n]s", newBook.author);

    library.books[library.count] = newBook;
    library.count++;

    printf("Book added successfully!\n");
}

void viewBooks() {
    if (library.count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("=== List of Books in the Library ===\n");
    for (int i = 0; i < library.count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", 
                library.books[i].id, 
                library.books[i].title, 
                library.books[i].author);
    }
    printf("=====================================\n");
}

void deleteBook() {
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > library.count) {
        printf("Invalid book ID.\n");
        return;
    }

    for (int i = id - 1; i < library.count - 1; i++) {
        library.books[i] = library.books[i + 1];
    }
    library.count--;

    printf("Book deleted successfully!\n");
}

void displayMenu() {
    printf("=== Library Database Menu ===\n");
    printf("1. Add a Book\n");
    printf("2. View Books\n");
    printf("3. Delete a Book\n");
    printf("4. Exit\n");
    printf("=============================\n");
}

int main() {
    int choice;
    initLibrary();

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}