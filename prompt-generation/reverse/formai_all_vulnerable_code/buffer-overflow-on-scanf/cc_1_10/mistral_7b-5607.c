//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 80
#define MAX_BOOKS 10
#define MAX_PAGES 500

typedef struct {
    char title[50];
    char author[50];
    char *pages[MAX_PAGES];
    int page_count;
} Book;

void read_book(Book *book) {
    FILE *fp;
    char line[MAX_LINE];
    int i = 0;

    fp = fopen(book->title, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", book->title);
        return;
    }

    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (i < book->page_count) {
            book->pages[i] = strdup(line);
            i++;
        }
    }

    fclose(fp);
    book->page_count = i;
}

void print_book(Book *book) {
    int i;

    printf("\nTitle: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->page_count);

    for (i = 0; i < book->page_count; i++) {
        printf("\nPage %d:\n%s", i + 1, book->pages[i]);
    }
}

int main() {
    int i, choice;
    Book books[MAX_BOOKS];

    for (i = 0; i < MAX_BOOKS; i++) {
        printf("Enter title of book %d: ", i + 1);
        scanf("%s", books[i].title);

        printf("Enter author of book %d: ", i + 1);
        scanf("%s", books[i].author);

        books[i].page_count = 0;
    }

    for (i = 0; i < MAX_BOOKS; i++) {
        if (books[i].title[0] != '\0') {
            read_book(&books[i]);
        }
    }

    do {
        printf("\nSelect an action:\n1. Read book\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int book_num;

            printf("Enter number of book to read: ");
            scanf("%d", &book_num);

            if (books[book_num - 1].title[0] != '\0') {
                print_book(&books[book_num - 1]);
            } else {
                printf("Error: Book not found.\n");
            }
        }
    } while (choice != 2);

    for (i = 0; i < MAX_BOOKS; i++) {
        if (books[i].title[0] != '\0') {
            for (int j = 0; j < books[i].page_count; j++) {
                free(books[i].pages[j]);
            }
            free(books[i].pages);
        }
    }

    return 0;
}