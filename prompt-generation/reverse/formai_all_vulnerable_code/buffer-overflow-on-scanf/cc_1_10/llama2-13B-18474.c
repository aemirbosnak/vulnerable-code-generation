//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOOK_TITLE 50
#define MAX_AUTHOR 50
#define MAX_PAGES 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    char author[MAX_AUTHOR];
    int pages;
} book_t;

book_t current_book;
book_t book_list[10];
int current_page = 0;

void init_books(void);
void add_book(const char* title, const char* author);
void display_book(void);
void next_page(void);
void previous_page(void);

int main(void) {
    init_books();

    while (1) {
        display_book();

        scanf("%d", &current_page);

        if (current_page == -1) {
            break;
        }

        next_page();
    }

    return 0;
}

void init_books(void) {
    int i;

    for (i = 0; i < 10; i++) {
        book_list[i].title[0] = '\0';
        book_list[i].author[0] = '\0';
        book_list[i].pages = 0;
    }

    current_book = book_list[0];
}

void add_book(const char* title, const char* author) {
    int i;

    for (i = 0; i < 10; i++) {
        if (strcmp(book_list[i].title, title) == 0) {
            break;
        }
    }

    if (i == 10) {
        printf("Error: No more space for books.\n");
        return;
    }

    strcpy(book_list[i].title, title);
    strcpy(book_list[i].author, author);
    book_list[i].pages = 0;
}

void display_book(void) {
    printf("Current Book: %s by %s\n", current_book.title, current_book.author);
    printf("Page %d of %d\n", current_page + 1, current_book.pages);
}

void next_page(void) {
    if (current_page < current_book.pages) {
        current_page++;
        display_book();
    } else {
        printf("End of book.\n");
    }
}

void previous_page(void) {
    if (current_page > 0) {
        current_page--;
        display_book();
    } else {
        printf("Start of book.\n");
    }
}