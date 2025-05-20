//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BOOK_LENGTH 100000
#define MAX_PAGE_COUNT 100

// Structure to store book information
typedef struct {
    char title[50];
    char author[50];
    int pageCount;
    char text[MAX_BOOK_LENGTH];
} Book;

// Function to read a book from a file
Book readBook(const char* filename) {
    Book book;
    char line[100];
    int page = 0;

    // Open the book file
    FILE* file = fopen(filename, "r");

    // Read the book title and author
    fscanf(file, "%s %s", book.title, book.author);

    // Read the book text, word by word
    while (fgets(line, 100, file) != NULL) {
        book.text[page * 100] = line[0];
        page++;
    }

    // Calculate the number of pages
    book.pageCount = page;

    // Close the book file
    fclose(file);

    return book;
}

// Function to display a book
void displayBook(const Book* book) {
    int i = 0;

    printf("Book Title: %s\n", book->title);
    printf("Book Author: %s\n", book->author);

    for (i = 0; i < book->pageCount; i++) {
        printf("%d. Page: %s\n", i + 1, book->text + i * 100);
    }
}

int main() {
    // Read a book from a file
    Book book = readBook("example_book.txt");

    // Display the book
    displayBook(&book);

    return 0;
}