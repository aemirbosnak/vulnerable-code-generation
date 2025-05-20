//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char author[50];
    int publish_year;
} Book;

void print_menu() {
    printf("\n------------------\n");
    printf("| Library Menu    |\n");
    printf("------------------|\n");
    printf("| 1. Add a Book   |\n");
    printf("| 2. Remove a Book|\n");
    printf("| 3. Display All  |\n");
    printf("| 4. Quit         |\n");
    printf("------------------\n");
}

void add_book(Book books[], int* num_books) {
    if (*num_books >= 10) {
        printf("Maximum number of books reached.\n");
        return;
    }

    printf("Enter book title: ");
    scanf("%s", books[*num_books].title);

    printf("Enter book author: ");
    scanf("%s", books[*num_books].author);

    printf("Enter book publish year: ");
    scanf("%d", &books[*num_books].publish_year);

    (*num_books)++;
}

void remove_book(Book books[], int* num_books) {
    int index;
    char title[50];

    printf("Enter book title to remove: ");
    scanf("%s", title);

    for (index = 0; index < *num_books; index++) {
        if (strcmp(books[index].title, title) == 0) {
            for (int i = index; i < *num_books - 1; i++) {
                books[i] = books[i + 1];
            }
            (*num_books)--;
            break;
        }
    }

    if (index == *num_books) {
        printf("Book not found.\n");
    }
}

void display_books(Book books[], int num_books) {
    printf("\n------------------\n");
    printf("| Library Books    |\n");
    printf("------------------|\n");

    for (int i = 0; i < num_books; i++) {
        printf("| %-20s | %-20s | %-10d |\n", books[i].title, books[i].author, books[i].publish_year);
    }

    printf("------------------\n");
}

int main() {
    int num_books = 0;
    Book books[10];

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &num_books);
                break;
            case 2:
                remove_book(books, &num_books);
                break;
            case 3:
                display_books(books, num_books);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}