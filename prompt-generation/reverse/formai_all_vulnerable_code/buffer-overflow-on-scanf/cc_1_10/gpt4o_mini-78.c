//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

// Function Declarations
void addBook(Library* library);
void displayBooks(Library library);
void searchBook(Library library);
void clearInputBuffer();

int main() {
    Library library;
    library.count = 0;

    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                searchBook(library);
                break;
            case 4:
                printf("Exiting the program. Happy reading!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(Library* library) {
    if (library->count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books!\n");
        return;
    }
    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    clearInputBuffer();

    library->books[library->count] = newBook;
    library->count++;
    printf("Book added successfully!\n");
}

void displayBooks(Library library) {
    if (library.count == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    for (int i = 0; i < library.count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", library.books[i].title, library.books[i].author, library.books[i].year);
    }
}

void searchBook(Library library) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < library.count; i++) {
        if (strcasecmp(library.books[i].title, searchTitle) == 0) {
            printf("Book found!\n");
            printf("Title: %s, Author: %s, Year: %d\n", library.books[i].title, library.books[i].author, library.books[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found in library.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}