//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_DESCRIPTION_LENGTH 200
#define MAX_BOOK_PAGES 1000

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
    int pages;
    char *pages_text;
} Book;

void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Description: %s\n", book->description);
    printf("Pages: %d\n", book->pages);
    printf("Pages Text: %s\n", book->pages_text);
}

void read_book(FILE *file, Book *book) {
    fscanf(file, "%s", book->title);
    fscanf(file, "%s", book->author);
    fscanf(file, "%s", book->description);
    fscanf(file, "%d", &book->pages);
    book->pages_text = malloc(book->pages * sizeof(char));
    fgets(book->pages_text, book->pages, file);
}

void write_book(FILE *file, Book *book) {
    fprintf(file, "%s\n", book->title);
    fprintf(file, "%s\n", book->author);
    fprintf(file, "%s\n", book->description);
    fprintf(file, "%d\n", book->pages);
    fprintf(file, "%s", book->pages_text);
}

int main() {
    FILE *file;
    Book books[MAX_BOOKS];
    int num_books = 0;

    file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: could not open books.txt\n");
        return 1;
    }

    while (num_books < MAX_BOOKS && fscanf(file, "%s", books[num_books].title)!= EOF) {
        read_book(file, &books[num_books]);
        num_books++;
    }

    fclose(file);

    file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Error: could not open books.txt\n");
        return 1;
    }

    for (int i = 0; i < num_books; i++) {
        write_book(file, &books[i]);
    }

    fclose(file);

    return 0;
}