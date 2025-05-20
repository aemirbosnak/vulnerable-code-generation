//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_ISBN_LENGTH 20
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
} Book;

void displayMenu() {
    printf("\nLibrary Database Management System\n");
    printf("1. Add Book\n");
    printf("2. Delete Book\n");
    printf("3. Display Books\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addBook(Book *books, int *numBooks) {
    if (*numBooks >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    getchar(); // Clear buffer
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n");

    printf("Enter ISBN: ");
    fgets(newBook.isbn, MAX_ISBN_LENGTH, stdin);
    strtok(newBook.isbn, "\n");

    books[*numBooks] = newBook;
    (*numBooks)++;
    printf("Book added successfully!\n");
}

void deleteBook(Book *books, int *numBooks) {
    char isbn[MAX_ISBN_LENGTH];
    printf("Enter the ISBN of the book to delete: ");
    getchar(); // Clear buffer
    fgets(isbn, MAX_ISBN_LENGTH, stdin);
    strtok(isbn, "\n");

    for (int i = 0; i < *numBooks; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            for (int j = i; j < *numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            (*numBooks)--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void displayBooks(Book *books, int numBooks) {
    printf("\n--- List of Books ---\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %s\n", books[i].isbn);
        printf("-------------------\n");
    }
    if (numBooks == 0) {
        printf("No books available!\n");
    }
}

int main() {
    Book *books = malloc(sizeof(Book) * MAX_BOOKS);
    if (!books) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    int numBooks = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2:
                deleteBook(books, &numBooks);
                break;
            case 3:
                displayBooks(books, numBooks);
                break;
            case 4:
                free(books);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}