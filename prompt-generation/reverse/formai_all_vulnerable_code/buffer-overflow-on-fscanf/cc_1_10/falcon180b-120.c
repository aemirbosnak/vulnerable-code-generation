//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a book
typedef struct {
    char title[100];
    char author[100];
    int pages;
    char genre[50];
} Book;

// Function to read books from a file
void readBooks(FILE *fp, Book books[]) {
    int i = 0;
    while (fscanf(fp, "%s %s %d %s", books[i].title, books[i].author, &books[i].pages, books[i].genre)!= EOF) {
        i++;
    }
}

// Function to display books
void displayBooks(Book books[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Title: %s\nAuthor: %s\nPages: %d\nGenre: %s\n", books[i].title, books[i].author, books[i].pages, books[i].genre);
        printf("\n");
    }
}

// Function to search for a book by title
int searchBookByTitle(Book books[], int n, char title[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the file containing book information: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read books from the file
    Book books[100];
    int n = 0;
    readBooks(fp, books);
    n = sizeof(books)/sizeof(books[0]);

    // Display all books
    printf("All books:\n");
    displayBooks(books, n);

    // Search for a book by title
    char title[100];
    printf("Enter the title of the book you want to search for: ");
    scanf("%s", title);
    int index = searchBookByTitle(books, n, title);

    if (index == -1) {
        printf("Book not found.\n");
    } else {
        printf("Book found:\n");
        displayBooks(books, 1);
    }

    fclose(fp);
    return 0;
}