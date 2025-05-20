//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 10
#define MAX_LINES 50
#define MAX_CHARS 100

typedef struct {
    char title[MAX_CHARS];
    FILE *file;
    int lines;
} Book;

void load_book(Book *book, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    fgets(book->title, MAX_CHARS, fp);
    book->lines = 0;

    char line[MAX_LINES][MAX_CHARS];
    while (fgets(line[0], MAX_LINES, fp) != NULL) {
        book->lines++;
    }
    rewind(fp);

    book->file = fp;
}

int main() {
    Book books[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        printf("Enter title for book %d: ", i + 1);
        scanf("%s", books[i].title);

        if (strlen(books[i].title) > 0) {
            char filename[MAX_CHARS];
            printf("Enter file name for book %s: ", books[i].title);
            scanf("%s", filename);

            load_book(&books[i], filename);
        }
    }

    for (int i = 0; i < MAX_BOOKS; i++) {
        if (books[i].file != NULL) {
            printf("\n%s\n", books[i].title);
            int line_num = 1;

            char line[MAX_LINES][MAX_CHARS];
            while (fgets(line[0], MAX_LINES, books[i].file) != NULL) {
                printf("%d. %s", line_num++, line[0]);
            }

            fclose(books[i].file);
        }
    }

    return 0;
}