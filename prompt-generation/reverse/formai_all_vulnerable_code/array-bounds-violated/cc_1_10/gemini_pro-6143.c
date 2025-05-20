//GEMINI-pro DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store data about a book
typedef struct book {
    char title[50];
    char author[50];
    int year;
    float price;
} Book;

// Function to read data about a book from a file
Book readBookFromFile(FILE *fp) {
    Book book;

    // Read the title of the book
    fgets(book.title, 50, fp);
    // Remove the newline character from the title
    book.title[strlen(book.title) - 1] = '\0';

    // Read the author of the book
    fgets(book.author, 50, fp);
    // Remove the newline character from the author
    book.author[strlen(book.author) - 1] = '\0';

    // Read the year of publication of the book
    fscanf(fp, "%d", &book.year);

    // Read the price of the book
    fscanf(fp, "%f", &book.price);

    return book;
}

// Function to write data about a book to a file
void writeBookToFile(FILE *fp, Book book) {
    // Write the title of the book to the file
    fprintf(fp, "%s\n", book.title);

    // Write the author of the book to the file
    fprintf(fp, "%s\n", book.author);

    // Write the year of publication of the book to the file
    fprintf(fp, "%d\n", book.year);

    // Write the price of the book to the file
    fprintf(fp, "%f\n", book.price);
}

// Function to print the data about a book
void printBook(Book book) {
    // Print the title of the book
    printf("Title: %s\n", book.title);

    // Print the author of the book
    printf("Author: %s\n", book.author);

    // Print the year of publication of the book
    printf("Year: %d\n", book.year);

    // Print the price of the book
    printf("Price: %f\n", book.price);
}

int main() {
    // Open the file containing the data about the books
    FILE *fp = fopen("books.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening the file!\n");
        return EXIT_FAILURE;
    }

    // Read the data about the first book from the file
    Book book1 = readBookFromFile(fp);

    // Print the data about the first book
    printf("First book:\n");
    printBook(book1);

    // Read the data about the second book from the file
    Book book2 = readBookFromFile(fp);

    // Print the data about the second book
    printf("Second book:\n");
    printBook(book2);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}