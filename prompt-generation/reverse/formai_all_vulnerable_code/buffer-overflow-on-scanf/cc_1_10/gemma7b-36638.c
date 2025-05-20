//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR_LEN 50

typedef struct Book {
    char title[MAX_BOOKS];
    char author[MAX_AUTHOR_LEN];
    int quantity;
} Book;

Book books[MAX_BOOKS];

void addBook() {
    Book newBook;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter book author: ");
    scanf("%s", newBook.author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook.quantity);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].title == NULL) {
            books[i] = newBook;
            return;
        }
    }

    printf("Error: Library is full.\n");
}

void searchBook() {
    char searchTitle[MAX_BOOKS];
    printf("Enter book title: ");
    scanf("%s", searchTitle);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book title: %s\n", books[i].title);
            printf("Book author: %s\n", books[i].author);
            printf("Book quantity: %d\n", books[i].quantity);
            return;
        }
    }

    printf("Book not found.\n");
}

void main() {
    int choice;

    printf("Welcome to the Music Library Management System.\n");
    printf("1. Add Book\n");
    printf("2. Search Book\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        default:
            printf("Invalid choice.\n");
    }
}