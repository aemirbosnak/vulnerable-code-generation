//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char title[50];
    char author[50];
    int pages;
    char *text;
} Book;

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the title, author, and pages from the file
    fscanf(fp, "%s %s %d", book->title, book->author, &book->pages);

    // Allocate memory for the text
    book->text = malloc(book->pages * sizeof(char));
    if (book->text == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(book);
        return NULL;
    }

    // Read the text from the file
    fread(book->text, sizeof(char), book->pages, fp);

    // Close the file
    fclose(fp);

    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->text);
    free(book);
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Text:\n%s\n", book->text);
}

int main() {
    // Read a book from a file
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