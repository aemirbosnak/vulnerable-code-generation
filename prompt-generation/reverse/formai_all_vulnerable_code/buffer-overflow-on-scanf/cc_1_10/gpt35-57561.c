//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct book {
    int id;
    char title[50];
    char author[50];
    int price;
};

typedef struct book Book;

void read_book(Book *b) {
    printf("Enter Book ID: ");
    scanf("%d", &(b->id));
    printf("Enter Book Title: ");
    scanf("%s", &(b->title));
    printf("Enter Book Author: ");
    scanf("%s", &(b->author));
    printf("Enter Book Price: ");
    scanf("%d", &(b->price));
}

void display_book(Book b) {
    printf("%d\t%s\t%s\t%d\n", b.id, b.title, b.author, b.price);
}

int main() {
    Book books[50];
    int num_books = 0;

    while (1) {
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_books == 50) {
                    printf("Cannot add more books\n");
                } else {
                    Book new_book;
                    read_book(&new_book);
                    books[num_books++] = new_book;
                    printf("Book Added Successfully\n");
                }
                break;
            case 2:
                printf("ID\tTitle\tAuthor\tPrice\n");
                for (int i = 0; i < num_books; i++) {
                    display_book(books[i]);
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}