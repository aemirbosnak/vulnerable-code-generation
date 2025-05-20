//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
}

void displayBooks(Book* books, int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n\n", books[i].pages);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    while (numBooks < MAX_BOOKS) {
        printf("\nDo you want to add a book? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            numBooks++;
            addBook(books, numBooks - 1);
        } else {
            break;
        }
    }

    printf("\nYour ebook library:\n");
    displayBooks(books, numBooks);

    return 0;
}