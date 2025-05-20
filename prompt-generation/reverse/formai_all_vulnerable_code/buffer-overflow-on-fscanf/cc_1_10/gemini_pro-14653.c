//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a book
typedef struct book {
    char title[100];
    char author[100];
    int pages;
    char genre[100];
} book;

// Function to print a book
void print_book(book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Genre: %s\n", b.genre);
}

// Function to read a book from a file
book read_book(char *filename) {
    book b;

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the title
    fgets(b.title, 100, fp);

    // Read the author
    fgets(b.author, 100, fp);

    // Read the pages
    fscanf(fp, "%d", &b.pages);

    // Read the genre
    fgets(b.genre, 100, fp);

    // Close the file
    fclose(fp);

    return b;
}

// Function to main
int main() {
    // Declare a book variable
    book b;

    // Read the book from a file
    b = read_book("book.txt");

    // Print the book
    print_book(b);

    return 0;
}