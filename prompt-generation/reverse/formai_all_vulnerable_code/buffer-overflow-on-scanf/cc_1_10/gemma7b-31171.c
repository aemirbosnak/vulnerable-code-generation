//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store book information
typedef struct Book {
    char title[50];
    char author[50];
    int quantity;
} Book;

// Define a function to add a book to the library
void addBook(Book *books, int *numBooks) {
    // Allocate memory for a new book
    books = (Book *)realloc(books, (*numBooks + 1) * sizeof(Book));

    // Get book information from the user
    printf("Enter book title: ");
    scanf("%s", books[*numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[*numBooks].author);

    printf("Enter book quantity: ");
    scanf("%d", &books[*numBooks].quantity);

    // Increment the number of books
    *numBooks++;
}

// Define a function to search for a book
void searchBook(Book *books, int numBooks) {
    // Get the book title from the user
    char title[50];
    printf("Enter book title: ");
    scanf("%s", title);

    // Search for the book
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Print book information
            printf("Book title: %s\n", books[i].title);
            printf("Book author: %s\n", books[i].author);
            printf("Book quantity: %d\n", books[i].quantity);
            found = 1;
        }
    }

    // If the book was not found, print an error message
    if (!found) {
        printf("Book not found.\n");
    }
}

// Define a function to update book quantity
void updateBookQuantity(Book *books, int numBooks) {
    // Get the book title from the user
    char title[50];
    printf("Enter book title: ");
    scanf("%s", title);

    // Search for the book
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Get the new book quantity from the user
            int newQuantity;
            printf("Enter new book quantity: ");
            scanf("%d", &newQuantity);

            // Update the book quantity
            books[i].quantity = newQuantity;

            // Print the updated book information
            printf("Book title: %s\n", books[i].title);
            printf("Book author: %s\n", books[i].author);
            printf("Book quantity: %d\n", books[i].quantity);
            found = 1;
        }
    }

    // If the book was not found, print an error message
    if (!found) {
        printf("Book not found.\n");
    }
}

// Define a function to delete a book
void deleteBook(Book *books, int *numBooks) {
    // Get the book title from the user
    char title[50];
    printf("Enter book title: ");
    scanf("%s", title);

    // Search for the book
    int found = 0;
    for (int i = 0; i < *numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            // Delete the book
            books = (Book *)realloc(books, (*numBooks - 1) * sizeof(Book));

            // Decrement the number of books
            *numBooks--;

            // Print the updated book list
            printf("Books:\n");
            for (int j = 0; j < *numBooks; j++) {
                printf("%s by %s (Quantity: %d)\n", books[j].title, books[j].author, books[j].quantity);
            }

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
    Book *books = NULL;
    int numBooks = 0;

    // Menu loop
    int choice;
    printf("Welcome to the Music Library Management System!\n");
    printf("1. Add Book\n");
    printf("2. Search Book\n");
    printf("3. Update Book Quantity\n");
    printf("4. Delete Book\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch case to handle user choice
    switch (choice) {
        case 1:
            addBook(books, &numBooks);
            break;
        case 2:
            searchBook(books, numBooks);
            break;
        case 3:
            updateBookQuantity(books, numBooks);
            break;
        case 4:
            deleteBook(books, &numBooks);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}