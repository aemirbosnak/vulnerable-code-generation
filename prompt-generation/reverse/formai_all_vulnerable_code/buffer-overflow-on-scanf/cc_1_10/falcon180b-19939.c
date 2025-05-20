//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_SIZE 100
#define MAX_BOOK_AUTHOR_SIZE 100
#define MAX_BOOK_PAGES 1000

typedef struct {
    char name[MAX_BOOK_NAME_SIZE];
    char author[MAX_BOOK_AUTHOR_SIZE];
    int pages;
} Book;

void addBook(Book* books, int numBooks, char* name, char* author, int pages) {
    if (numBooks >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }
    strcpy(books[numBooks].name, name);
    strcpy(books[numBooks].author, author);
    books[numBooks].pages = pages;
    numBooks++;
}

void displayBooks(Book* books, int numBooks) {
    printf("Book List:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Name: %s\nAuthor: %s\nPages: %d\n\n", books[i].name, books[i].author, books[i].pages);
    }
}

void searchBook(Book* books, int numBooks, char* name) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("Book found:\n");
            printf("Name: %s\nAuthor: %s\nPages: %d\n\n", books[i].name, books[i].author, books[i].pages);
        }
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    addBook(books, numBooks, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    addBook(books, numBooks, "To Kill a Mockingbird", "Harper Lee", 281);
    addBook(books, numBooks, "1984", "George Orwell", 328);
    addBook(books, numBooks, "The Catcher in the Rye", "J.D. Salinger", 277);

    displayBooks(books, numBooks);

    char searchName[MAX_BOOK_NAME_SIZE];
    printf("Enter a book name to search: ");
    scanf("%s", searchName);
    searchBook(books, numBooks, searchName);

    return 0;
}