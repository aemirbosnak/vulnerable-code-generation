//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
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
    int num_books = 0;

    FILE *f = fopen("books.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_TITLE_LENGTH + MAX_AUTHOR_LENGTH + 10];
    while (fgets(line, sizeof(line), f)!= NULL) {
        char *title = strtok(line, ":");
        char *author = strtok(NULL, ":");
        int pages = atoi(strtok(NULL, ":"));

        if (num_books >= MAX_BOOKS) {
            printf("Too many books.\n");
            return 2;
        }

        strncpy(books[num_books].title, title, MAX_TITLE_LENGTH);
        strncpy(books[num_books].author, author, MAX_AUTHOR_LENGTH);
        books[num_books].pages = pages;

        num_books++;
    }

    fclose(f);

    printf("Number of books: %d\n", num_books);

    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].title, books[i].author, books[i].pages);
    }

    return 0;
}