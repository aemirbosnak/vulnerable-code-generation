//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

#define MAX_PAGES 1000
#define MAX_BOOK_SIZE 1024*1024*10

typedef struct {
    char *title;
    char *author;
    char *book_path;
    size_t page_count;
    size_t current_page;
} book_t;

book_t books[5];

void init_books(void) {
    books[0].title = "The Great Gatsby";
    books[0].author = "F. Scott Fitzgerald";
    books[0].book_path = "/path/to/gatsby.txt";
    books[0].page_count = 200;
    books[0].current_page = 0;

    books[1].title = "To Kill a Mockingbird";
    books[1].author = "Harper Lee";
    books[1].book_path = "/path/to/mockingbird.txt";
    books[1].page_count = 300;
    books[1].current_page = 0;

    books[2].title = "The Catcher in the Rye";
    books[2].author = "J.D. Salinger";
    books[2].book_path = "/path/to/catcher.txt";
    books[2].page_count = 250;
    books[2].current_page = 0;

    books[3].title = "The Hitchhiker's Guide to the Galaxy";
    books[3].author = "Douglas Adams";
    books[3].book_path = "/path/to/hitchhiker.txt";
    books[3].page_count = 400;
    books[3].current_page = 0;

    books[4].title = "The Lord of the Rings";
    books[4].author = "J.R.R. Tolkien";
    books[4].book_path = "/path/to/lord.txt";
    books[4].page_count = 1000;
    books[4].current_page = 0;
}

void display_book(book_t *book) {
    printf("Book: %s by %s\n", book->title, book->author);
    printf("Current Page: %d of %d\n", book->current_page, book->page_count);
}

void turn_page(book_t *book) {
    if (book->current_page < book->page_count - 1) {
        book->current_page++;
        display_book(book);
    }
}

int main(void) {
    init_books();

    while (1) {
        printf("Select a book (1-4): ");
        int book_num = scanf("%d", &book_num);

        if (book_num < 1 || book_num > 4) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        book_t *book = &books[book_num - 1];
        display_book(book);

        printf("Turn the page? (y/n): ");
        char c = getchar();

        if (c == 'y' || c == 'Y') {
            turn_page(book);
        } else {
            break;
        }
    }

    return 0;
}