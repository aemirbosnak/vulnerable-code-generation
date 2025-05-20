//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int pages;
} Book;

int main() {
    int numBooks;
    char filename[50];
    FILE *fp;
    Book books[MAX_BOOKS];

    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %d", books[i].title, books[i].author, &books[i].pages)!= EOF) {
        i++;
    }

    fclose(fp);

    printf("Number of books: %d\n", numBooks);
    printf("Book titles, authors, and pages:\n");

    for (i = 0; i < numBooks; i++) {
        printf("%s by %s (%d pages)\n", books[i].title, books[i].author, books[i].pages);
    }

    return 0;
}