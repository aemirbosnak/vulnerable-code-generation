//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LIBRARY_SIZE 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int is_checked_out;
} Book;

typedef struct {
    Book *books[MAX_LIBRARY_SIZE];
    int size;
} Library;

// Function prototypes
Library* create_library();
void add_book(Library *library, int id, const char *name);
void checkout_book(Library *library, int id);
void return_book(Library *library, int id);
void list_books(Library *library);
void free_library(Library *library);

// Entry Point
int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];
    Library *library = create_library();

    while (1) {
        printf("Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Checkout Book\n");
        printf("3. Return Book\n");
        printf("4. List Books\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Name: ");
                scanf(" %[^\n]", name);
                add_book(library, id, name);
                break;
            case 2:
                printf("Enter Book ID to checkout: ");
                scanf("%d", &id);
                checkout_book(library, id);
                break;
            case 3:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                return_book(library, id);
                break;
            case 4:
                list_books(library);
                break;
            case 5:
                free_library(library);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new library
Library* create_library() {
    Library *library = (Library *)malloc(sizeof(Library));
    if (!library) {
        perror("Failed to create library");
        exit(EXIT_FAILURE);
    }
    library->size = 0;
    memset(library->books, 0, sizeof(library->books));
    return library;
}

// Function to add a book to the library
void add_book(Library *library, int id, const char *name) {
    if (library->size >= MAX_LIBRARY_SIZE) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book *new_book = (Book *)malloc(sizeof(Book));
    if (!new_book) {
        perror("Failed to add book");
        return;
    }

    new_book->id = id;
    strncpy(new_book->name, name, MAX_NAME_LENGTH);
    new_book->is_checked_out = 0;

    library->books[library->size++] = new_book;
    printf("Book added: %s (ID: %d)\n", new_book->name, new_book->id);
}

// Function to checkout a book
void checkout_book(Library *library, int id) {
    for (int i = 0; i < library->size; i++) {
        if (library->books[i]->id == id) {
            if (library->books[i]->is_checked_out) {
                printf("Book '%s' is already checked out.\n", library->books[i]->name);
            } else {
                library->books[i]->is_checked_out = 1;
                printf("Book '%s' has been checked out.\n", library->books[i]->name);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

// Function to return a book
void return_book(Library *library, int id) {
    for (int i = 0; i < library->size; i++) {
        if (library->books[i]->id == id) {
            if (!library->books[i]->is_checked_out) {
                printf("Book '%s' was not checked out.\n", library->books[i]->name);
            } else {
                library->books[i]->is_checked_out = 0;
                printf("Book '%s' has been returned.\n", library->books[i]->name);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

// Function to list all books in the library
void list_books(Library *library) {
    printf("Library Books:\n");
    for (int i = 0; i < library->size; i++) {
        Book *book = library->books[i];
        printf("ID: %d, Name: %s, Status: %s\n", book->id, book->name, book->is_checked_out ? "Checked Out" : "Available");
    }
}

// Function to free the library memory
void free_library(Library *library) {
    for (int i = 0; i < library->size; i++) {
        free(library->books[i]);
    }
    free(library);
}