//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int quantity;
    int id;
};

void displayBooks() {
    struct Book books[MAX_BOOKS];
    int i = 0;

    for (i = 0; i < MAX_BOOKS && books[i].title[0] != '\0'; i++) {
        printf("%d. %s by %s (Quantity: %d)\n", books[i].id, books[i].title, books[i].author, books[i].quantity);
    }
}

void addBook() {
    struct Book books[MAX_BOOKS];
    int i = 0;

    for (i = 0; i < MAX_BOOKS && books[i].title[0] != '\0'; i++) {}

    books[i].id = i + 1;
    printf("Enter book title: ");
    scanf("%s", books[i].title);
    printf("Enter author's name: ");
    scanf("%s", books[i].author);
    printf("Enter quantity: ");
    scanf("%d", &books[i].quantity);

    displayBooks();
}

void updateBookQuantity() {
    struct Book books[MAX_BOOKS];
    int bookId;
    int newQuantity;

    printf("Enter book ID: ");
    scanf("%d", &bookId);
    printf("Enter new quantity: ");
    scanf("%d", &newQuantity);

    for (int i = 0; i < MAX_BOOKS && books[i].title[0] != '\0'; i++) {
        if (books[i].id == bookId) {
            books[i].quantity = newQuantity;
            break;
        }
    }

    displayBooks();
}

void deleteBook() {
    struct Book books[MAX_BOOKS];
    int bookId;

    printf("Enter book ID: ");
    scanf("%d", &bookId);

    for (int i = 0; i < MAX_BOOKS && books[i].title[0] != '\0'; i++) {
        if (books[i].id == bookId) {
            books[i].title[0] = '\0';
            break;
        }
    }

    displayBooks();
}

int main() {
    int choice;

    printf("Welcome to the Music Library Management System!\n");
    printf("Please select an option:\n");
    printf("1. Display Books\n");
    printf("2. Add Book\n");
    printf("3. Update Book Quantity\n");
    printf("4. Delete Book\n");

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
            deleteBook();
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}