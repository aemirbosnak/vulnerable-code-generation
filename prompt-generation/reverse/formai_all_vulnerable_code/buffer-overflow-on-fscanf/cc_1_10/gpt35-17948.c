//FormAI DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a typedef for the book structure
typedef struct {
    char title[100];
    char author[50];
    int year;
    int num_pages;
    char* content;
} Book;

// Function to read a book from a file
Book read_book(char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Create a Book struct and read the data from the file
    Book book;
    fscanf(fp, "%[^\n]\n", book.title);
    fscanf(fp, "%[^\n]\n", book.author);
    fscanf(fp, "%d\n", &book.year);
    fscanf(fp, "%d\n", &book.num_pages);

    // Allocate memory for the book content
    book.content = (char*) malloc(book.num_pages * sizeof(char));

    // Read the content from the file
    fread(book.content, sizeof(char), book.num_pages, fp);

    // Close the file
    fclose(fp);

    return book;
}

// Function to print book information to the console
void print_book_info(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Number of Pages: %d\n", book.num_pages);
}

int main() {
    // Read in a book from a file
    Book book = read_book("book.txt");

    // Print out the book information
    print_book_info(book);

    // Print out the book content
    printf("Content:\n%s", book.content);

    // Free the memory used by the book content
    free(book.content);

    return 0;
}