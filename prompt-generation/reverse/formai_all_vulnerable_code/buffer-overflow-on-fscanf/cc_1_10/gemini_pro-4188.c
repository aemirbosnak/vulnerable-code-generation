//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOK_SIZE 100000

typedef struct {
    char title[100];
    char author[100];
    int num_pages;
    char text[MAX_BOOK_SIZE];
} Book;

bool load_book(Book *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    fscanf(file, "%s %s %d", book->title, book->author, &book->num_pages);
    
    // Read the book's text
    int i = 0;
    while (fscanf(file, "%c", &book->text[i]) != EOF) {
        i++;
    }

    fclose(file);
    return true;
}

void print_book(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

int main() {
    Book book;

    // Load the book from a file
    if (!load_book(&book, "book.txt")) {
        printf("Error loading book.\n");
        return 1;
    }

    // Print the book's information
    print_book(&book);

    return 0;
}