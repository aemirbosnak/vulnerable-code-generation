//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 1000
#define MAX_WORDS 10000

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char pages[MAX_PAGES][MAX_WORDS];
} Book;

void load_book(Book *book) {
    printf("Enter book title: ");
    scanf("%s", book->title);

    printf("Enter book author: ");
    scanf("%s", book->author);

    printf("Enter number of pages: ");
    scanf("%d", &book->num_pages);

    for (int i = 0; i < book->num_pages; i++) {
        printf("Enter page %d content:\n", i+1);
        scanf("%s", book->pages[i]);
    }
}

void display_book(Book *book) {
    printf("Book Title: %s\n", book->title);
    printf("Book Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->num_pages);

    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s\n", i+1, book->pages[i]);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("Enter book information:\n");
        load_book(&books[num_books]);
        num_books++;
    }

    while (1) {
        printf("Enter book number to display: ");
        int book_num;
        scanf("%d", &book_num);

        if (book_num >= 0 && book_num < num_books) {
            display_book(&books[book_num]);
        } else {
            printf("Invalid book number.\n");
        }
    }

    return 0;
}