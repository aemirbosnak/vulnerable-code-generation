//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100

typedef struct {
    char title[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_NAME_LENGTH];
    int pages;
} book;

book library[MAX_BOOKS];
int num_books;

void add_book() {
    printf("Enter book title: ");
    scanf("%s", library[num_books].title);
    printf("Enter author: ");
    scanf("%s", library[num_books].author);
    printf("Enter number of pages: ");
    scanf("%d", &library[num_books].pages);
    num_books++;
}

void display_book(int index) {
    printf("Title: %s\n", library[index].title);
    printf("Author: %s\n", library[index].author);
    printf("Pages: %d\n", library[index].pages);
}

void search_book() {
    char search_title[MAX_BOOK_NAME_LENGTH];
    printf("Enter book title to search: ");
    scanf("%s", search_title);
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            display_book(i);
            found = 1;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    num_books = 0;
    while (num_books < MAX_BOOKS) {
        printf("1. Add book\n2. Display all books\n3. Search book\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                for (int i = 0; i < num_books; i++) {
                    display_book(i);
                }
                break;
            case 3:
                search_book();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}