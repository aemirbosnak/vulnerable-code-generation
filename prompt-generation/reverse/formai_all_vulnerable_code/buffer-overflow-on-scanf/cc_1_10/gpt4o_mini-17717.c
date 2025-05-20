//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a book
typedef struct Book {
    char title[100];
    char author[100];
    int pages;
} Book;

// Function to read a book's information
void readBookInfo(Book *book) {
    printf("Enter the title of the book: ");
    fgets(book->title, sizeof(book->title), stdin);
    book->title[strcspn(book->title, "\n")] = 0; // Remove newline

    printf("Enter the author of the book: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = 0; // Remove newline

    printf("Enter the number of pages: ");
    scanf("%d", &book->pages);
    getchar(); // Clear the newline from the input buffer
}

// Function to display a book's information
void displayBookInfo(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n\n", book.pages);
}

// Recursive function to manage multiple books
void manageBooks(Book *books, int count) {
    if (count == 0) {
        return;
    }
    
    printf("Managing book %d:\n", count);
    readBookInfo(&books[count - 1]);
    manageBooks(books, count - 1);
}

// Function to print out all books information
void printAllBooks(Book *books, int count) {
    printf("\nBooks List:\n");
    for (int i = 0; i < count; i++) {
        displayBookInfo(books[i]);
    }
}

int main() {
    int bookCount;
    
    printf("How many books would you like to enter? ");
    scanf("%d", &bookCount);
    getchar(); // Clear newline from the input buffer

    if (bookCount <= 0) {
        printf("Invalid number of books. Exiting.\n");
        return 1;
    }

    // Allocate memory for the books
    Book *books = (Book *)malloc(bookCount * sizeof(Book));
    if (books == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Use recursive function to read book information
    manageBooks(books, bookCount);

    // Displaying all book information
    printAllBooks(books, bookCount);

    // Free allocated memory
    free(books);

    return 0;
}