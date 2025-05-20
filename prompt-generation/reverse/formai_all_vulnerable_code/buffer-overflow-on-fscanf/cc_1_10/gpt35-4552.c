//FormAI DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_BOOK_TITLE 50
#define MAX_BOOK_AUTHOR 50
#define MAX_LINE_LENGTH 100

// Book structure
typedef struct {
    char title[MAX_BOOK_TITLE];
    char author[MAX_BOOK_AUTHOR];
    int num_pages;
} Book;

// Function to read book from file
void read_book(Book *book, char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }
    fscanf(fp, "%s", book->title);
    fscanf(fp, "%s", book->author);
    fscanf(fp, "%d", &book->num_pages);
    fclose(fp);
}

// Function to print book
void print_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.num_pages);
}

int main() {
    // Get file name from user
    char file_name[MAX_FILE_NAME];
    printf("Enter name of book file: ");
    scanf("%s", file_name);

    // Read book from file
    Book book;
    read_book(&book, file_name);

    // Print book
    print_book(book);

    return 0;
}