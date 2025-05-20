//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 50
#define MAX_FILENAME_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
} Book;

void display_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
}

void display_books(Book books[], int num_books) {
    for (int i = 0; i < num_books; i++) {
        printf("Book #%d:\n", i+1);
        display_book(books[i]);
        printf("\n");
    }
}

void read_book_from_file(char *filename, Book *book) {
    FILE *fp;
    char line[MAX_AUTHOR_LEN + MAX_TITLE_LEN + 10]; // Allocate extra space to handle integer conversion

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    fgets(line, sizeof line, fp);
    strncpy(book->title, line, MAX_TITLE_LEN);

    fgets(line, sizeof line, fp);
    strncpy(book->author, line, MAX_AUTHOR_LEN);

    fgets(line, sizeof line, fp);
    book->pages = atoi(line);

    fclose(fp);
}

int main() {
    char filename[MAX_FILENAME_LEN];
    int num_books;
    Book *books;

    // Read in the number of books and allocate space for the book array
    printf("How many books do you want to read? ");
    scanf("%d", &num_books);

    books = (Book *)malloc(num_books * sizeof(Book));

    // Read in filenames of books and populate book array
    for (int i = 0; i < num_books; i++) {
        printf("Enter filename for book #%d: ", i+1);
        scanf("%s", filename);
        read_book_from_file(filename, &books[i]);
    }

    // Display the books
    printf("\nHere are the books you requested:\n\n");
    display_books(books, num_books);

    free(books);

    return 0;
}