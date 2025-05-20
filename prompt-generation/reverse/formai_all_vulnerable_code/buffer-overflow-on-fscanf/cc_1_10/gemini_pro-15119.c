//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a book
typedef struct book {
    char title[50];
    char author[50];
    int num_pages;
    char *text;
} book_t;

// Function to read a book from a file
book_t *read_book(char *filename) {
    FILE *fp;
    book_t *book;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the book
    book = malloc(sizeof(book_t));
    if (book == NULL) {
        printf("Error allocating memory for book\n");
        fclose(fp);
        return NULL;
    }

    // Read the title, author, and number of pages from the file
    fscanf(fp, "%s %s %d", book->title, book->author, &book->num_pages);

    // Allocate memory for the text of the book
    book->text = malloc(book->num_pages * sizeof(char));
    if (book->text == NULL) {
        printf("Error allocating memory for book text\n");
        fclose(fp);
        free(book);
        return NULL;
    }

    // Read the text of the book from the file
    fread(book->text, sizeof(char), book->num_pages, fp);

    // Close the file
    fclose(fp);

    // Return the book
    return book;
}

// Function to print a book to the console
void print_book(book_t *book) {
    // Print the title, author, and number of pages
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);

    // Print the text of the book
    printf("\n%s\n", book->text);
}

// Function to free the memory allocated for a book
void free_book(book_t *book) {
    // Free the memory allocated for the text of the book
    free(book->text);

    // Free the memory allocated for the book
    free(book);
}

// Main function
int main(int argc, char *argv[]) {
    book_t *book;

    // Check if the user provided a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book from the file
    book = read_book(argv[1]);
    if (book == NULL) {
        return 1;
    }

    // Print the book to the console
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}