#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int pages;
    char genre[50];
};

int main() {
    struct Book books[MAX_BOOKS];
    int numBooks = 0;

    // Read book data from file
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        return 1;
    }

    // Allocate memory for each book
    while (fscanf(fp, "%s %s %d %s", books[numBooks].title, books[numBooks].author, &books[numBooks].pages, books[numBooks].genre) != EOF) {
        numBooks++;
    }

    fclose(fp);

    // Search for book by title
    char searchTitle[50];
    printf("Enter book title: ");
    scanf("%s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            printf("Genre: %s\n", books[i].genre);
        }
    }

    if (!found) {
        printf("No book found.\n");
    }

    return 0;
}
