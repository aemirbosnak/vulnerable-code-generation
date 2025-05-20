//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50

typedef struct {
    char title[MAX_TITLE];
    int copies;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void add_book(char *title, int num_copies) {
    if (num_books >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    strcpy(library[num_books].title, title);
    library[num_books].copies = num_copies;
    num_books++;
}

void remove_book(char *title) {
    int i;

    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            num_books--;
            memmove(&library[i], &library[i + 1], sizeof(Book) * (num_books - i));
            return;
        }
    }

    printf("Book not found.\n");
}

void search_book(char *title) {
    int i;

    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Copies: %d\n", library[i].copies);
            return;
        }
    }

    printf("Book not found.\n");
}

int main() {
    char command[10], title[MAX_TITLE];
    int num_copies;

    while (1) {
        printf("\nLibrary Management System\n"
               "1. Add book\n"
               "2. Remove book\n"
               "3. Search book\n"
               "4. Quit\n"
               "Enter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter number of copies: ");
                scanf("%d", &num_copies);
                add_book(title, num_copies);
                break;
            case '2':
                printf("Enter title of the book to remove: ");
                scanf("%s", title);
                remove_book(title);
                break;
            case '3':
                printf("Enter title to search: ");
                scanf("%s", title);
                search_book(title);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}