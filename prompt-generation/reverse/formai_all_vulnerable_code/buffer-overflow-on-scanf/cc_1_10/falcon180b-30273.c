//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
    int id;
} Book;

Book books[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("Cannot add more books. Maximum limit reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    books[numBooks].id = numBooks + 1;
    numBooks++;
}

void displayBooks() {
    printf("Book ID\tBook Title\tAuthor\tPages\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d\t%s\t%s\t%d\n", books[i].id, books[i].title, books[i].author, books[i].pages);
    }
}

int main() {
    int choice;

    do {
        printf("\nEbook Reader\n");
        printf("1. Add book\n2. Display books\n3. Exit\n");
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
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}