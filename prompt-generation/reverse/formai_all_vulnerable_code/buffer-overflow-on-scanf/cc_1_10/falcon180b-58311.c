//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME 100
#define MAX_BOOK_AUTHOR 100
#define MAX_BOOK_PUBLISHER 100
#define MAX_BOOK_GENRE 100
#define MAX_BOOK_ISBN 20

typedef struct {
    char name[MAX_BOOK_NAME];
    char author[MAX_BOOK_AUTHOR];
    char publisher[MAX_BOOK_PUBLISHER];
    char genre[MAX_BOOK_GENRE];
    char isbn[MAX_BOOK_ISBN];
    int pages;
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter book name: ");
    scanf("%s", books[numBooks].name);
    printf("Enter author name: ");
    scanf("%s", books[numBooks].author);
    printf("Enter publisher name: ");
    scanf("%s", books[numBooks].publisher);
    printf("Enter genre: ");
    scanf("%s", books[numBooks].genre);
    printf("Enter ISBN: ");
    scanf("%s", books[numBooks].isbn);
    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
    numBooks++;
}

void searchBook(Book* books, int numBooks, char* isbn) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            printf("Book found:\n");
            printf("Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);
            printf("Publisher: %s\n", books[i].publisher);
            printf("Genre: %s\n", books[i].genre);
            printf("ISBN: %s\n", books[i].isbn);
            printf("Pages: %d\n", books[i].pages);
        }
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    printf("Enter number of books: ");
    scanf("%d", &numBooks);

    for (int i = 0; i < numBooks; i++) {
        addBook(books, i);
    }

    char searchIsbn[MAX_BOOK_ISBN];
    printf("Enter ISBN to search: ");
    scanf("%s", searchIsbn);

    searchBook(books, numBooks, searchIsbn);

    return 0;
}