//GEMINI-pro DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a book's details
typedef struct book {
    char title[50];
    char author[50];
    int pages;
    float price;
} Book;

// Function to read books from a file
Book *readBooks(char *filename, int *numBooks) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the number of books in the file
    fscanf(fp, "%d", numBooks);

    // Allocate memory for the books
    Book *books = (Book *)malloc(*numBooks * sizeof(Book));
    if (books == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the books from the file
    for (int i = 0; i < *numBooks; i++) {
        fscanf(fp, "%s %s %d %f", books[i].title, books[i].author, &books[i].pages, &books[i].price);
    }

    // Close the file
    fclose(fp);

    // Return the books
    return books;
}

// Function to write books to a file
void writeBooks(char *filename, Book *books, int numBooks) {
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the number of books to the file
    fprintf(fp, "%d\n", numBooks);

    // Write the books to the file
    for (int i = 0; i < numBooks; i++) {
        fprintf(fp, "%s %s %d %f\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }

    // Close the file
    fclose(fp);
}

// Function to print a book
void printBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Price: %f\n", book.price);
}

// Function to compare two books
int compareBooks(Book book1, Book book2) {
    return strcmp(book1.title, book2.title);
}

// Function to sort books by title
void sortBooks(Book *books, int numBooks) {
    qsort(books, numBooks, sizeof(Book), compareBooks);
}

// Function to find a book by title
Book *findBook(Book *books, int numBooks, char *title) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }

    return NULL;
}

// Main function
int main() {
    // Read books from a file
    int numBooks;
    Book *books = readBooks("books.txt", &numBooks);
    if (books == NULL) {
        return 1;
    }

    // Print the books
    for (int i = 0; i < numBooks; i++) {
        printBook(books[i]);
        printf("\n");
    }

    // Sort the books by title
    sortBooks(books, numBooks);

    // Find a book by title
    char *title = "The Catcher in the Rye";
    Book *book = findBook(books, numBooks, title);
    if (book == NULL) {
        printf("Book not found\n");
    } else {
        printBook(*book);
        printf("\n");
    }

    // Write the books to a file
    writeBooks("books.txt", books, numBooks);

    // Free the memory allocated for the books
    free(books);

    return 0;
}