//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 30

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int id;
    struct Book *next;
} Book;

Book *library = NULL;
int num_books = 0;

void add_book(char *title, char *author) {
    Book *new_book = (Book *)malloc(sizeof(Book));

    strcpy(new_book->title, title);
    strcpy(new_book->author, author);

    if (num_books == 0) {
        new_book->id = 1;
        library = new_book;
    } else {
        new_book->id = library->id + 1;
        new_book->next = library;
        library = new_book;
    }

    num_books++;
}

void remove_book(int id) {
    Book *current = library, *previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book not found!\n");
        return;
    }

    if (previous == NULL) {
        library = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    num_books--;
}

void search_book(int id) {
    Book *current = library;

    while (current != NULL) {
        if (current->id == id) {
            printf("Book found:\nTitle: %s\nAuthor: %s\nID: %d\n", current->title, current->author, current->id);
            return;
        }
        current = current->next;
    }

    printf("Book not found!\n");
}

int main() {
    char title[MAX_TITLE], author[MAX_AUTHOR];
    int choice, id;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter author: ");
                scanf("%s", author);
                add_book(title, author);
                break;
            case 2:
                printf("Enter book ID to remove: ");
                scanf("%d", &id);
                remove_book(id);
                break;
            case 3:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                search_book(id);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}