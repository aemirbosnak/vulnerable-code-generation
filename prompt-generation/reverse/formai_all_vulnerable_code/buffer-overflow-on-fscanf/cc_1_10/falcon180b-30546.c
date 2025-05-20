//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

void read_books(Book books[], int num_books) {
    FILE *file;
    char filename[20];
    int i;

    for (i = 0; i < num_books; i++) {
        sprintf(filename, "book%d.txt", i + 1);
        file = fopen(filename, "r");

        if (file == NULL) {
            printf("Error opening file: %s\n", filename);
            exit(1);
        }

        fscanf(file, "%s", books[i].title);
        fscanf(file, "%s", books[i].author);
        fscanf(file, "%d", &books[i].pages);

        fclose(file);
    }
}

void display_books(Book books[], int num_books) {
    int i;

    for (i = 0; i < num_books; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n\n", books[i].pages);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books;

    printf("Enter the number of books (up to %d): ", MAX_BOOKS);
    scanf("%d", &num_books);

    if (num_books > MAX_BOOKS) {
        printf("Error: too many books.\n");
        return 1;
    }

    read_books(books, num_books);
    display_books(books, num_books);

    return 0;
}