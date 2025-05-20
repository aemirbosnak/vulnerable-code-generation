//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to hold information about a book
struct book {
    char title[50];
    char author[50];
    int pages;
    int publication_year;
};

// Function to read a book's information from a file
struct book read_book(FILE *file) {
    struct book b;
    fscanf(file, "%s %s %d %d", b.title, b.author, &b.pages, &b.publication_year);
    return b;
}

// Function to write a book's information to a file
void write_book(struct book b, FILE *file) {
    fprintf(file, "%s %s %d %d\n", b.title, b.author, b.pages, b.publication_year);
}

int main() {
    // Open a file for reading and writing
    FILE *file = fopen("books.dat", "r+");
    if (file == NULL) {
        printf("Error: unable to open file\n");
        return 1;
    }

    // Read a book's information from the file
    struct book b = read_book(file);
    printf("Book: %s, Author: %s, Pages: %d, Publication Year: %d\n",
           b.title, b.author, b.pages, b.publication_year);

    // Add a new book to the file
    struct book new_book = {
        .title = "The Alchemist",
        .author = "Paulo Coelho",
        .pages = 224,
        .publication_year = 1988
    };
    write_book(new_book, file);

    // Close the file
    fclose(file);

    return 0;
}