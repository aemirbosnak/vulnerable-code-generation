//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_DESCRIPTION_LENGTH 200
#define MAX_NUM_BOOKS 10

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
} Book;

int main() {
    int numBooks = 0;
    Book books[MAX_NUM_BOOKS];

    char filename[50] = "books.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s %s %s\n", books[numBooks].title, books[numBooks].author, books[numBooks].description)!= EOF) {
        numBooks++;
        if (numBooks >= MAX_NUM_BOOKS) {
            printf("Error: too many books in file.\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("Welcome to the Ebook Reader!\n");
    printf("Please select a book:\n");

    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s\n%s\n", i+1, books[i].title, books[i].author, books[i].description);
    }

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > numBooks) {
        printf("Invalid selection.\n");
        exit(1);
    }

    printf("You have selected %s by %s.\n\n", books[choice-1].title, books[choice-1].author);
    printf("%s\n", books[choice-1].description);

    return 0;
}