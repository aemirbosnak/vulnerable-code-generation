//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define INITIAL_BOOK_COUNT 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book *books;
    int count;
    int capacity;
} Library;

Library* createLibrary(int initialCapacity) {
    Library *library = (Library *)malloc(sizeof(Library));
    if (!library) {
        fprintf(stderr, "Memory allocation for library failed!\n");
        exit(EXIT_FAILURE);
    }
    library->books = (Book *)malloc(initialCapacity * sizeof(Book));
    if (!library->books) {
        free(library);
        fprintf(stderr, "Memory allocation for books failed!\n");
        exit(EXIT_FAILURE);
    }
    library->capacity = initialCapacity;
    library->count = 0;
    return library;
}

void freeLibrary(Library *library) {
    free(library->books);
    free(library);
}

void resizeLibrary(Library *library) {
    library->capacity *= 2;
    library->books = (Book *)realloc(library->books, library->capacity * sizeof(Book));
    if (!library->books) {
        fprintf(stderr, "Memory reallocation for books failed!\n");
        freeLibrary(library);
        exit(EXIT_FAILURE);
    }
}

void addBook(Library *library, const char *title, const char *author, int year) {
    if (library->count == library->capacity) {
        resizeLibrary(library);
    }
    strncpy(library->books[library->count].title, title, MAX_TITLE_LENGTH);
    strncpy(library->books[library->count].author, author, MAX_AUTHOR_LENGTH);
    library->books[library->count].year = year;
    library->count++;
}

void removeBook(Library *library, const char *title) {
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->books[j] = library->books[j + 1];
            }
            library->count--;
            printf("Book '%s' removed successfully.\n", title);
            return;
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

void viewBooks(Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Books in the library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n",
               library->books[i].title,
               library->books[i].author,
               library->books[i].year);
    }
}

void menu() {
    printf("Mini Library System:\n");
    printf("1. Add Book\n");
    printf("2. Remove Book\n");
    printf("3. View Books\n");
    printf("4. Exit\n");
}

int main() {
    Library *library = createLibrary(INITIAL_BOOK_COUNT);
    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf(" %[^\n]s", title);
                printf("Enter author name: ");
                scanf(" %[^\n]s", author);
                printf("Enter year of publication: ");
                scanf("%d", &year);
                addBook(library, title, author, year);
                printf("Book added successfully.\n");
                break;
            case 2:
                printf("Enter book title to remove: ");
                scanf(" %[^\n]s", title);
                removeBook(library, title);
                break;
            case 3:
                viewBooks(library);
                break;
            case 4:
                freeLibrary(library);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}