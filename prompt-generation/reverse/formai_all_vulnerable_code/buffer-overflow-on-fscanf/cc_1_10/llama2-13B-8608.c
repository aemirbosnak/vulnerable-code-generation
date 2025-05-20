//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to hold information about a book
struct book {
    char title[50];
    char author[50];
    int publicationYear;
    int pages;
};

// Function to read a book from a file and store it in a struct
struct book readBook(FILE *file) {
    struct book b;
    fscanf(file, "%s %s %d %d", b.title, b.author, &b.publicationYear, &b.pages);
    return b;
}

// Function to write a book to a file
void writeBook(struct book b, FILE *file) {
    fprintf(file, "%s %s %d %d\n", b.title, b.author, b.publicationYear, b.pages);
}

// Function to print a list of books
void printBooks(struct book *books, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%d. %s by %s (%d pages)\n", i + 1, books[i].title, books[i].author, books[i].pages);
    }
}

int main() {
    // Open a file for reading and writing
    FILE *file = fopen("books.dat", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read a list of books from the file
    struct book books[5];
    int count = 0;
    while (fscanf(file, "%s %s %d %d", books[count].title, books[count].author, &books[count].publicationYear, &books[count].pages) == 4) {
        count++;
    }

    // Print the list of books
    printBooks(books, count);

    // Add a new book to the file
    struct book newBook = {"The Second Mountain", "David Brooks", 2019, 320};
    writeBook(newBook, file);

    // Print the updated list of books
    printBooks(books, count + 1);

    // Close the file
    fclose(file);

    return 0;
}