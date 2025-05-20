//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
} book;

// Define the function to add a book to the library
void addBook(book *books, int *numBooks) {
    // Allocate memory for a new book
    books = (book *)realloc(books, (*numBooks + 1) * sizeof(book));

    // Get the book's title, author, genre, and quantity
    printf("Enter the book's title: ");
    scanf("%s", books[*numBooks].title);

    printf("Enter the book's author: ");
    scanf("%s", books[*numBooks].author);

    printf("Enter the book's genre: ");
    scanf("%s", books[*numBooks].genre);

    printf("Enter the book's quantity: ");
    scanf("%d", &books[*numBooks].quantity);

    // Increment the number of books
    *numBooks++;
}

// Define the function to search for a book
void searchBook(book *books, int numBooks) {
    // Get the book's title
    printf("Enter the book's title: ");
    char title[50];
    scanf("%s", title);

    // Search for the book
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Print the book's information
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Genre: %s\n", books[i].genre);
            printf("Quantity: %d\n", books[i].quantity);
            found = 1;
        }
    }

    // If the book was not found, print an error message
    if (!found) {
        printf("Book not found.\n");
    }
}

// Define the function to update a book's quantity
void updateBookQuantity(book *books, int numBooks) {
    // Get the book's title
    printf("Enter the book's title: ");
    char title[50];
    scanf("%s", title);

    // Search for the book
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Get the book's new quantity
            int newQuantity;
            printf("Enter the book's new quantity: ");
            scanf("%d", &newQuantity);

            // Update the book's quantity
            books[i].quantity = newQuantity;

            // Print the book's updated information
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Genre: %s\n", books[i].genre);
            printf("Quantity: %d\n", books[i].quantity);
            found = 1;
        }
    }

    // If the book was not found, print an error message
    if (!found) {
        printf("Book not found.\n");
    }
}

// Define the function to delete a book from the library
void deleteBook(book *books, int *numBooks) {
    // Get the book's title
    printf("Enter the book's title: ");
    char title[50];
    scanf("%s", title);

    // Search for the book
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Delete the book
            books = (book *)realloc(books, (*numBooks - 1) * sizeof(book));
            *numBooks--;

            // Print a confirmation message
            printf("Book deleted.\n");
            found = 1;
        }
    }

    // If the book was not found, print an error message
    if (!found) {
        printf("Book not found.\n");
    }
}

// Main function
int main() {
    // Create an array of books
    book *books = NULL;
    int numBooks = 0;

    // Add some books to the library
    addBook(books, &numBooks);
    addBook(books, &numBooks);
    addBook(books, &numBooks);

    // Search for a book
    searchBook(books, numBooks);

    // Update a book's quantity
    updateBookQuantity(books, numBooks);

    // Delete a book
    deleteBook(books, &numBooks);

    return 0;
}