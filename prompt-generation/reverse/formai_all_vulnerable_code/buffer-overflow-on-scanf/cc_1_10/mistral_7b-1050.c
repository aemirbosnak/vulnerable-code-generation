//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define BOOK_NAME_SIZE 50
#define BOOK_AUTHOR_SIZE 50

typedef struct {
    char name[BOOK_NAME_SIZE];
    char author[BOOK_AUTHOR_SIZE];
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void add_book();
void remove_book();
void list_books();
void search_books();

void print_menu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add a book\n");
    printf("2. Remove a book\n");
    printf("3. List all books\n");
    printf("4. Search for a book\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                remove_book();
                break;
            case 3:
                list_books();
                break;
            case 4:
                search_books();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book name: ");
    scanf("%s", library[num_books].name);

    printf("Enter book author: ");
    scanf("%s", library[num_books].author);

    num_books++;
    printf("Book added successfully.\n");
}

void remove_book() {
    int index;
    char name[BOOK_NAME_SIZE];

    printf("Enter book name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        for (int i = index; i < num_books - 1; i++) {
            library[i] = library[i + 1];
        }
        num_books--;
        printf("Book removed successfully.\n");
    } else {
        printf("Book not found in the library.\n");
    }
}

void list_books() {
    printf("\nList of all books in the library:\n");

    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].name, library[i].author);
    }
}

void search_books() {
    int index;
    char name[BOOK_NAME_SIZE];

    printf("Enter book name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        printf("Book found: %s by %s\n", library[index].name, library[index].author);
    } else {
        printf("Book not found in the library.\n");
    }
}