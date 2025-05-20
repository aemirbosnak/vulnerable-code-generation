//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_DESCRIPTION_LENGTH 200
#define MAX_NUM_BOOKS 100

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
} Book;

void readBooks(Book books[], int numBooks) {
    FILE *fp;
    char filename[20];
    int i;

    for (i = 0; i < numBooks; i++) {
        sprintf(filename, "book%d.txt", i + 1);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            fprintf(stderr, "Error: could not open file %s\n", filename);
            exit(1);
        }
        fscanf(fp, "%s %s %s", books[i].name, books[i].author, books[i].description);
        fclose(fp);
    }
}

void displayBooks(Book books[], int numBooks) {
    int i;

    for (i = 0; i < numBooks; i++) {
        printf("Name: %s\n", books[i].name);
        printf("Author: %s\n", books[i].author);
        printf("Description: %s\n\n", books[i].description);
    }
}

int main() {
    Book books[MAX_NUM_BOOKS];
    int numBooks;

    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    if (numBooks > MAX_NUM_BOOKS) {
        fprintf(stderr, "Error: too many books\n");
        exit(1);
    }

    readBooks(books, numBooks);
    displayBooks(books, numBooks);

    return 0;
}