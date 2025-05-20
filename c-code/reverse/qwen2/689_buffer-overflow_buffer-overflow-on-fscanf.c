#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 256
#define MAX_AUTHOR_LENGTH 256
#define MAX_GENRE_LENGTH 128

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char genre[MAX_GENRE_LENGTH];
} Book;

void readBooks(Book books[], int *numBooks, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }
    while (*numBooks < MAX_BOOKS && fscanf(file, "%s %s %d %s", books[*numBooks].title, books[*numBooks].author, &books[*numBooks].pages, books[*numBooks].genre) != EOF) {
        (*numBooks)++;
    }
    fclose(file);
}

int searchBook(const Book books[], int numBooks, const char *query) {
    for (int i = 0; i < numBooks; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
            return i;
        }
    }
    return -1;
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;
    const char *filename = "library.txt";

    readBooks(books, &numBooks, filename);

    char query[256];
    printf("Enter search query: ");
    scanf("%s", query);

    int index = searchBook(books, numBooks, query);
    if (index != -1) {
        printf("Found book:\nTitle: %s\nAuthor: %s\nPages: %d\nGenre: %s\n", books[index].title, books[index].author, books[index].pages, books[index].genre);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}
