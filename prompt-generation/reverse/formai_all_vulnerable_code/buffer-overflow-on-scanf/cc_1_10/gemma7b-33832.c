//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
    double price;
} Book;

Book books[MAX_BOOKS];

int main() {
    int i, book_count = 0;
    char search_title[50];

    // Create a book
    Book new_book;
    new_book.quantity = 1;
    strcpy(new_book.title, "The Lord of the Flies");
    strcpy(new_book.author, "William Golding");
    new_book.price = 10.0;

    books[book_count++] = new_book;

    // Add more books
    new_book.quantity = 2;
    strcpy(new_book.title, "The Great Gatsby");
    strcpy(new_book.author, "F. Scott Fitzgerald");
    new_book.price = 12.0;
    books[book_count++] = new_book;

    // Print all books
    for (i = 0; i < book_count; i++) {
        printf("%s by %s, quantity: %d, price: %.2lf\n", books[i].title, books[i].author, books[i].quantity, books[i].price);
    }

    // Search for a book
    printf("Enter book title: ");
    scanf("%s", search_title);

    for (i = 0; i < book_count; i++) {
        if (strcmp(search_title, books[i].title) == 0) {
            printf("Book found: %s by %s, quantity: %d, price: %.2lf\n", books[i].title, books[i].author, books[i].quantity, books[i].price);
        }
    }

    return 0;
}