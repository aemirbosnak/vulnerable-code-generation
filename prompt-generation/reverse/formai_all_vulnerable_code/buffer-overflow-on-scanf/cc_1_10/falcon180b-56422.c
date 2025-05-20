//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50
#define MAX_BOOK_DESCRIPTION_LENGTH 200
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    char description[MAX_BOOK_DESCRIPTION_LENGTH];
} book;

book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    printf("Enter the title of the book: ");
    scanf("%s", books[num_books].title);

    printf("Enter the author of the book: ");
    scanf("%s", books[num_books].author);

    printf("Enter the description of the book: ");
    scanf("%s", books[num_books].description);

    num_books++;
}

void display_books() {
    printf("Book Title\tBook Author\tBook Description\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t%s\t%s\n", books[i].title, books[i].author, books[i].description);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_book();
            break;
        case 2:
            display_books();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}