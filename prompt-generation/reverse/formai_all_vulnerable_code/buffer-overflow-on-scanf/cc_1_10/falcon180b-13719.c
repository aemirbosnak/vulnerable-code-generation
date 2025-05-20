//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_TITLE_LEN 100
#define MAX_BOOK_AUTHOR_LEN 100
#define MAX_BOOK_CONTENT_LEN 1000000

typedef struct {
    char title[MAX_BOOK_TITLE_LEN];
    char author[MAX_BOOK_AUTHOR_LEN];
    char content[MAX_BOOK_CONTENT_LEN];
} Book;

int num_books = 0;
Book books[MAX_BOOKS];

void add_book(Book* book) {
    if (num_books >= MAX_BOOKS) {
        printf("Maximum number of books reached!\n");
        return;
    }

    strcpy(book->title, "");
    strcpy(book->author, "");
    strcpy(book->content, "");

    num_books++;
}

void remove_book(int index) {
    if (index < 0 || index >= num_books) {
        printf("Invalid book index!\n");
        return;
    }

    num_books--;
}

void read_book(int index) {
    if (index < 0 || index >= num_books) {
        printf("Invalid book index!\n");
        return;
    }

    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Content:\n%s", books[index].content);
}

void write_book(int index) {
    if (index < 0 || index >= num_books) {
        printf("Invalid book index!\n");
        return;
    }

    printf("Enter new title: ");
    scanf("%s", books[index].title);

    printf("Enter new author: ");
    scanf("%s", books[index].author);

    printf("Enter new content:\n");
    fgets(books[index].content, MAX_BOOK_CONTENT_LEN, stdin);
}

int main() {
    add_book(&books[0]);
    add_book(&books[1]);

    read_book(0);
    read_book(1);

    write_book(0);
    write_book(1);

    remove_book(1);

    read_book(0);
    read_book(1);

    return 0;
}