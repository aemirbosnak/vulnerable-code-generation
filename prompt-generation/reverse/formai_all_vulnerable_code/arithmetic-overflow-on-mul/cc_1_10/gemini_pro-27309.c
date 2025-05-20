//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct book {
    char title[50];
    char author[50];
    int pages;
    char *text;
} Book;

// Function to read a book from a file
Book *read_book(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the book
    Book *book = malloc(sizeof(Book));
    if (book == NULL) {
        printf("Error allocating memory for book\n");
        return NULL;
    }

    // Read the book's title
    fscanf(file, "%s", book->title);

    // Read the book's author
    fscanf(file, "%s", book->author);

    // Read the book's pages
    fscanf(file, "%d", &book->pages);

    // Read the book's text
    book->text = malloc(book->pages * 1000);
    if (book->text == NULL) {
        printf("Error allocating memory for book text\n");
        return NULL;
    }

    fread(book->text, 1, book->pages * 1000, file);

    // Close the file
    fclose(file);

    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->text);
    free(book);
}

// Function to print a book's title, author, pages, and text
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

    // Print the book's title, author, pages, and text
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}