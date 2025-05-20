//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = title;
    book->author = author;
    book->num_pages = num_pages;
    return book;
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *title = malloc(100);
    char *author = malloc(100);
    int num_pages;

    fscanf(fp, "%s %s %d", title, author, &num_pages);

    Book *book = create_book(title, author, num_pages);

    fclose(fp);

    return book;
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book);
}

int main() {
    // Read a book from a file
    Book *book = read_book("book.txt");

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}