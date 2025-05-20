//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME 100
#define MAX_BOOK_AUTHOR 100

typedef struct {
    char name[MAX_BOOK_NAME];
    char author[MAX_BOOK_AUTHOR];
    int pages;
} Book;

int numBooks = 0;
Book library[MAX_BOOKS];

void addBook() {
    char name[MAX_BOOK_NAME];
    char author[MAX_BOOK_AUTHOR];
    int pages;

    printf("Enter the name of the book: ");
    scanf("%s", name);
    strcpy(library[numBooks].name, name);

    printf("Enter the author of the book: ");
    scanf("%s", author);
    strcpy(library[numBooks].author, author);

    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    library[numBooks].pages = pages;

    numBooks++;
}

void displayBooks() {
    printf("\n\nBooks in the library:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d pages)\n", i+1, library[i].name, library[i].author, library[i].pages);
    }
}

int main() {
    printf("Welcome to the e-book library!\n");

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Exit\n");

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
                printf("Thank you for using the e-book library!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}