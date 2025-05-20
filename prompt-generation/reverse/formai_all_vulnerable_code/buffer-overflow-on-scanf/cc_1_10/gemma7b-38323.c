//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
} Book;

Book books[MAX_BOOKS];

void displayBooks() {
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].quantity > 0) {
            printf("%s by %s (%s) - %d copies\n", books[i].title, books[i].author, books[i].genre, books[i].quantity);
        }
    }
}

void addBook() {
    Book newBook;

    printf("Enter book title: ");
    scanf("%s", newBook.title);

    printf("Enter author's name: ");
    scanf("%s", newBook.author);

    printf("Enter genre: ");
    scanf("%s", newBook.genre);

    printf("Enter number of copies: ");
    scanf("%d", &newBook.quantity);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].quantity == 0) {
            books[i] = newBook;
            break;
        }
    }

    printf("Book added successfully!\n");
}

void updateBookQuantity() {
    char title[50];

    printf("Enter book title: ");
    scanf("%s", title);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &books[i].quantity);
            break;
        }
    }

    printf("Book quantity updated successfully!\n");
}

void searchBooks() {
    char query[50];

    printf("Enter search query: ");
    scanf("%s", query);

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].author, query) || strstr(books[i].genre, query)) {
            printf("%s by %s (%s) - %d copies\n", books[i].title, books[i].author, books[i].genre, books[i].quantity);
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Display books\n");
        printf("2. Add book\n");
        printf("3. Update book quantity\n");
        printf("4. Search books\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks();
                break;
            case 2:
                addBook();
                break;
            case 3:
                updateBookQuantity();
                break;
            case 4:
                searchBooks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}