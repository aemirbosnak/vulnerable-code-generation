//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_GENRE_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    int pages;
    int year;
} Book;

void addBook(Book books[], int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter author name: ");
    scanf("%s", books[numBooks].author);

    printf("Enter genre: ");
    scanf("%s", books[numBooks].genre);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    printf("Enter publication year: ");
    scanf("%d", &books[numBooks].year);

    numBooks++;
}

void displayBooks(Book books[], int numBooks) {
    printf("Book Title\tAuthor\tGenre\tPages\tYear\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s\t%s\t%s\t%d\t%d\n", books[i].title, books[i].author, books[i].genre, books[i].pages, books[i].year);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    addBook(books, numBooks);

    while (1) {
        displayBooks(books, numBooks);

        printf("\nDo you want to add another book? (y/n)\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }

        addBook(books, numBooks);
    }

    return 0;
}