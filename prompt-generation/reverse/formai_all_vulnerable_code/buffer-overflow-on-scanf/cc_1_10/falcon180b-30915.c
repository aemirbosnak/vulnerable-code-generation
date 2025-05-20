//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: irregular
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
    printf("Enter title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
    numBooks++;
}

void printBooks() {
    printf("Number of books: %d\n", numBooks);
    for (int i = 0; i < numBooks; i++) {
        printf("%d. Title: %s\nAuthor: %s\nPages: %d\n", i + 1, books[i].title, books[i].author, books[i].pages);
    }
}

void searchBook() {
    printf("Enter title to search: ");
    char searchTitle[MAX_TITLE_LENGTH];
    scanf("%s", searchTitle);
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    printf("Welcome to the Ebook Reader!\n");
    while (1) {
        printf("\n1. Add book\n2. Print books\n3. Search book\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                printBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}