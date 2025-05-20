//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct {
    char *title;
    char *author;
    char *text;
    int num_pages;
} Book;

// Read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the book's title
    char *title = NULL;
    size_t title_len = 0;
    getline(&title, &title_len, fp);

    // Read the book's author
    char *author = NULL;
    size_t author_len = 0;
    getline(&author, &author_len, fp);

    // Read the book's text
    char *text = NULL;
    size_t text_len = 0;
    getline(&text, &text_len, fp);

    // Read the book's number of pages
    int num_pages;
    fscanf(fp, "%d", &num_pages);

    // Close the file
    fclose(fp);

    // Create a new book struct
    Book *book = malloc(sizeof(Book));
    book->title = title;
    book->author = author;
    book->text = text;
    book->num_pages = num_pages;

    // Return the book
    return book;
}

// Print a book to the console
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Text: %s\n", book->text);
    printf("Num pages: %d\n", book->num_pages);
}

// Free a book's memory
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book from the file
    Book *book = read_book(argv[1]);
    if (book == NULL) {
        return 1;
    }

    // Print the book to the console
    print_book(book);

    // Free the book's memory
    free_book(book);

    return 0;
}