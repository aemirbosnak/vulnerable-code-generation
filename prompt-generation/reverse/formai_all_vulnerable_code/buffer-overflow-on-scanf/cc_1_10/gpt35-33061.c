//FormAI DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 10000

// Define the book structure
typedef struct Book {
    char title[50];
    char author[50];
    char file_name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
} Book;

// Define the function to load a book from a file
void load_book(Book *book) {
    // Prompt the user for the file name
    printf("Enter the file name of the book: ");
    scanf("%s", book->file_name);

    // Open the file and read the contents into the book structure
    FILE *fp = fopen(book->file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", book->file_name);
        exit(1);
    }
    fgets(book->title, 50, fp);
    fgets(book->author, 50, fp);
    fgets(book->content, MAX_FILE_SIZE, fp);
    fclose(fp);
}

// Define the function to display the book
void display_book(Book book) {
    printf("Title: %s", book.title);
    printf("Author: %s", book.author);
    printf("%s\n", book.content);
}

int main() {
    // Create a book structure and load the book from a file
    Book book;
    load_book(&book);

    // Display the book to the user
    display_book(book);

    return 0;
}