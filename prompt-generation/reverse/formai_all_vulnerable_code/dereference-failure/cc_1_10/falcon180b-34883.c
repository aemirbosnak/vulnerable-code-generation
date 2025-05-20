//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} Book;

int numBooks = 0;
Book* books = NULL;

int addBook(char* title, char* author, char* description) {
    if (numBooks >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return -1;
    }

    Book* newBook = malloc(sizeof(Book));
    strncpy(newBook->title, title, MAX_TITLE_LENGTH);
    strncpy(newBook->author, author, MAX_AUTHOR_LENGTH);
    strncpy(newBook->description, description, MAX_DESCRIPTION_LENGTH);

    books = realloc(books, sizeof(Book) * (numBooks + 1));
    books[numBooks] = *newBook;
    numBooks++;

    return 0;
}

void listBooks() {
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s\n%s\n", i+1, books[i].title, books[i].author, books[i].description);
    }
}

int main() {
    books = malloc(sizeof(Book) * MAX_BOOKS);

    addBook("The Catcher in the Rye", "J.D. Salinger", "A story about a teenage boy's struggle with identity and belonging.");
    addBook("To Kill a Mockingbird", "Harper Lee", "A novel exploring themes of racism and injustice in the American South.");
    addBook("1984", "George Orwell", "A dystopian novel set in a totalitarian society where individualism is suppressed.");

    listBooks();

    return 0;
}