//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
struct book {
    char *title;
    char *author;
    int num_pages;
    char *text;
};

// Create a new book
struct book *create_book(char *title, char *author, int num_pages, char *text) {
    // Allocate memory for the book
    struct book *book = malloc(sizeof(struct book));

    // Copy the title, author, and number of pages into the book
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->text = strdup(text);

    // Return the book
    return book;
}

// Free the memory allocated for a book
void free_book(struct book *book) {
    // Free the memory allocated for the title, author, and text
    free(book->title);
    free(book->author);
    free(book->text);

    // Free the memory allocated for the book
    free(book);
}

// Print the information about a book
void print_book(struct book *book) {
    // Print the title, author, and number of pages
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);

    // Print the first 100 characters of the text
    printf("Text: %.*s\n", 100, book->text);
}

// Read a book from a file
struct book *read_book(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title, author, and number of pages
    char title[100];
    char author[100];
    int num_pages;
    fscanf(fp, "%s %s %d", title, author, &num_pages);

    // Read the text
    char *text = malloc(num_pages + 1);
    fread(text, num_pages, 1, fp);
    text[num_pages] = '\0';

    // Close the file
    fclose(fp);

    // Create the book
    struct book *book = create_book(title, author, num_pages, text);

    // Return the book
    return book;
}

// Write a book to a file
void write_book(char *filename, struct book *book) {
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    // Write the title, author, and number of pages
    fprintf(fp, "%s %s %d\n", book->title, book->author, book->num_pages);

    // Write the text
    fwrite(book->text, book->num_pages, 1, fp);

    // Close the file
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the book from the file
    struct book *book = read_book(argv[1]);
    if (book == NULL) {
        printf("Error reading book from file\n");
        return 1;
    }

    // Print the information about the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}