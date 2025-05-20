//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
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

int numBooks = 0;
Book books[MAX_BOOKS];

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Sorry, cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    numBooks++;
}

void displayBooks() {
    printf("Number of books: %d\n", numBooks);

    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].title, books[i].author, books[i].pages);
    }
}

int main() {
    int choice;

    do {
        printf("Ebook Reader\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}