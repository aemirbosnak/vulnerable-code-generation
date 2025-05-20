//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a book
typedef struct {
    char title[50];
    char author[50];
    char genre[50];
    char content[5000];
} Book;

// Function to display the book information
void displayBookInfo(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Genre: %s\n", book.genre);
    printf("Content: %s\n", book.content);
}

// Function to load a book from a file
Book loadBook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Book book;
    fscanf(file, "%s %s %s %[^\n]", book.title, book.author, book.genre, book.content);

    fclose(file);
    return book;
}

// Function to save a book to a file
void saveBook(Book book, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "%s %s %s %s", book.title, book.author, book.genre, book.content);

    fclose(file);
}

int main() {
    // Load the book from a file
    Book book = loadBook("book.txt");

    // Display the book information
    displayBookInfo(book);

    // Save the book to a file
    saveBook(book, "book_copy.txt");

    return 0;
}