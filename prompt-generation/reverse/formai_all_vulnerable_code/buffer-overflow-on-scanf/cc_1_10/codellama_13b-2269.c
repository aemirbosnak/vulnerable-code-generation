//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: complete
/*
 * ebook_reader.c
 *
 * A simple ebook reader program in C.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
    int read_pages;
} book_t;

void print_menu(void);
void add_book(book_t books[], int *num_books);
void remove_book(book_t books[], int *num_books);
void read_book(book_t books[], int *num_books);

int main(void) {
    book_t books[MAX_BOOKS];
    int num_books = 0;
    char input;

    print_menu();

    while (1) {
        printf("Enter your choice: ");
        scanf("%c", &input);

        switch (input) {
            case 'a':
                add_book(books, &num_books);
                break;
            case 'r':
                remove_book(books, &num_books);
                break;
            case 'p':
                read_book(books, &num_books);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}

void print_menu(void) {
    printf("Ebook Reader Menu\n");
    printf("-----------------\n");
    printf("a) Add a new book\n");
    printf("r) Remove a book\n");
    printf("p) Read a book\n");
    printf("q) Quit\n");
}

void add_book(book_t books[], int *num_books) {
    if (*num_books >= MAX_BOOKS) {
        printf("Cannot add any more books\n");
        return;
    }

    printf("Enter the title: ");
    scanf("%s", books[*num_books].title);
    printf("Enter the author: ");
    scanf("%s", books[*num_books].author);
    printf("Enter the number of pages: ");
    scanf("%d", &books[*num_books].pages);

    books[*num_books].read_pages = 0;

    (*num_books)++;
}

void remove_book(book_t books[], int *num_books) {
    if (*num_books <= 0) {
        printf("No books to remove\n");
        return;
    }

    int index;
    printf("Enter the index of the book to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_books) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *num_books - 1; i++) {
        books[i] = books[i + 1];
    }

    (*num_books)--;
}

void read_book(book_t books[], int *num_books) {
    if (*num_books <= 0) {
        printf("No books to read\n");
        return;
    }

    int index;
    printf("Enter the index of the book to read: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_books) {
        printf("Invalid index\n");
        return;
    }

    books[index].read_pages++;
    printf("You have read %d pages of the book\n", books[index].read_pages);
}