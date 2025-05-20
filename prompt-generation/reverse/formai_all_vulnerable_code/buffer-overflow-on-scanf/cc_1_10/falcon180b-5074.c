//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BOOKS 1000
#define MAX_NAME_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_ISBN_LEN 20
#define MAX_YEAR_LEN 4

typedef struct {
    char title[MAX_NAME_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    char isbn[MAX_ISBN_LEN];
    int year;
} Book;

typedef struct {
    int numBooks;
    Book books[MAX_BOOKS];
} Library;

void initLibrary(Library *lib) {
    lib->numBooks = 0;
}

void addBook(Library *lib, Book book) {
    if (lib->numBooks >= MAX_BOOKS) {
        printf("Error: Library is full.\n");
        return;
    }
    lib->books[lib->numBooks++] = book;
}

void printBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Genre: %s\n", book.genre);
    printf("ISBN: %s\n", book.isbn);
    printf("Year: %d\n", book.year);
}

void printLibrary(Library lib) {
    printf("Library:\n");
    for (int i = 0; i < lib.numBooks; i++) {
        printBook(lib.books[i]);
    }
}

int main() {
    Library lib;
    initLibrary(&lib);

    int choice;
    while (true) {
        printf("1. Add book\n");
        printf("2. Print library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Book book;
            printf("Enter book details:\n");
            printf("Title: ");
            scanf(" %[^\n]", book.title);
            printf("Author: ");
            scanf(" %[^\n]", book.author);
            printf("Genre: ");
            scanf(" %[^\n]", book.genre);
            printf("ISBN: ");
            scanf(" %[^\n]", book.isbn);
            printf("Year: ");
            scanf("%d", &book.year);
            addBook(&lib, book);
            break;
        }
        case 2: {
            printLibrary(lib);
            break;
        }
        case 3: {
            return 0;
        }
        default: {
            printf("Invalid choice.\n");
        }
        }
    }

    return 0;
}