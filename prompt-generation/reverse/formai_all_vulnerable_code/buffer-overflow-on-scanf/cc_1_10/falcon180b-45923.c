//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: active
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

Book books[MAX_BOOKS];
int numBooks;

void addBook() {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    numBooks++;
}

void displayBooks() {
    printf("List of books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].title, books[i].author, books[i].pages);
    }
}

void searchBook() {
    char searchTitle[MAX_TITLE_LENGTH];

    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(searchTitle, books[i].title) == 0) {
            printf("%s by %s (%d pages)\n", books[i].title, books[i].author, books[i].pages);
        }
    }
}

int main() {
    printf("Welcome to Ebook Reader!\n");

    numBooks = 0;

    while (1) {
        printf("\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Search book\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}