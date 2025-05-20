//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOK_LENGTH 10000
#define MAX_PAGES 50

typedef struct {
    char title[50];
    char author[50];
    char chapter[100];
} book_t;

book_t current_book;
int current_page = 0;
int page_count = 0;

void init_book(book_t *book, char *title, char *author) {
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->chapter[0] = '\0';
}

void turn_page() {
    if (current_page < page_count) {
        current_page++;
        printf("Page %d of %d\n", current_page, page_count);
    } else {
        current_page = 0;
        printf("Back to the beginning\n");
    }
}

void display_book() {
    printf("Current book: %s by %s\n", current_book.title, current_book.author);
    printf("Current chapter: %s\n", current_book.chapter);
}

int main() {
    book_t books[] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Chapter 1: In the town of West Egg"},
        {"Pride and Prejudice", "Jane Austen", "Chapter 1: The Bennet family"},
        {"To Kill a Mockingbird", "Harper Lee", "Chapter 1: Scout Finch's childhood"}
    };

    int chosen_book = 0;

    do {
        printf("Select a book by number: ");
        scanf("%d", &chosen_book);

        if (chosen_book < 0 || chosen_book >= sizeof(books) / sizeof(books[0])) {
            printf("Invalid selection. Try again.\n");
        } else {
            init_book(&books[chosen_book], books[chosen_book].title, books[chosen_book].author);
            break;
        }
    } while (1);

    while (1) {
        display_book();
        turn_page();
    }

    return 0;
}