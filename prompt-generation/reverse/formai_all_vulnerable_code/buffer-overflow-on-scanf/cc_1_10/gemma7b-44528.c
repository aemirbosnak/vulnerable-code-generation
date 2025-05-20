//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store book information
typedef struct book {
    char title[50];
    char author[50];
    int quantity;
} book;

// Function to insert a book into the library
void insertBook(book *books, int *numBooks) {
    // Allocate memory for a new book
    books = (book *)realloc(books, (*numBooks + 1) * sizeof(book));

    // Get the book information from the user
    printf("Enter book title: ");
    scanf("%s", books[*numBooks].title);

    printf("Enter author's name: ");
    scanf("%s", books[*numBooks].author);

    printf("Enter quantity: ");
    scanf("%d", &books[*numBooks].quantity);

    // Increment the number of books
    (*numBooks)++;
}

// Function to search for a book in the library
void searchBook(book *books, int numBooks) {
    // Get the book title from the user
    char title[50];
    printf("Enter book title: ");
    scanf("%s", title);

    // Search for the book
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Print book information
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Quantity: %d\n", books[i].quantity);
            return;
        }
    }

    // Book not found
    printf("Book not found.\n");
}

int main() {
    // Define an array of books
    book *books = NULL;

    // Initialize the number of books to 0
    int numBooks = 0;

    // Insert a book into the library
    insertBook(books, &numBooks);

    // Search for a book in the library
    searchBook(books, numBooks);

    return 0;
}