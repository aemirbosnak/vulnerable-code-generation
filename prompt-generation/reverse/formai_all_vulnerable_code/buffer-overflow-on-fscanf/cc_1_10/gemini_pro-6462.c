//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Book structure
typedef struct Book {
    char title[50];
    char author[50];
    int pages;
    char *content;
} Book;

// Function to read a book from a file
Book *read_book(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title, author, and pages
    Book *book = malloc(sizeof(Book));
    fscanf(fp, "%s %s %d", book->title, book->author, &book->pages);

    // Read the content
    int content_size = 0;
    char *content = NULL;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        content_size += strlen(line);
    }
    content = malloc(content_size + 1);
    rewind(fp);
    while (fgets(line, sizeof(line), fp) != NULL) {
        strcat(content, line);
    }
    book->content = content;

    // Close the file
    fclose(fp);

    return book;
}

// Function to print a book
void print_book(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content:\n%s\n", book->content);
}

// Main function
int main() {
    // Read a book from a file
    Book *book = read_book("book.txt");
    if (book == NULL) {
        return 1;
    }

    // Print the book
    print_book(book);

    // Free the memory allocated for the book
    free(book->content);
    free(book);

    return 0;
}