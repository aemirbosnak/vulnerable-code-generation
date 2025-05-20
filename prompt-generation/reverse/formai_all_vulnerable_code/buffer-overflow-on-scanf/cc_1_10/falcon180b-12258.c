//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_PAGES 100
#define MAX_WORDS 1000

typedef struct {
    char title[50];
    char author[50];
    int pages;
    char words[MAX_WORDS][100];
} Book;

void addBook(Book* books, int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);
    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);
    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);
    printf("Enter the words in the book:\n");
    for (int i = 0; i < books[numBooks].pages; i++) {
        scanf("%s", books[numBooks].words[i]);
    }
    printf("\n");
}

void displayBook(Book* books, int numBooks) {
    printf("Book title: %s\n", books[numBooks].title);
    printf("Book author: %s\n", books[numBooks].author);
    printf("Number of pages: %d\n", books[numBooks].pages);
    printf("Words in the book:\n");
    for (int i = 0; i < books[numBooks].pages; i++) {
        printf("%s\n", books[numBooks].words[i]);
    }
    printf("\n");
}

void searchBook(Book* books, int numBooks) {
    printf("Enter book title to search: ");
    char title[50];
    scanf("%s", title);
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found!\n");
            displayBook(books, i);
        }
    }
}

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    while (numBooks < MAX_BOOKS) {
        printf("Enter 1 to add book, 2 to search book, 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(books, numBooks);
                numBooks++;
                break;
            case 2:
                searchBook(books, numBooks);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}