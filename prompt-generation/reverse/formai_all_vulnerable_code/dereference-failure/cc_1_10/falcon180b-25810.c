//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *title = strtok(line, ",");
        char *author = strtok(NULL, ",");
        int pages = atoi(strtok(NULL, ","));

        strncpy(books[numBooks].title, title, MAX_TITLE_LENGTH);
        strncpy(books[numBooks].author, author, MAX_AUTHOR_LENGTH);
        books[numBooks].pages = pages;

        numBooks++;
    }

    fclose(file);

    printf("Number of books: %d\n", numBooks);

    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("\n");
    }

    return 0;
}