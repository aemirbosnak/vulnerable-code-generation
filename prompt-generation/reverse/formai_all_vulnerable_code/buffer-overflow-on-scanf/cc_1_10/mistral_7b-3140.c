//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_PAGES 10

typedef struct {
    char title[MAX_LINE_LENGTH];
    char content[MAX_NUM_PAGES][MAX_LINE_LENGTH];
} Book;

void display_menu() {
    printf("\n1. Load Book\n2. Display Book\n3. Exit\n");
}

void load_book(Book *book) {
    printf("Enter Book Title: ");
    fgets(book->title, MAX_LINE_LENGTH, stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    for (int i = 0; i < MAX_NUM_PAGES; i++) {
        printf("Enter Page %d: ", i + 1);
        fgets(book->content[i], MAX_LINE_LENGTH, stdin);
        book->content[i][strcspn(book->content[i], "\n")] = '\0';
    }
}

void display_book(const Book *book) {
    printf("\n%s\n", book->title);

    for (int i = 0; i < MAX_NUM_PAGES; i++) {
        printf("\nPage %d:\n%s\n", i + 1, book->content[i]);
    }
}

int main() {
    Book my_book;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                load_book(&my_book);
                break;
            case 2:
                display_book(&my_book);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}