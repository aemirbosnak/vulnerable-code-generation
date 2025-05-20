//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 100
#define MAX_BOOK_GENRE_LENGTH 50

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char genre[MAX_BOOK_GENRE_LENGTH];
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter book name: ");
    scanf("%s", books[numBooks].name);
    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter book genre: ");
    scanf("%s", books[numBooks].genre);
}

void displayBooks(Book* books, int numBooks) {
    printf("Book Name\tAuthor\tGenre\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%s\t%s\t%s\n", books[i].name, books[i].author, books[i].genre);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    while (numBooks < MAX_BOOKS) {
        printf("Enter 1 to add a book, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addBook(books, numBooks);
            numBooks++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    displayBooks(books, numBooks);

    return 0;
}