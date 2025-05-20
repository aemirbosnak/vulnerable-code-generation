//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
}

void displayBooks(Book* books, int numBooks) {
    printf("List of books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. Title: %s\nAuthor: %s\nPages: %d\n", i+1, books[i].title, books[i].author, books[i].pages);
    }
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
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("Displaying list of books:\n");
    displayBooks(books, numBooks);

    return 0;
}