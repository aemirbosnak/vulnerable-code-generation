//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_PAGES 1000
#define MAX_SUMMARY_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    int pages;
    char summary[MAX_SUMMARY_LEN];
} Book;

void addBook(Book *books, int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);

    printf("Enter book genre: ");
    scanf("%s", books[numBooks].genre);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    printf("Enter book summary: ");
    scanf("%s", books[numBooks].summary);
}

void displayBook(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Pages: %d\n", book->pages);
    printf("Summary: %s\n", book->summary);
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    while (numBooks < MAX_BOOKS) {
        printf("Enter 1 to add a book or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addBook(books, numBooks);
            numBooks++;
        } else {
            break;
        }
    }

    printf("Displaying books:\n");
    for (int i = 0; i < numBooks; i++) {
        displayBook(&books[i]);
    }

    return 0;
}