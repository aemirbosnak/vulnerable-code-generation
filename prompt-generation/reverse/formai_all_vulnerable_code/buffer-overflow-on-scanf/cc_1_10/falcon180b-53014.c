//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char title[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_NAME_LENGTH];
    char content[MAX_BOOK_NAME_LENGTH];
} Book;

int main() {
    int numBooks;
    Book books[MAX_BOOKS];
    char filename[MAX_BOOK_NAME_LENGTH];
    FILE *fp;
    int i = 0;
    char line[MAX_LINE_LENGTH];

    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i >= numBooks) {
            printf("Error: Max number of books reached.\n");
            exit(1);
        }

        strcpy(books[i].title, line);
        i++;

        if (i == numBooks) {
            break;
        }
    }

    fclose(fp);

    printf("List of books:\n");

    for (int j = 0; j < i; j++) {
        printf("%s\n", books[j].title);
    }

    return 0;
}