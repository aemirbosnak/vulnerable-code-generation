//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_PAGES 50
#define MAX_WORDS 100

typedef struct {
    char title[50];
    char author[50];
    int pages;
    char words[MAX_WORDS];
} book;

void addBook(book *b) {
    printf("Enter book title: ");
    scanf("%s", b->title);
    printf("Enter book author: ");
    scanf("%s", b->author);
    printf("Enter book pages: ");
    scanf("%d", &b->pages);
    printf("Enter book words: ");
    scanf("%s", b->words);
}

void displayBooks(book *b, int n) {
    printf("\nBook list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s by %s (%d pages, %s)\n", i+1, b[i].title, b[i].author, b[i].pages, b[i].words);
    }
}

int main() {
    book b[MAX_BOOKS];
    int n = 0;

    while (n < MAX_BOOKS) {
        printf("\nEnter 1 to add a book, 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addBook(&b[n]);
            n++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    displayBooks(b, n);

    return 0;
}