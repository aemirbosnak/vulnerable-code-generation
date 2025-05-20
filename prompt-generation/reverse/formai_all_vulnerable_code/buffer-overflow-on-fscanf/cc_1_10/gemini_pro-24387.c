//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a book.
typedef struct Book {
    char title[100];
    char author[100];
    int pages;
    char content[1000];
} Book;

// Function to read a book from a file.
Book* readBook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the book.
    Book* book = malloc(sizeof(Book));
    if (book == NULL) {
        printf("Error allocating memory for book\n");
        fclose(file);
        return NULL;
    }

    // Read the title, author, and pages from the file.
    fscanf(file, "%s %s %d\n", book->title, book->author, &book->pages);

    // Read the content of the book from the file.
    char line[1000];
    while (fgets(line, 1000, file) != NULL) {
        strcat(book->content, line);
    }

    // Close the file.
    fclose(file);

    return book;
}

// Function to free the memory allocated for a book.
void freeBook(Book* book) {
    free(book);
}

// Function to print the contents of a book.
void printBook(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content:\n%s\n", book->content);
}

int main() {
    // Read the book from the file.
    Book* book = readBook("book.txt");
    if (book == NULL) {
        return 1;
    }

    // Print the contents of the book.
    printBook(book);

    // Free the memory allocated for the book.
    freeBook(book);

    return 0;
}