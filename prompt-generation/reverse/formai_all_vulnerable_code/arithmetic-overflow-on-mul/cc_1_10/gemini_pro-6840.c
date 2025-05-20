//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    int pages;
    char *content;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int pages, char *content) {
    Book *book = malloc(sizeof(Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pages = pages;
    book->content = content;
    return book;
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the title, author, and pages
    char title[100];
    char author[100];
    int pages;
    fscanf(fp, "%s %s %d\n", title, author, &pages);

    // Allocate memory for the content
    char *content = malloc(pages * 1000);

    // Read the content
    int i = 0;
    while (!feof(fp)) {
        char line[1000];
        fgets(line, 1000, fp);
        strcpy(content + i * 1000, line);
        i++;
    }

    // Close the file
    fclose(fp);

    // Create the book
    Book *book = create_book(title, author, pages, content);
    return book;
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content:\n%s", book->content);
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->content);
    free(book);
}

// Main function
int main() {
    // Read the book from the file
    Book *book = read_book("book.txt");

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}