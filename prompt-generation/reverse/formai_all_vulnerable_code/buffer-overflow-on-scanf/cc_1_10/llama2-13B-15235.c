//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BOOK_TITLE 20
#define MAX_AUTHOR 20
#define MAX_PAGES 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    char author[MAX_AUTHOR];
    int pages;
} book_t;

book_t books[5];

void add_book(book_t *book) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strcmp(books[i].title, book->title) > 0) {
            break;
        }
    }
    books[i] = *book;
}

void list_books() {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%s, by %s, %d pages\n", books[i].title, books[i].author, books[i].pages);
    }
}

void set_book_pages(int page) {
    int i;
    for (i = 0; i < 5; i++) {
        if (books[i].pages == page) {
            books[i].pages = page;
            break;
        }
    }
}

int main() {
    book_t book;
    char command;

    while (1) {
        printf("Welcome to the Ebook Reader!\n");
        printf("Enter a command: ");
        scanf(" %c", &command);

        if (command == 'a') {
            printf("Add a new book: ");
            scanf("%19s %19s %d", book.title, book.author, &book.pages);
            add_book(&book);
        } else if (command == 'l') {
            list_books();
        } else if (command == 'p') {
            set_book_pages(atoi(book.title));
        } else {
            printf("Invalid command. Try again!\n");
        }
    }

    return 0;
}