//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

void addBook(Book books[], int numBooks) {
    printf("Enter book title: ");
    scanf("%s", books[numBooks].title);

    printf("Enter book author: ");
    scanf("%s", books[numBooks].author);

    printf("Enter number of pages: ");
    scanf("%d", &books[numBooks].pages);

    numBooks++;
}

void displayBooks(Book books[], int numBooks) {
    printf("\nBook List:\n");
    printf("--------------------\n");

    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, books[i].title, books[i].author, books[i].pages);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int numBooks = 0;

    while (numBooks < MAX_BOOKS) {
        printf("\nLibrary Menu:\n");
        printf("--------------------\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, numBooks);
                break;
            case 2:
                displayBooks(library, numBooks);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}