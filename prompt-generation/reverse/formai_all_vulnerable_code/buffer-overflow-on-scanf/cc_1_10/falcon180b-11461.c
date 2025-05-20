//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOKS 10
#define MAX_PAGES 100
#define MAX_LINES 50

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char pages[MAX_PAGES][MAX_LINES];
} Book;

void read_book(char *filename, Book *book) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINES];
    int page_num = 0;

    while (fgets(line, MAX_LINES, fp)!= NULL) {
        strcat(book->pages[page_num], line);
        page_num++;
    }

    book->num_pages = page_num;
    fclose(fp);
}

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;

    while (true) {
        printf("Enter a book title: ");
        scanf("%s", library[num_books].title);

        printf("Enter the author: ");
        scanf("%s", library[num_books].author);

        read_book(library[num_books].title, &library[num_books]);

        num_books++;

        char choice;
        printf("Do you want to add another book? (y/n): ");
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    while (true) {
        printf("Enter a book title to read: ");
        scanf("%s", library[num_books-1].title);

        int page_num = 0;
        while (page_num < library[num_books-1].num_pages) {
            printf("\nPage %d:\n%s", page_num+1, library[num_books-1].pages[page_num]);
            page_num++;
        }

        char choice;
        printf("Do you want to read another book? (y/n): ");
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    return 0;
}