//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_BOOK_NAME_LENGTH 100

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_NAME_LENGTH];
    int num_pages;
    int current_page;
} Book;

void print_book(Book* book) {
    printf("Book Name: %s\n", book->name);
    printf("Author: %s\n", book->author);
    printf("Number of Pages: %d\n", book->num_pages);
    printf("Current Page: %d\n", book->current_page);
}

void read_book(Book* book) {
    printf("You are now reading %s by %s...\n", book->name, book->author);
    for (int i = 1; i <= book->num_pages; i++) {
        printf("Page %d:\n", i);
        printf(" ");
        for (int j = 0; j < 50; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("Enter the name of a book (or type 'done' to finish):\n");
        scanf("%s", books[num_books].name);

        if (strcmp(books[num_books].name, "done") == 0) {
            break;
        }

        printf("Enter the author of the book:\n");
        scanf("%s", books[num_books].author);

        printf("Enter the number of pages in the book:\n");
        scanf("%d", &books[num_books].num_pages);

        num_books++;
    }

    printf("You have %d books:\n", num_books);

    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i+1);
        print_book(&books[i]);
    }

    int choice;
    while (1) {
        printf("Choose a book to read:\n");
        for (int i = 0; i < num_books; i++) {
            printf("%d. %s by %s\n", i+1, books[i].name, books[i].author);
        }
        scanf("%d", &choice);

        if (choice >= 1 && choice <= num_books) {
            read_book(&books[choice-1]);
        } else {
            printf("Invalid choice.\n");
        }

        printf("Press enter to continue...\n");
        getchar();
    }

    return 0;
}