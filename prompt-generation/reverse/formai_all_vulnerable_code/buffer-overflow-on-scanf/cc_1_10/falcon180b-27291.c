//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_GENRE_LENGTH 20
#define MAX_ISBN_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
} Book;

void addBook(Book* bookshelf, int numBooks) {
    if (numBooks >= MAX_BOOKS) {
        printf("Sorry, bookshelf is full.\n");
        return;
    }
    printf("Enter book title: ");
    scanf("%s", bookshelf[numBooks].title);
    printf("Enter author name: ");
    scanf("%s", bookshelf[numBooks].author);
    printf("Enter book genre: ");
    scanf("%s", bookshelf[numBooks].genre);
    printf("Enter ISBN: ");
    scanf("%s", bookshelf[numBooks].isbn);
    printf("Book added successfully.\n");
}

void displayBooks(Book* bookshelf, int numBooks) {
    printf("Books on the shelf:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i+1);
        printf("Title: %s\n", bookshelf[i].title);
        printf("Author: %s\n", bookshelf[i].author);
        printf("Genre: %s\n", bookshelf[i].genre);
        printf("ISBN: %s\n\n", bookshelf[i].isbn);
    }
}

int main() {
    Book bookshelf[MAX_BOOKS];
    int numBooks = 0;
    char choice;
    do {
        printf("1. Add book\n2. Display books\n3. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                addBook(bookshelf, numBooks);
                break;
            case '2':
                displayBooks(bookshelf, numBooks);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
    return 0;
}