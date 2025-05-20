//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of a line in the book
#define MAX_LINE_LENGTH 1024

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages) {
    book *new_book = malloc(sizeof(book));
    new_book->title = title;
    new_book->author = author;
    new_book->num_pages = num_pages;
    new_book->pages = malloc(sizeof(char *) * num_pages);
    return new_book;
}

// Free the memory allocated for a book
void free_book(book *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

// Load a book from a file
book *load_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title and author of the book
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    fgets(title, MAX_LINE_LENGTH, fp);
    fgets(author, MAX_LINE_LENGTH, fp);

    // Read the number of pages in the book
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Create a new book
    book *new_book = create_book(title, author, num_pages);

    // Read the pages of the book
    for (int i = 0; i < num_pages; i++) {
        char *page = malloc(sizeof(char) * MAX_LINE_LENGTH);
        fgets(page, MAX_LINE_LENGTH, fp);
        new_book->pages[i] = page;
    }

    fclose(fp);

    return new_book;
}

// Print the contents of a book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s\n", i + 1, book->pages[i]);
    }
}

// Main function
int main() {
    // Load a book from a file
    book *book = load_book("book.txt");

    // Print the contents of the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}