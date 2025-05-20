//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME_SIZE 100

typedef struct {
    char name[MAX_BOOK_NAME_SIZE];
    char author[MAX_BOOK_NAME_SIZE];
    char genre[MAX_BOOK_NAME_SIZE];
    char description[MAX_BOOK_NAME_SIZE];
    int page_count;
    int price;
} Book;

void add_book(Book* books, int num_books) {
    printf("Enter book name: ");
    scanf("%s", books[num_books].name);
    printf("Enter author name: ");
    scanf("%s", books[num_books].author);
    printf("Enter genre: ");
    scanf("%s", books[num_books].genre);
    printf("Enter description: ");
    scanf("%s", books[num_books].description);
    printf("Enter page count: ");
    scanf("%d", &books[num_books].page_count);
    printf("Enter price: ");
    scanf("%d", &books[num_books].price);
}

void display_books(Book* books, int num_books) {
    for (int i = 0; i < num_books; i++) {
        printf("\nBook %d:\n", i+1);
        printf("Name: %s\n", books[i].name);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Description: %s\n", books[i].description);
        printf("Page Count: %d\n", books[i].page_count);
        printf("Price: $%d\n\n", books[i].price);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("\nEnter 1 to add a book or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_book(books, num_books);
            num_books++;
        } else if (choice!= 0) {
            printf("Invalid input. Please enter 1 or 0.\n");
        }
    }

    printf("\nDisplaying all books:\n");
    display_books(books, num_books);

    return 0;
}