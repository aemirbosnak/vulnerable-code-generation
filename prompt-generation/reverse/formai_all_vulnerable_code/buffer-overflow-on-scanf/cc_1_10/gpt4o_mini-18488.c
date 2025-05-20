//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LENGTH 100
#define INITIAL_CAPACITY 2

// Struct to represent a Book
typedef struct {
    char title[TITLE_LENGTH];
} Book;

// Struct to represent the Library
typedef struct {
    Book* books;
    int size;
    int capacity;
} Library;

// Function to create a new library
Library* create_library() {
    Library* library = malloc(sizeof(Library));
    library->size = 0;
    library->capacity = INITIAL_CAPACITY;
    library->books = malloc(library->capacity * sizeof(Book));
    return library;
}

// Function to add a book to the library
void add_book(Library* library, const char* title) {
    if (library->size >= library->capacity) {
        library->capacity *= 2; // Double the capacity
        library->books = realloc(library->books, library->capacity * sizeof(Book));
        if (!library->books) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(library->books[library->size].title, title, TITLE_LENGTH - 1);
    library->books[library->size].title[TITLE_LENGTH - 1] = '\0'; // Ensure null-termination
    library->size++;
}

// Function to display all books in the library
void display_books(Library* library) {
    printf("Library contains %d book(s):\n", library->size);
    for (int i = 0; i < library->size; i++) {
        printf("- %s\n", library->books[i].title);
    }
}

// Function to free the library and its books
void free_library(Library* library) {
    if (library) {
        free(library->books);
        free(library);
    }
}

// Main function to demonstrate library system
int main() {
    Library* myLibrary = create_library();
    int choice;
    char title[TITLE_LENGTH];

    while (1) {
        printf("\nLibrary Menu:\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clean newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter the title of the book: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                add_book(myLibrary, title);
                break;
            case 2:
                display_books(myLibrary);
                break;
            case 3:
                free_library(myLibrary);
                printf("Exiting the library. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}