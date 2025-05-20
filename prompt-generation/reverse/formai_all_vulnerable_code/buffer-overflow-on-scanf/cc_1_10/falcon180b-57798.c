//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    int numBooks;
    Book library[MAX_BOOKS];

    // Initialize library
    for (int i = 0; i < MAX_BOOKS; i++) {
        library[i].title[0] = '\0';
        library[i].author[0] = '\0';
        library[i].pages = 0;
    }

    numBooks = 0;

    // Add books to library
    while (numBooks < MAX_BOOKS) {
        printf("Enter book title (up to %d characters):\n", MAX_TITLE_LENGTH - 1);
        scanf("%s", library[numBooks].title);

        printf("Enter book author (up to %d characters):\n", MAX_AUTHOR_LENGTH - 1);
        scanf("%s", library[numBooks].author);

        printf("Enter number of pages:\n");
        scanf("%d", &library[numBooks].pages);

        numBooks++;
    }

    // Display library contents
    printf("\nLibrary contents:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s by %s (%d pages)\n", library[i].title, library[i].author, library[i].pages);
    }

    return 0;
}