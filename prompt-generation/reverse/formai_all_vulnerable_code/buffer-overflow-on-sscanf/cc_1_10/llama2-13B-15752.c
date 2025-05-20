//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold information about a book
typedef struct book {
    char title[50];
    char author[50];
    int publicationYear;
    int pages;
} book;

// Function to read a book from a file
book readBook(FILE *file) {
    book b;
    char line[100];

    // Read the title
    fgets(line, 100, file);
    sscanf(line, "%s", b.title);

    // Read the author
    fgets(line, 100, file);
    sscanf(line, "%s", b.author);

    // Read the publication year
    fscanf(file, "%d", &b.publicationYear);

    // Read the number of pages
    fscanf(file, "%d", &b.pages);

    return b;
}

// Function to write a book to a file
void writeBook(FILE *file, book b) {
    fprintf(file, "%s\n", b.title);
    fprintf(file, "%s\n", b.author);
    fprintf(file, "%d\n", b.publicationYear);
    fprintf(file, "%d\n", b.pages);
}

int main() {
    // Open a file in read and write mode
    FILE *file = fopen("books.txt", "r+");

    // Check if the file exists
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read a book from the file
    book b = readBook(file);

    // Print the book information
    printf("Title: %s\nAuthor: %s\nPublication Year: %d\nPages: %d\n", b.title, b.author, b.publicationYear, b.pages);

    // Write the book to the file
    writeBook(file, b);

    // Close the file
    fclose(file);

    return 0;
}