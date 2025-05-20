//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_ISBN_LEN 20

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    int num_pages;
    int num_chapters;
} Book;

void add_book(Book* books, int num_books) {
    if (num_books == MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[num_books].title);

    printf("Enter book author: ");
    scanf("%s", books[num_books].author);

    printf("Enter book ISBN: ");
    scanf("%s", books[num_books].isbn);

    printf("Enter number of pages: ");
    scanf("%d", &books[num_books].num_pages);

    printf("Enter number of chapters: ");
    scanf("%d", &books[num_books].num_chapters);

    num_books++;
}

void display_books(Book* books, int num_books) {
    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %s\n", books[i].isbn);
        printf("Number of pages: %d\n", books[i].num_pages);
        printf("Number of chapters: %d\n", books[i].num_chapters);
        printf("\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (1) {
        printf("\n1. Add book\n2. Display books\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_book(books, num_books);
            break;
        case 2:
            display_books(books, num_books);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}