//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_PAGE_COUNT 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int page_count;
} book_t;

void add_book(book_t *books, int num_books) {
    printf("Enter book title: ");
    scanf("%s", books[num_books].title);
    printf("Enter author name: ");
    scanf("%s", books[num_books].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[num_books].page_count);
}

void print_book(book_t *books, int num_books) {
    printf("%d. %s by %s (%d pages)\n", num_books+1, books[num_books].title, books[num_books].author, books[num_books].page_count);
}

void read_books(book_t *books, int num_books) {
    for (int i = 0; i < num_books; i++) {
        print_book(books, i);
    }
}

int main() {
    book_t books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("Enter 1 to add a book, 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add_book(books, num_books);
            num_books++;
        } else if (choice!= 0) {
            printf("Invalid choice\n");
        }
    }

    read_books(books, num_books);
    return 0;
}