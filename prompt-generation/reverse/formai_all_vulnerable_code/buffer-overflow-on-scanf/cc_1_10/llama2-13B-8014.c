//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_BOOK_NAME 50
#define MAX_AUTHOR 20
#define MAX_PAGES 1000

// Structure to store book information
typedef struct {
    char name[MAX_BOOK_NAME];
    char author[MAX_AUTHOR];
    int pages;
} book_t;

// Function to read a book from a file
book_t read_book(const char* filename) {
    // Open the file in read mode
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return (book_t){};
    }

    // Read the book name, author, and pages
    char line[100];
    gets(line, sizeof(line)); // Ignore the first line (book name)
    gets(line, sizeof(line)); // Ignore the second line (author)
    int pages;
    scanf("%d", &pages);

    // Create a new book struct and fill it with the read data
    book_t book;
    strcpy(book.name, line);
    strcpy(book.author, line);
    book.pages = pages;

    // Close the file
    fclose(file);

    return book;
}

// Function to display a book
void display_book(const book_t* book) {
    printf("Book: %s\nAuthor: %s\nPages: %d\n\n", book->name, book->author, book->pages);
}

// Function to read a book and display it
void read_and_display_book(const char* filename) {
    book_t book = read_book(filename);
    display_book(&book);
}

int main() {
    // Read and display a book
    read_and_display_book("example.txt");

    return 0;
}