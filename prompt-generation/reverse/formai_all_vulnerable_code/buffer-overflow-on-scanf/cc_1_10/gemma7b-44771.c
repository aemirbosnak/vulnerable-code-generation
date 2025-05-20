//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
} Book;

Book books[MAX_BOOKS];

void manageBooks() {
    int i;
    for (i = 0; i < MAX_BOOKS; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Quantity: %d\n", books[i].quantity);
        printf("\n");
    }
}

void addBook() {
    Book newBook;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter book author: ");
    scanf("%s", newBook.author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook.quantity);

    int i;
    for (i = 0; i < MAX_BOOKS; i++) {
        if (books[i].quantity == 0) {
            books[i] = newBook;
            break;
        }
    }

    if (i == MAX_BOOKS) {
        printf("Error: No space for new book.\n");
    } else {
        printf("Book added successfully.\n");
    }
}

void updateBookQuantity() {
    Book bookToUpdate;
    printf("Enter book title: ");
    scanf("%s", bookToUpdate.title);
    printf("Enter book quantity: ");
    scanf("%d", &bookToUpdate.quantity);

    int i;
    for (i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i].title, bookToUpdate.title) == 0) {
            books[i].quantity = bookToUpdate.quantity;
            break;
        }
    }

    if (i == MAX_BOOKS) {
        printf("Error: Book not found.\n");
    } else {
        printf("Book quantity updated successfully.\n");
    }
}

void deleteBook() {
    Book bookToDelete;
    printf("Enter book title: ");
    scanf("%s", bookToDelete.title);

    int i;
    for (i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i].title, bookToDelete.title) == 0) {
            books[i].quantity = 0;
            break;
        }
    }

    if (i == MAX_BOOKS) {
        printf("Error: Book not found.\n");
    } else {
        printf("Book deleted successfully.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Music Library Management System!\n");
    printf("1. Manage Books\n");
    printf("2. Add Book\n");
    printf("3. Update Book Quantity\n");
    printf("4. Delete Book\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            manageBooks();
            break;
        case 2:
            addBook();
            break;
        case 3:
            updateBookQuantity();
            break;
        case 4:
            deleteBook();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}