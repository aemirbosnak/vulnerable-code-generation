//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
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

void displayBooks() {
    printf("Here is a list of books:\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].quantity > 0) {
            printf("%s by %s (Quantity: %d)\n", books[i].title, books[i].author, books[i].quantity);
        }
    }
}

void addBook() {
    Book newBook;
    printf("Enter the title of the book: ");
    scanf("%s", newBook.title);

    printf("Enter the author's name: ");
    scanf("%s", newBook.author);

    printf("Enter the quantity of the book: ");
    scanf("%d", &newBook.quantity);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].quantity == 0) {
            books[i] = newBook;
            break;
        }
    }

    printf("Book added successfully!\n");
}

void searchBooks() {
    char query[50];
    printf("Enter the title or author of the book you are searching for: ");
    scanf("%s", query);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i].title, query) == 0 || strcmp(books[i].author, query) == 0) {
            printf("%s by %s (Quantity: %d)\n", books[i].title, books[i].author, books[i].quantity);
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the C Music Library Management System!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Display Books\n");
        printf("2. Add Book\n");
        printf("3. Search Books\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks();
                break;
            case 2:
                addBook();
                break;
            case 3:
                searchBooks();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}