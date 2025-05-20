//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

typedef struct {
    Book *books;
    int size;
    int capacity;
} Library;

void initializeLibrary(Library *library) {
    library->size = 0;
    library->capacity = 2; // Start with a small capacity
    library->books = malloc(library->capacity * sizeof(Book));
    if (!library->books) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void resizeLibrary(Library *library) {
    library->capacity *= 2;
    library->books = realloc(library->books, library->capacity * sizeof(Book));
    if (!library->books) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void addBook(Library *library) {
    if (library->size >= library->capacity) {
        resizeLibrary(library);
    }
    
    printf("Enter book title: ");
    getchar(); // Consume newline character
    fgets(library->books[library->size].title, sizeof(library->books[library->size].title), stdin);
    library->books[library->size].title[strcspn(library->books[library->size].title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(library->books[library->size].author, sizeof(library->books[library->size].author), stdin);
    library->books[library->size].author[strcspn(library->books[library->size].author, "\n")] = 0; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &library->books[library->size].year);

    library->size++;
    printf("Book added successfully.\n");
}

void displayBooks(Library *library) {
    if (library->size == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("Books in Library:\n");
    for (int i = 0; i < library->size; i++) {
        printf("%d. Title: %s, Author: %s, Year: %d\n", 
               i + 1, 
               library->books[i].title, 
               library->books[i].author, 
               library->books[i].year);
    }
}

void searchBook(Library *library) {
    char title[100];
    printf("Enter book title to search: ");
    getchar(); // Consume newline character
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < library->size; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            printf("Found: Title: %s, Author: %s, Year: %d\n", 
                   library->books[i].title, 
                   library->books[i].author, 
                   library->books[i].year);
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook(Library *library) {
    char title[100];
    printf("Enter book title to delete: ");
    getchar(); // Consume newline character
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    for (int i = 0; i < library->size; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            for (int j = i; j < library->size - 1; j++) {
                library->books[j] = library->books[j + 1]; // Shift books left
            }
            library->size--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void cleanupLibrary(Library *library) {
    free(library->books);
}

int main() {
    Library library;
    initializeLibrary(&library);

    int choice;
    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search for a Book\n");
        printf("4. Delete a Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                deleteBook(&library);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    cleanupLibrary(&library);
    return 0;
}