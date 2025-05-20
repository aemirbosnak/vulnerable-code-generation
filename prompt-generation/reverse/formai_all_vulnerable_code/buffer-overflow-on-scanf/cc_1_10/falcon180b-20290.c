//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100
#define MAX_BOOK_DESCRIPTION_LENGTH 1000

typedef struct {
    char book_name[MAX_BOOK_NAME_LENGTH];
    char book_author[MAX_BOOK_AUTHOR_LENGTH];
    char book_description[MAX_BOOK_DESCRIPTION_LENGTH];
    int book_pages;
    int book_chapters;
} Book;

int main() {
    int i;
    char filename[100];
    FILE *fp;
    Book books[MAX_BOOKS];
    int num_books = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %d %d", books[num_books].book_name,
                  books[num_books].book_author, books[num_books].book_description,
                  &books[num_books].book_pages, &books[num_books].book_chapters)!= EOF) {
        num_books++;
    }

    fclose(fp);

    printf("Book List:\n");

    for (i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n%s\n", i+1, books[i].book_name, books[i].book_author, books[i].book_description);
    }

    return 0;
}