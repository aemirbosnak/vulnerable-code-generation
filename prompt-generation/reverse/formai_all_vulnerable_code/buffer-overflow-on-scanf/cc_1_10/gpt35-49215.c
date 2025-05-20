//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    int pages;
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Max number of books reached.\n");
        return;
    }

    Book new_book;

    printf("Enter the book's title: ");
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;

    printf("Enter the book's author: ");
    fgets(new_book.author, MAX_TITLE_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &new_book.pages);
    getchar(); // remove extra newline character

    books[num_books] = new_book;
    num_books++;

    printf("Book added successfully.\n");
}

void list_books() {
    if (num_books == 0) {
        printf("No books found.\n");
        return;
    }

    printf("List of Books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s, Author: %s, Pages: %d\n", books[i].title, books[i].author, books[i].pages);
    }
}

void search_books() {
    char query[MAX_TITLE_LENGTH];

    printf("Enter your search query: ");
    fgets(query, MAX_TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0;

    printf("Search results:\n");
    for (int i = 0; i < num_books; i++) {
        if (strstr(books[i].title, query) != NULL) {
            printf("Title: %s, Author: %s, Pages: %d\n", books[i].title, books[i].author, books[i].pages);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Books\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // remove extra newline character

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                search_books();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}