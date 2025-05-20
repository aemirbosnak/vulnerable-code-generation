//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_LENGTH 100
#define MAX_BOOK_AUTHOR_LENGTH 50

typedef struct {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_AUTHOR_LENGTH];
    int pages;
    int read_pages;
} Book;

int main() {
    int num_books = 0;
    Book books[MAX_BOOKS];

    while (num_books < MAX_BOOKS) {
        printf("Enter book name (or 'done' to finish): ");
        scanf("%s", books[num_books].name);

        if (strcmp(books[num_books].name, "done") == 0) {
            break;
        }

        printf("Enter author name: ");
        scanf("%s", books[num_books].author);

        printf("Enter number of pages: ");
        scanf("%d", &books[num_books].pages);

        num_books++;
    }

    int choice;
    while (1) {
        printf("\n1. List books\n");
        printf("2. Start reading\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nList of books:\n");
            for (int i = 0; i < num_books; i++) {
                printf("%d. %s by %s (%d pages)\n", i+1, books[i].name, books[i].author, books[i].pages);
            }
            break;

        case 2:
            printf("\nEnter book number: ");
            scanf("%d", &choice);

            if (choice >= 1 && choice <= num_books) {
                printf("\nYou are reading %s by %s\n", books[choice-1].name, books[choice-1].author);
                printf("How many pages did you read? ");
                scanf("%d", &books[choice-1].read_pages);
            } else {
                printf("Invalid book number.\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}