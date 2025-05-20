//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_PAGES 1000
#define MAX_CHARS_PER_PAGE 5000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
    char content[MAX_BOOKS][MAX_PAGES][MAX_CHARS_PER_PAGE];
} Book;

int main() {
    Book library[MAX_BOOKS];
    int numBooks = 0;

    printf("Welcome to the Ebook Reader!\n");

    while (numBooks < MAX_BOOKS) {
        printf("Enter the title of the book (or type 'done' to finish):\n");
        scanf("%s", library[numBooks].title);

        if (strcmp(library[numBooks].title, "done") == 0) {
            break;
        }

        printf("Enter the author of the book:\n");
        scanf("%s", library[numBooks].author);

        printf("Enter the number of pages in the book:\n");
        scanf("%d", &library[numBooks].pages);

        printf("Enter the content of the book (press enter after each line):\n");
        for (int i = 0; i < library[numBooks].pages; i++) {
            char line[MAX_CHARS_PER_PAGE];
            scanf("%[^\n]", line);
            strcpy(library[numBooks].content[i], line);
        }

        numBooks++;
    }

    printf("\nYour library contains the following books:\n");

    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Pages: %d\n", library[i].pages);
        printf("\n");

        for (int j = 0; j < library[i].pages; j++) {
            printf("%s\n", library[i].content[j]);
        }

        printf("\n");
    }

    return 0;
}