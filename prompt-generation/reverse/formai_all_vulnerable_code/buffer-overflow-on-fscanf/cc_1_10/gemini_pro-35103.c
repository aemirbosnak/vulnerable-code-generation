//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an e-book
typedef struct ebook {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} ebook;

// Create a new e-book
ebook *create_ebook(char *title, char *author, int num_pages) {
    ebook *book = malloc(sizeof(ebook));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(num_pages * sizeof(char *));
    return book;
}

// Open an e-book file and read its contents into an e-book struct
ebook *open_ebook(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the title and author
    read = getline(&line, &len, fp);
    char *title = strdup(line);
    read = getline(&line, &len, fp);
    char *author = strdup(line);

    // Read the number of pages
    int num_pages;
    fscanf(fp, "%d\n", &num_pages);

    // Read the pages
    char **pages = malloc(num_pages * sizeof(char *));
    for (int i = 0; i < num_pages; i++) {
        read = getline(&line, &len, fp);
        pages[i] = strdup(line);
    }

    // Close the file
    fclose(fp);

    // Create the e-book struct
    ebook *book = create_ebook(title, author, num_pages);
    book->pages = pages;

    return book;
}

// Print the contents of an e-book
void print_ebook(ebook *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s", i + 1, book->pages[i]);
    }
}

// Free the memory allocated for an e-book
void free_ebook(ebook *book) {
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the e-book file
    ebook *book = open_ebook(argv[1]);
    if (book == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Print the contents of the e-book
    print_ebook(book);

    // Free the memory allocated for the e-book
    free_ebook(book);

    return EXIT_SUCCESS;
}