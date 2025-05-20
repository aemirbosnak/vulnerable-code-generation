//GEMINI-pro DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define MAX_LINE_LENGTH 1024

typedef struct _book {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int year_published;
    int num_pages;
} book;

int main() {
    // Open the input file.
    FILE *input_file = fopen("books.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file.");
        return EXIT_FAILURE;
    }

    // Read the number of books from the input file.
    int num_books;
    fscanf(input_file, "%d\n", &num_books);

    // Allocate memory for the array of books.
    book *books = malloc(num_books * sizeof(book));
    if (books == NULL) {
        perror("Error allocating memory for array of books.");
        return EXIT_FAILURE;
    }

    // Read the book data from the input file.
    for (int i = 0; i < num_books; i++) {
        fscanf(input_file, "%s %s %d %d\n", books[i].title, books[i].author, &books[i].year_published, &books[i].num_pages);
    }

    // Close the input file.
    fclose(input_file);

    // Open the output file.
    FILE *output_file = fopen("books.csv", "w");
    if (output_file == NULL) {
        perror("Error opening output file.");
        return EXIT_FAILURE;
    }

    // Write the book data to the output file.
    fprintf(output_file, "Title,Author,Year Published,Number of Pages\n");
    for (int i = 0; i < num_books; i++) {
        fprintf(output_file, "%s,%s,%d,%d\n", books[i].title, books[i].author, books[i].year_published, books[i].num_pages);
    }

    // Close the output file.
    fclose(output_file);

    // Free the memory for the array of books.
    free(books);

    return EXIT_SUCCESS;
}