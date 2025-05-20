//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define PASSWORD "mypassword"

typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    int year_published;
} Book;

int num_books = 0;
Book book_list[MAX_BOOKS];

void add_book() {
    Book new_book;
    printf("Title: ");
    scanf("%s", new_book.title);
    printf("Author: ");
    scanf("%s", new_book.author);
    printf("Publisher: ");
    scanf("%s", new_book.publisher);
    printf("Year Published: ");
    scanf("%d", &new_book.year_published);
    book_list[num_books++] = new_book;
    printf("Book added successfully!\n");
}

void list_books() {
    if (num_books == 0) {
        printf("No books to display.\n");
        return;
    }
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, book_list[i].title, book_list[i].author);
    }
}

int main() {
    char password_attempt[50];

    printf("Welcome to the C Ebook Reader\n");
    printf("Please enter the password: ");
    scanf("%s", password_attempt);

    if (strcmp(password_attempt, PASSWORD) != 0) {
        printf("Incorrect password. Exiting program.\n");
        return 0;
    }

    printf("You have been granted access to the program.\n");

    while (1) {
        printf("1. Add book\n");
        printf("2. List books\n");
        printf("0. Exit\n");

        int choice = -1;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 0:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}