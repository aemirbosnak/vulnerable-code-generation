//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} book;

void addBook(book* books, int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
}

void displayBook(book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
}

int main() {
    book books[MAX_BOOKS];
    int numBooks = 0;

    while(numBooks < MAX_BOOKS) {
        printf("Do you want to add a book? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if(choice == 'y') {
            addBook(books, numBooks);
            numBooks++;
        } else {
            break;
        }
    }

    printf("Your library contains %d books:\n", numBooks);

    for(int i = 0; i < numBooks; i++) {
        displayBook(books[i]);
    }

    return 0;
}