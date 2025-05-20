//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the book's data
typedef struct Book {
    char title[50];
    char author[50];
    int num_pages;
    char *pages;
} Book;

// Function to read a book from a file
Book *read_book(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        printf("Error allocating memory for book\n");
        fclose(fp);
        return NULL;
    }

    // Read the book's data from the file
    fscanf(fp, "%s %s %d", book->title, book->author, &book->num_pages);

    // Allocate memory for the book's pages
    book->pages = malloc(book->num_pages * sizeof(char));
    if (book->pages == NULL) {
        printf("Error allocating memory for book's pages\n");
        fclose(fp);
        free(book);
        return NULL;
    }

    // Read the book's pages from the file
    for (int i = 0; i < book->num_pages; i++) {
        fscanf(fp, "%c", &book->pages[i]);
    }

    // Close the file
    fclose(fp);

    return book;
}

// Function to print a book
void print_book(Book *book) {
    // Print the book's data
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);

    // Print the book's pages
    for (int i = 0; i < book->num_pages; i++) {
        printf("%c", book->pages[i]);
    }
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    // Free the memory allocated for the book's pages
    free(book->pages);

    // Free the memory allocated for the book
    free(book);
}

int main() {
    // Read the book from a file
    Book *book = read_book("book.txt");
    if (book == NULL) {
        return 1;
    }

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}