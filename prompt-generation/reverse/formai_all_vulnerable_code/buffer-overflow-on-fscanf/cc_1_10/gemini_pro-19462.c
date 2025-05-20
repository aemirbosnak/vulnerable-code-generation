//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of pages in the book
#define MAX_PAGES 100

// Define the maximum number of characters per page
#define MAX_CHARS_PER_PAGE 1000

// Create a struct to represent a book
typedef struct book {
    char title[100];
    char author[100];
    int num_pages;
    char pages[MAX_PAGES][MAX_CHARS_PER_PAGE];
} book;

// Create a function to load a book from a file
book *load_book(char *filename) {
    // Allocate memory for the book
    book *b = malloc(sizeof(book));

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title and author from the file
    fscanf(fp, "%s %s\n", b->title, b->author);

    // Read the number of pages from the file
    fscanf(fp, "%d\n", &b->num_pages);

    // Read the pages from the file
    for (int i = 0; i < b->num_pages; i++) {
        fgets(b->pages[i], MAX_CHARS_PER_PAGE, fp);
    }

    // Close the file
    fclose(fp);

    // Return the book
    return b;
}

// Create a function to print a book
void print_book(book *b) {
    // Print the title and author of the book
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);

    // Print the pages of the book
    for (int i = 0; i < b->num_pages; i++) {
        printf("Page %d:\n", i + 1);
        printf("%s\n", b->pages[i]);
    }
}

// Create a function to free the memory allocated for a book
void free_book(book *b) {
    // Free the memory allocated for the pages
    for (int i = 0; i < b->num_pages; i++) {
        free(b->pages[i]);
    }

    // Free the memory allocated for the book
    free(b);
}

int main() {
    // Load a book from a file
    book *b = load_book("book.txt");
    if (b == NULL) {
        return 1;
    }

    // Print the book
    print_book(b);

    // Free the memory allocated for the book
    free_book(b);

    return 0;
}