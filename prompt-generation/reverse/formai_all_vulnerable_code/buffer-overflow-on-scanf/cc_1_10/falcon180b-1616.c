//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LEN 100
#define MAX_BOOK_AUTHOR_LEN 50
#define MAX_BOOK_DESCRIPTION_LEN 200

typedef struct {
    char name[MAX_BOOK_NAME_LEN];
    char author[MAX_BOOK_AUTHOR_LEN];
    char description[MAX_BOOK_DESCRIPTION_LEN];
    int pages;
    int publication_year;
} book;

int num_books = 0;
book books[MAX_BOOKS];

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Error: Cannot add more books.\n");
        return;
    }

    printf("Enter book name: ");
    scanf("%s", books[num_books].name);

    printf("Enter book author: ");
    scanf("%s", books[num_books].author);

    printf("Enter book description: ");
    scanf("%s", books[num_books].description);

    printf("Enter number of pages: ");
    scanf("%d", &books[num_books].pages);

    printf("Enter publication year: ");
    scanf("%d", &books[num_books].publication_year);

    num_books++;
}

void display_books() {
    printf("Number of books: %d\n", num_books);

    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i + 1);
        printf("Name: %s\n", books[i].name);
        printf("Author: %s\n", books[i].author);
        printf("Description: %s\n", books[i].description);
        printf("Pages: %d\n", books[i].pages);
        printf("Publication Year: %d\n\n", books[i].publication_year);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add book\n");
        printf("2. Display books\n");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}