//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_GENRE_LEN 50
#define MAX_ISBN_LEN 20

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char genre[MAX_GENRE_LEN];
    char isbn[MAX_ISBN_LEN];
    int pages;
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter author name: ");
    scanf("%s", books[numBooks].author);

    printf("Enter genre: ");
    scanf("%s", books[numBooks].genre);

    printf("Enter ISBN: ");
    scanf("%s", books[numBooks].isbn);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
}

void displayBooks(Book* books, int numBooks) {
    printf("Book Title\tAuthor\tGenre\tISBN\tPages\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s\t%s\t%s\t%s\t%d\n", books[i].title, books[i].author, books[i].genre, books[i].isbn, books[i].pages);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    while (numBooks < MAX_BOOKS) {
        printf("Do you want to add a book? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            addBook(books, numBooks);
            numBooks++;
        } else {
            break;
        }
    }

    displayBooks(books, numBooks);

    return 0;
}