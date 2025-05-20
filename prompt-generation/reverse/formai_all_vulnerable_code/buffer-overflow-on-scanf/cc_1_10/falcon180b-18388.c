//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 1000
#define MAX_WORDS 5000

typedef struct {
    char title[50];
    char author[50];
    int pages;
    char words[MAX_WORDS][50];
} Book;

int main() {
    int i, j, n;
    char filename[50];
    FILE *fp;
    Book books[MAX_BOOKS];

    printf("Enter the name of the file containing book information: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    n = 0;
    while (fscanf(fp, "%s %s %d", books[n].title, books[n].author, &books[n].pages)!= EOF) {
        for (i = 0; i < books[n].pages; i++) {
            fscanf(fp, "%s", books[n].words[i]);
        }
        n++;
        if (n >= MAX_BOOKS) {
            printf("Error: maximum number of books reached.\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("List of Books:\n");
    for (i = 0; i < n; i++) {
        printf("%s by %s (%d pages)\n", books[i].title, books[i].author, books[i].pages);
        for (j = 0; j < books[i].pages; j++) {
            printf("%s\n", books[i].words[j]);
        }
    }

    return 0;
}