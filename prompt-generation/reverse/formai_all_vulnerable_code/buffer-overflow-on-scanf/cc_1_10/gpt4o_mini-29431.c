//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    int id;
} Book;

typedef struct {
    Book* books;
    int count;
} Library;

Library* createLibrary() {
    Library* library = (Library*)malloc(sizeof(Library));
    if (library == NULL) {
        perror("Failed to allocate memory for library");
        exit(EXIT_FAILURE);
    }
    library->books = (Book*)malloc(sizeof(Book) * MAX_BOOKS);
    if (library->books == NULL) {
        perror("Failed to allocate memory for books");
        free(library);
        exit(EXIT_FAILURE);
    }
    library->count = 0;
    return library;
}

void addBook(Library* library) {
    if (library->count >= MAX_BOOKS) {
        fprintf(stderr, "Library is full! Cannot add more books.\n");
        return;
    }

    Book book;
    printf("Enter Book ID: ");
    int result = scanf("%d", &book.id);
    if (result != 1) {
        fprintf(stderr, "Invalid input. Please enter a number.\n");
        while(getchar() != '\n'); // clear invalid input
        return;
    }

    printf("Enter Book Title: ");
    getchar(); // clear the newline character from previous input
    fgets(book.title, TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline character

    library->books[library->count++] = book;
    printf("Book added successfully!\n");
}

void viewBooks(const Library* library) {
    if (library->count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Books in Library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("ID: %d, Title: %s\n", library->books[i].id, library->books[i].title);
    }
}

void freeLibrary(Library* library) {
    free(library->books);
    free(library);
}

int main() {
    Library* library = createLibrary();
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear invalid input
            choice = -1; // Reset choice to an invalid option
        }

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                viewBooks(library);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                if (choice != -1) {
                    fprintf(stderr, "Invalid choice. Please try again.\n");
                }
                break;
        }
    } while (choice != 3);

    freeLibrary(library);
    return 0;
}