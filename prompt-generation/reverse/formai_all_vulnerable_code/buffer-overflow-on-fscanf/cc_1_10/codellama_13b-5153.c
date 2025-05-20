//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
// Dennis Ritchie-style Ebook reader program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for storing book information
typedef struct {
    char title[256];
    char author[256];
    char genre[256];
    int pages;
    int year;
} book_t;

// Function to display book information
void display_book(book_t book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Genre: %s\n", book.genre);
    printf("Pages: %d\n", book.pages);
    printf("Year: %d\n", book.year);
}

// Function to read book information from file
book_t read_book(FILE *fp) {
    book_t book;
    fscanf(fp, "%s %s %s %d %d", book.title, book.author, book.genre, &book.pages, &book.year);
    return book;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: ebook <filename>\n");
        return 1;
    }

    // Open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Read book information from file
    book_t book = read_book(fp);

    // Display book information
    display_book(book);

    // Close file
    fclose(fp);

    return 0;
}