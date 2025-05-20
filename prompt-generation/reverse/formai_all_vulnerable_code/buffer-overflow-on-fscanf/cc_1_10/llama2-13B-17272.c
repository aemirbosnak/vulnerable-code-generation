//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOK_LENGTH 10000
#define MAX_CHAPTERS 10

// Structure to hold information about a book
typedef struct {
    char title[50];
    char author[50];
    char chapter[50];
    int pages[MAX_CHAPTERS];
} book_t;

// Function to initialize a book structure with default values
void init_book(book_t *book) {
    strcpy(book->title, "Untitled");
    strcpy(book->author, "Unknown");
    for (int i = 0; i < MAX_CHAPTERS; i++) {
        book->pages[i] = 0;
    }
}

// Function to read a book from a file and store it in memory
book_t *read_book(const char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Create a book structure to store the data
    book_t *book = malloc(sizeof(book_t));
    if (book == NULL) {
        printf("Error: Unable to allocate memory for book structure\n");
        fclose(file);
        return NULL;
    }

    // Read the book title
    fscanf(file, "%s", book->title);

    // Read the author name
    fscanf(file, "%s", book->author);

    // Read the chapter numbers and page counts
    for (int i = 0; i < MAX_CHAPTERS; i++) {
        int chapter_num;
        int page_count;
        fscanf(file, "%d %d", &chapter_num, &page_count);
        book->pages[i] = page_count;
    }

    // Close the file and return the book structure
    fclose(file);
    return book;
}

// Function to display the book's contents
void display_book(book_t *book) {
    printf("Book Title: %s\n", book->title);
    printf("Author: %s\n", book->author);

    for (int i = 0; i < MAX_CHAPTERS; i++) {
        printf("Chapter %d: %d pages\n", i + 1, book->pages[i]);
    }
}

int main() {
    // Load a book from a file
    book_t *book = read_book("example_book.txt");
    if (book == NULL) {
        printf("Error: Unable to read book from file\n");
        return 1;
    }

    // Display the book's contents
    display_book(book);

    // Free the book structure
    free(book);

    return 0;
}