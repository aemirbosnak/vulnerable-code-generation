//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOK_NAME_LEN 50
#define MAX_AUTHOR_NAME_LEN 30
#define MAX_PAGES 500

typedef struct {
    char book_name[MAX_BOOK_NAME_LEN];
    char author_name[MAX_AUTHOR_NAME_LEN];
    int pages;
} book_info_t;

book_info_t current_book;

void init_book_info(void) {
    current_book.book_name[0] = '\0';
    current_book.author_name[0] = '\0';
    current_book.pages = 0;
}

void set_book_info(const char* book_name, const char* author_name, int pages) {
    strcpy(current_book.book_name, book_name);
    strcpy(current_book.author_name, author_name);
    current_book.pages = pages;
}

void display_book_info(void) {
    printf("Current Book:\n");
    printf("  Book Name: %s\n", current_book.book_name);
    printf("  Author Name: %s\n", current_book.author_name);
    printf("  Pages: %d\n", current_book.pages);
}

void turn_page(int page) {
    if (page < 1 || page > current_book.pages) {
        printf("Invalid page number. Please enter a page number between 1 and %d.\n", current_book.pages);
        return;
    }

    if (page == current_book.pages) {
        printf("You have reached the end of the book. Would you like to start again? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            init_book_info();
        } else {
            exit(0);
        }
    } else {
        current_book.pages = page;
        display_book_info();
    }
}

int main(void) {
    init_book_info();

    while (1) {
        printf("What is the name of the book you would like to read? ");
        char book_name[MAX_BOOK_NAME_LEN];
        scanf(" %s", book_name);
        set_book_info(book_name, NULL, 0);

        printf("What is the author's name? ");
        char author_name[MAX_AUTHOR_NAME_LEN];
        scanf(" %s", author_name);
        set_book_info(book_name, author_name, 0);

        printf("How many pages does this book have? ");
        int pages;
        scanf(" %d", &pages);
        set_book_info(book_name, author_name, pages);

        display_book_info();

        printf("Do you want to turn the page (y/n)? ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            turn_page(1);
        } else {
            break;
        }
    }

    return 0;
}