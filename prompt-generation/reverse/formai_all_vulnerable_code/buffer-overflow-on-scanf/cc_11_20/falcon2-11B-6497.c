//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    int pages;
    float price;
};

struct book *books[10];

int main() {
    int num_books = 0;
    int choice = 0;

    printf("Welcome to the Library Management System!\n");
    printf("1. Add a new book\n2. View all books\n3. Search for a book\n4. Update a book's information\n5. Delete a book\n6. Exit\n");

    while (choice!= 6) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                num_books += 1;
                books[num_books] = (struct book *)malloc(sizeof(struct book));
                printf("Enter book title: ");
                scanf("%s", books[num_books]->title);
                printf("Enter book pages: ");
                scanf("%d", &(books[num_books]->pages));
                printf("Enter book price: ");
                scanf("%f", &(books[num_books]->price));
                break;

            case 2:
                for (int i = 0; i < num_books; i++) {
                    printf("Book %d: %s - %d pages - $%.2f\n", i+1, books[i]->title, books[i]->pages, books[i]->price);
                }
                break;

            case 3:
                printf("Enter book title to search: ");
                scanf("%s", books[num_books]->title);
                for (int i = 0; i < num_books; i++) {
                    if (strcmp(books[i]->title, books[num_books]->title) == 0) {
                        printf("Book %d: %s - %d pages - $%.2f\n", i+1, books[i]->title, books[i]->pages, books[i]->price);
                    }
                }
                break;

            case 4:
                printf("Enter book title to update: ");
                scanf("%s", books[num_books]->title);
                printf("Enter new book title: ");
                scanf("%s", books[num_books]->title);
                printf("Enter new book pages: ");
                scanf("%d", &(books[num_books]->pages));
                printf("Enter new book price: ");
                scanf("%f", &(books[num_books]->price));
                break;

            case 5:
                printf("Enter book title to delete: ");
                scanf("%s", books[num_books]->title);
                for (int i = num_books-1; i >= 0; i--) {
                    if (strcmp(books[i]->title, books[num_books]->title) == 0) {
                        free(books[i]);
                        books[i] = NULL;
                        num_books--;
                        break;
                    }
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}