//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct book {
    char title[50];
    char author[50];
    int pages;
    float price;
} book;

// Function to read a book from a file
book readBook(FILE *fp) {
    book b;
    fscanf(fp, "%s %s %d %f", b.title, b.author, &b.pages, &b.price);
    return b;
}

// Function to print a book
void printBook(book b) {
    printf("%s by %s, %d pages, $%.2f\n", b.title, b.author, b.pages, b.price);
}

// Function to search for a book by title
book *searchBook(book *books, int n, char *title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Open the file containing the books
    FILE *fp = fopen("books.txt", "r");

    // Read the number of books from the file
    int n;
    fscanf(fp, "%d", &n);

    // Allocate memory for the books
    book *books = malloc(n * sizeof(book));

    // Read the books from the file
    for (int i = 0; i < n; i++) {
        books[i] = readBook(fp);
    }

    // Close the file
    fclose(fp);

    // Search for a book by title
    char title[50];
    printf("Enter the title of the book you want to search for: ");
    scanf("%s", title);

    book *b = searchBook(books, n, title);

    // Print the book if it was found
    if (b != NULL) {
        printBook(*b);
    } else {
        printf("Book not found.\n");
    }

    // Free the memory allocated for the books
    free(books);

    return 0;
}