//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10

typedef struct {
    char title[50];
    char author[50];
    int pages;
} Book;

void addBook(Book* books, int numBooks, char* title, char* author, int pages) {
    if (numBooks >= MAX_BOOKS) {
        printf("Error: Cannot add more than %d books.\n", MAX_BOOKS);
        return;
    }
    strcpy(books[numBooks].title, title);
    strcpy(books[numBooks].author, author);
    books[numBooks].pages = pages;
    numBooks++;
}

void printBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
}

void searchBook(Book* books, int numBooks, char* title) {
    int i;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printBook(books[i]);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    addBook(books, numBooks, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    addBook(books, numBooks, "To Kill a Mockingbird", "Harper Lee", 281);
    addBook(books, numBooks, "Pride and Prejudice", "Jane Austen", 279);

    printf("List of books:\n");
    for (int i = 0; i < numBooks; i++) {
        printBook(books[i]);
    }

    char searchTitle[50];
    printf("Enter a book title to search: ");
    scanf("%s", searchTitle);
    searchBook(books, numBooks, searchTitle);

    return 0;
}