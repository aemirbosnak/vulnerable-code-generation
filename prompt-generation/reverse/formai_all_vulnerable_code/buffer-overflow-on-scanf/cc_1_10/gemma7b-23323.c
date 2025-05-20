//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
} Book;

Book books[MAX_BOOKS];

void manageBooks() {
    int i = 0;
    for (i = 0; i < MAX_BOOKS; i++) {
        printf("%s by %s, quantity: %d\n", books[i].title, books[i].author, books[i].quantity);
    }
}

void addBook() {
    Book newBook;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter author's name: ");
    scanf("%s", newBook.author);
    printf("Enter quantity: ");
    scanf("%d", &newBook.quantity);

    int i = 0;
    for (i = 0; i < MAX_BOOKS; i++) {
        if (books[i].quantity == 0) {
            books[i] = newBook;
            break;
        }
    }

    if (i == MAX_BOOKS) {
        printf("Error: Library is full!\n");
    }
}

void updateBookQuantity() {
    Book bookToUpdate;
    printf("Enter book title: ");
    scanf("%s", bookToUpdate.title);
    printf("Enter new quantity: ");
    scanf("%d", &bookToUpdate.quantity);

    int i = 0;
    for (i = 0; i < MAX_BOOKS; i++) {
        if (strcmp(books[i].title, bookToUpdate.title) == 0) {
            books[i].quantity = bookToUpdate.quantity;
            break;
        }
    }

    if (i == MAX_BOOKS) {
        printf("Error: Book not found!\n");
    }
}

void searchBooks() {
    char searchTerm[50];
    printf("Enter search term: ");
    scanf("%s", searchTerm);

    int i = 0;
    for (i = 0; i < MAX_BOOKS; i++) {
        if (strstr(books[i].title, searchTerm) || strstr(books[i].author, searchTerm)) {
            printf("%s by %s, quantity: %d\n", books[i].title, books[i].author, books[i].quantity);
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Music Library Management System!\n");
    printf("Please select an option:\n");
    printf("1. Manage Books\n");
    printf("2. Add Book\n");
    printf("3. Update Book Quantity\n");
    printf("4. Search Books\n");

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
            searchBooks();
            break;
        default:
            printf("Invalid input!\n");
    }

    return 0;
}