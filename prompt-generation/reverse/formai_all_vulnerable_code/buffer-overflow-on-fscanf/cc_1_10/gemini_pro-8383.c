//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a book
typedef struct book {
    char *title;
    char *author;
    int num_pages;
    int current_page;
} book;

// Create a new book
book *create_book(char *title, char *author, int num_pages) {
    book *new_book = malloc(sizeof(book));
    new_book->title = title;
    new_book->author = author;
    new_book->num_pages = num_pages;
    new_book->current_page = 1;
    return new_book;
}

// Open a book file
FILE *open_book_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Read a book from a file
book *read_book(FILE *fp) {
    char *title = NULL;
    char *author = NULL;
    int num_pages = 0;
    int c;

    // Read the title
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        title = realloc(title, strlen(title) + 1);
        title[strlen(title)] = c;
    }

    // Read the author
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        author = realloc(author, strlen(author) + 1);
        author[strlen(author)] = c;
    }

    // Read the number of pages
    fscanf(fp, "%d", &num_pages);

    // Create a new book
    book *new_book = create_book(title, author, num_pages);

    // Free the memory allocated for the title and author
    free(title);
    free(author);

    return new_book;
}

// Print a book
void print_book(book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Current page: %d\n", book->current_page);
}

// Turn a page in a book
void turn_page(book *book) {
    if (book->current_page < book->num_pages) {
        book->current_page++;
    }
}

// Close a book file
void close_book_file(FILE *fp) {
    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the book file
    FILE *fp = open_book_file(argv[1]);

    // Read the book from the file
    book *book = read_book(fp);

    // Print the book
    print_book(book);

    // Turn a page in the book
    turn_page(book);

    // Print the book
    print_book(book);

    // Close the book file
    close_book_file(fp);

    // Free the memory allocated for the book
    free(book);

    return 0;
}