//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_BOOK_LENGTH 100000

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char content[MAX_BOOK_LENGTH];
    int num_pages;
} Book;

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Book book;

    printf("Enter the name of the e-book file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fgets(line, MAX_LINE_LENGTH, fp);
    strcpy(book.title, line);

    fgets(line, MAX_LINE_LENGTH, fp);
    strcpy(book.author, line);

    book.num_pages = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        strcat(book.content, line);
        book.num_pages++;
    }

    fclose(fp);

    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of pages: %d\n", book.num_pages);

    printf("\nPress any key to exit.\n");
    getchar();

    return 0;
}