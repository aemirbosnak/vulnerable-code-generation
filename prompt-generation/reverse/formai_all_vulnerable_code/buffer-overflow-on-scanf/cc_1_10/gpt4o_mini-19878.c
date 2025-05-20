//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

void addBook(Book **library, int *count);
void viewBooks(Book *library, int count);
void deleteBook(Book **library, int *count);
void freeLibrary(Book *library);

int main() {
    Book *library = NULL;
    int count = 0;
    int choice;

    do {
        printf("\nWelcome to the Book Library Management System!\n");
        printf("1. Add a Book\n");
        printf("2. View Books\n");
        printf("3. Delete a Book\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice input

        switch (choice) {
            case 1:
                addBook(&library, &count);
                break;
            case 2:
                viewBooks(library, count);
                break;
            case 3:
                deleteBook(&library, &count);
                break;
            case 4:
                printf("Exiting the program. Thank you for using the Book Library Management System!\n");
                freeLibrary(library);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void addBook(Book **library, int *count) {
    printf("Adding a new book...\n");
    *library = (Book *) realloc(*library, (*count + 1) * sizeof(Book));
    if (*library == NULL) {
        perror("Failed to allocate memory.");
        exit(EXIT_FAILURE);
    }

    printf("Enter book title: ");
    fgets((*library)[*count].title, MAX_TITLE_LENGTH, stdin);
    (*library)[*count].title[strcspn((*library)[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets((*library)[*count].author, MAX_AUTHOR_LENGTH, stdin);
    (*library)[*count].author[strcspn((*library)[*count].author, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Book added successfully! Total books: %d\n", *count);
}

void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library yet.\n");
        return;
    }

    printf("\nBooks in the Library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
    }
}

void deleteBook(Book **library, int *count) {
    if (*count == 0) {
        printf("No books to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the book to delete (1 to %d): ", *count);
    scanf("%d", &index);
    getchar(); // To consume the newline character

    if (index < 1 || index > *count) {
        printf("Invalid index! No book deleted.\n");
        return;
    }

    // Shift books down
    for (int i = index - 1; i < *count - 1; i++) {
        (*library)[i] = (*library)[i + 1];
    }

    *library = (Book *) realloc(*library, (*count - 1) * sizeof(Book));
    if (*library == NULL && *count - 1 > 0) {
        perror("Failed to reallocate memory.");
        exit(EXIT_FAILURE);
    }

    (*count)--;
    printf("Book deleted successfully! Total books remaining: %d\n", *count);
}

void freeLibrary(Book *library) {
    free(library);
    printf("Library memory freed successfully!\n");
}