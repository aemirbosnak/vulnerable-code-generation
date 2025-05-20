#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[100];
    int pages;
    char genre[50];
} Book;

void readBooksFromFile(Book books[], int *numBooks, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    while (*numBooks < MAX_BOOKS && fscanf(file, "%s %s %d %s", books[*numBooks].title, books[*numBooks].author, &books[*numBooks].pages, books[*numBooks].genre) != EOF) {
        (*numBooks)++;
    }
    fclose(file);
}

void searchBookByTitle(const Book books[], int numBooks, const char *searchTitle) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Title: %s\nAuthor: %s\nPages: %d\nGenre: %s\n", books[i].title, books[i].author, books[i].pages, books[i].genre);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;
    const char *filename = "books.txt";

    readBooksFromFile(books, &numBooks, filename);

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    searchBookByTitle(books, numBooks, searchTitle);

    return 0;
}
