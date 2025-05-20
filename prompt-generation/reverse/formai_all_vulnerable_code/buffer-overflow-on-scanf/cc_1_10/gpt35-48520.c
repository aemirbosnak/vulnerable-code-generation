//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the book title and author's name
#define MAX_TITLE_SIZE 50
#define MAX_AUTHOR_NAME_SIZE 30

// A structure to hold information about a book
struct book {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_NAME_SIZE];
    int pageCount;
};

// Function to read the details of a book from the user
void readBook(struct book *b) {
    printf("Enter book title: ");
    fgets(b->title, MAX_TITLE_SIZE, stdin);
    strtok(b->title, "\n"); // remove the newline character

    printf("Enter author's name: ");
    fgets(b->author, MAX_AUTHOR_NAME_SIZE, stdin);
    strtok(b->author, "\n"); // remove the newline character

    printf("Enter page count: ");
    scanf("%d", &b->pageCount);
}

// Function to print the details of a book
void printBook(struct book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Page Count: %d\n", b.pageCount);
}

// Function to read the details of a book from a file
void readBookFromFile(struct book *b, FILE *file) {
    fgets(b->title, MAX_TITLE_SIZE, file);
    strtok(b->title, "\n"); // remove the newline character

    fgets(b->author, MAX_AUTHOR_NAME_SIZE, file);
    strtok(b->author, "\n"); // remove the newline character

    fscanf(file, "%d", &b->pageCount);
    fgetc(file); // remove the newline character
}

// Function to print the details of a book to a file
void printBookToFile(struct book b, FILE *file) {
    fprintf(file, "%s\n", b.title);
    fprintf(file, "%s\n", b.author);
    fprintf(file, "%d\n", b.pageCount);
}

int main() {
    struct book myBook; // create a book structure

    // Read details of the book from the user
    readBook(&myBook);

    // Print the details of the book
    printf("\nDetails of the book:\n");
    printBook(myBook);

    // Write the details of the book to a file
    FILE *file = fopen("book.txt", "w");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    printBookToFile(myBook, file);
    fclose(file);

    // Read the details of the book from the file
    struct book myNewBook;
    file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    readBookFromFile(&myNewBook, file);
    printf("\nDetails of the new book read from file:\n");
    printBook(myNewBook);
    fclose(file);

    return 0;
}