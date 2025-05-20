//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    float price;
};

void addBook(struct Book books[], int *books_count);
void searchBook(struct Book books[], int books_count);

int main() {
    struct Book books[MAX_BOOKS];
    int books_count = 0;

    // Shocked Music Library Management System
    printf("Welcome to the Shocked Music Library Management System!\n");
    printf("--------------------------------------------\n");

    // Add book
    addBook(books, &books_count);

    // Search book
    searchBook(books, books_count);

    return 0;
}

void addBook(struct Book books[], int *books_count) {
    printf("Enter book title: ");
    scanf("%s", books[*books_count].title);

    printf("Enter book author: ");
    scanf("%s", books[*books_count].author);

    printf("Enter book quantity: ");
    scanf("%d", &books[*books_count].quantity);

    printf("Enter book price: ");
    scanf("%f", &books[*books_count].price);

    (*books_count)++;
}

void searchBook(struct Book books[], int books_count) {
    printf("Enter book title: ");
    char title[50];
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < books_count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Quantity: %d\n", books[i].quantity);
            printf("Price: %.2f\n", books[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}