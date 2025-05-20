//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int isbn;
};

void display_menu() {
    printf("1. Add book\n");
    printf("2. Remove book\n");
    printf("3. Search book\n");
    printf("4. Exit\n");
}

void add_book() {
    struct book book;

    printf("Enter the title: ");
    scanf("%s", book.title);

    printf("Enter the author: ");
    scanf("%s", book.author);

    printf("Enter the ISBN: ");
    scanf("%d", &book.isbn);

    printf("Book added successfully.\n");
}

void remove_book() {
    struct book book;

    printf("Enter the title: ");
    scanf("%s", book.title);

    printf("Enter the author: ");
    scanf("%s", book.author);

    printf("Enter the ISBN: ");
    scanf("%d", &book.isbn);

    printf("Book removed successfully.\n");
}

void search_book() {
    struct book book;

    printf("Enter the title: ");
    scanf("%s", book.title);

    printf("Enter the author: ");
    scanf("%s", book.author);

    printf("Enter the ISBN: ");
    scanf("%d", &book.isbn);

    printf("Book found: %s by %s (ISBN: %d)\n", book.title, book.author, book.isbn);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                remove_book();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}