//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 20
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_GENRE_LENGTH 30
#define MAX_PAGES 1000
#define MAX_WORDS 5000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int pages;
    int words;
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter the title of the book: ");
    scanf("%s", &books[numBooks].title);

    printf("Enter the author of the book: ");
    scanf("%s", &books[numBooks].author);

    printf("Enter the genre of the book: ");
    scanf("%s", &books[numBooks].genre);

    printf("Enter the number of pages: ");
    scanf("%d", &books[numBooks].pages);

    printf("Enter the number of words: ");
    scanf("%d", &books[numBooks].words);

    numBooks++;
}

void displayBooks(Book* books, int numBooks) {
    printf("The library contains the following books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%s) - %d pages, %d words\n", i+1, books[i].title, books[i].author, books[i].genre, books[i].pages, books[i].words);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int numBooks = 0;

    addBook(library, numBooks);

    while (numBooks < MAX_BOOKS) {
        printf("Do you want to add another book? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addBook(library, numBooks);
        } else {
            break;
        }
    }

    displayBooks(library, numBooks);

    return 0;
}