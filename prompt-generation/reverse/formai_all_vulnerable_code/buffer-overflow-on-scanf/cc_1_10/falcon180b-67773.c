//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define NUM_BOOKS 5
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
} Book;

void addBook(Book* books, int numBooks) {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;

    printf("Enter book title: ");
    scanf("%s", title);
    printf("Enter book author: ");
    scanf("%s", author);
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    strcpy(books[numBooks].title, title);
    strcpy(books[numBooks].author, author);
    books[numBooks].pages = pages;

    printf("Book added successfully!\n");
}

void displayBooks(Book* books, int numBooks) {
    printf("Book Title\tBook Author\tNumber of Pages\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%-20s%-30s%d\n", books[i].title, books[i].author, books[i].pages);
    }
}

int main() {
    Book books[NUM_BOOKS];
    int numBooks = 0;

    while (numBooks < NUM_BOOKS) {
        printf("1. Add book\n2. Display books\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook(books, numBooks);
            break;
        case 2:
            displayBooks(books, numBooks);
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }

        printf("\n");
    }

    return 0;
}