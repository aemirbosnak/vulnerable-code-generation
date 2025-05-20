//FormAI DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    int pages;
    int year;
    char path[100];
} Book;

void print_menu() {
    printf("\nWelcome to Retro Ebook Reader!\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Open Book\n");
    printf("4. Exit\n");
}

int get_choice() {
    int choice = 0;
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_book(Book books[], int *num_books) {
    if (*num_books >= MAX_BOOKS) {
        printf("\nMaximum number of books reached!\n");
        return;
    }

    Book book;

    printf("\nEnter book title: ");
    scanf("%s", book.title);
    printf("Enter author name: ");
    scanf("%s", book.author);
    printf("Enter number of pages: ");
    scanf("%d", &book.pages);
    printf("Enter year: ");
    scanf("%d", &book.year);
    printf("Enter file path: ");
    scanf("%s", book.path);

    books[*num_books] = book;
    (*num_books)++;
}

void list_books(Book books[], int num_books) {
    printf("\n%-30s %-30s %-10s %-10s\n", "Title", "Author", "Pages", "Year");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%-30s %-30s %-10d %-10d\n", books[i].title, books[i].author, books[i].pages, books[i].year);
    }
}

void open_book(Book books[], int num_books) {
    char title[100];
    printf("\nEnter the title of the book you want to read: ");
    scanf("%s", title);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("\nOpening book: %s\n", books[i].title);
            printf("Path: %s\n", books[i].path);
            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    int choice = 0;
    do {
        print_menu();
        choice = get_choice();

        switch (choice) {
            case 1:
                add_book(books, &num_books);
                break;
            case 2:
                list_books(books, num_books);
                break;
            case 3:
                open_book(books, num_books);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}