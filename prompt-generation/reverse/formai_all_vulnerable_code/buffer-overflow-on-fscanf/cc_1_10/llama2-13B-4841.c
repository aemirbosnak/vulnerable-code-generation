//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BOOK_WIDTH 800
#define BOOK_HEIGHT 1200

// Structure to store book information
typedef struct {
    char title[50];
    char author[50];
    int pageCount;
} book_t;

// Function to read a book from a file
book_t read_book(char *file_name) {
    book_t book;
    FILE *file = fopen(file_name, "r");

    // Read book title
    fscanf(file, "%s", book.title);

    // Read book author
    fscanf(file, "%s", book.author);

    // Read book page count
    int page_count = 0;
    fscanf(file, "%d", &page_count);

    // Return book information
    return book;
}

// Function to display a book
void display_book(book_t book) {
    int current_page = 0;

    // Print book title
    printf("Book Title: %s\n", book.title);

    // Print book author
    printf("Book Author: %s\n", book.author);

    // Print book page count
    printf("Page Count: %d\n", book.pageCount);

    // Print current page number
    printf("Current Page: %d\n", current_page);

    // Print book text
    for (int i = 0; i < book.pageCount; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < BOOK_WIDTH; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    // Load book from file
    book_t book = read_book("example_book.txt");

    // Display book
    display_book(book);

    return 0;
}