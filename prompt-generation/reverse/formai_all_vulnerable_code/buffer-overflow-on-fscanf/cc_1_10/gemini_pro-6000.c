//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
struct Book {
    char title[50];
    char author[50];
    int num_pages;
    char text[10000];
};

// Function to read a book from a file
struct Book *read_book(char *filename) {
    FILE *fp;
    struct Book *book;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the book
    book = malloc(sizeof(struct Book));
    if (book == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the title
    fscanf(fp, "%s", book->title);

    // Read the author
    fscanf(fp, "%s", book->author);

    // Read the number of pages
    fscanf(fp, "%d", &book->num_pages);

    // Read the text
    char buffer[10000];
    while (fgets(buffer, 10000, fp)) {
        strcat(book->text, buffer);
    }

    // Close the file
    fclose(fp);

    return book;
}

// Function to print a book
void print_book(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Function to free the memory allocated for a book
void free_book(struct Book *book) {
    free(book);
}

int main() {
    // Read the book from a file
    struct Book *book = read_book("book.txt");
    if (book == NULL) {
        return 1;
    }

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}