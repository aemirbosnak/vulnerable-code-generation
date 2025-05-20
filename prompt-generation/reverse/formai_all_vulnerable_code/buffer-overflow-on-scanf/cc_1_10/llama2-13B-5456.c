//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to hold information about a book
typedef struct {
    char title[50];
    char author[50];
    int pages;
    int publication_year;
} book_t;

// Function to read a book from a file
book_t read_book(FILE *file) {
    book_t b;
    char line[100];

    // Read the title
    fgets(line, 100, file);
    strcpy(b.title, line);

    // Read the author
    fgets(line, 100, file);
    strcpy(b.author, line);

    // Read the pages
    int pages;
    scanf("%d", &pages);
    b.pages = pages;

    // Read the publication year
    int year;
    scanf("%d", &year);
    b.publication_year = year;

    return b;
}

// Function to write a book to a file
void write_book(book_t b, FILE *file) {
    fprintf(file, "%s\n", b.title);
    fprintf(file, "%s\n", b.author);
    fprintf(file, "%d\n", b.pages);
    fprintf(file, "%d\n", b.publication_year);
}

int main() {
    // Open a file in read and write mode
    FILE *file = fopen("books.txt", "r+");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Read a book from the file
    book_t b = read_book(file);
    printf("Book title: %s\n", b.title);
    printf("Book author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Publication year: %d\n", b.publication_year);

    // Write a new book to the file
    b.title[0] = 'A';
    b.title[1] = 'n';
    b.title[2] = 'd';
    b.title[3] = 'e';
    b.author[0] = 'J';
    b.author[1] = 'K';
    b.author[2] = ' R';
    b.author[3] = 'o';
    b.pages = 300;
    b.publication_year = 2022;
    write_book(b, file);

    // Close the file
    fclose(file);

    return 0;
}