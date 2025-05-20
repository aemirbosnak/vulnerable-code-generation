//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: careful
// Ebook reader program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int pages;
} Book;

void print_menu() {
    printf("Ebook Reader Program\n");
    printf("1. Add a book\n");
    printf("2. Remove a book\n");
    printf("3. Display all books\n");
    printf("4. Search for a book\n");
    printf("5. Exit\n");
}

void add_book(Book* books, int* num_books) {
    if (*num_books >= MAX_BOOKS) {
        printf("Sorry, the book list is full.\n");
        return;
    }
    printf("Enter the title of the book: ");
    scanf("%s", books[*num_books].title);
    printf("Enter the author of the book: ");
    scanf("%s", books[*num_books].author);
    printf("Enter the number of pages: ");
    scanf("%d", &books[*num_books].pages);
    (*num_books)++;
}

void remove_book(Book* books, int* num_books) {
    if (*num_books <= 0) {
        printf("Sorry, there are no books to remove.\n");
        return;
    }
    printf("Enter the title of the book to remove: ");
    scanf("%s", books[*num_books].title);
    for (int i = 0; i < *num_books; i++) {
        if (strcmp(books[i].title, books[*num_books].title) == 0) {
            for (int j = i; j < *num_books - 1; j++) {
                books[j] = books[j + 1];
            }
            (*num_books)--;
            break;
        }
    }
}

void display_books(Book* books, int num_books) {
    printf("Books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s by %s (%d pages)\n", books[i].title, books[i].author, books[i].pages);
    }
}

void search_book(Book* books, int num_books) {
    char title[MAX_TITLE_LEN];
    printf("Enter the title of the book to search for: ");
    scanf("%s", title);
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("%s by %s (%d pages)\n", books[i].title, books[i].author, books[i].pages);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, the book was not found.\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;
    int choice;
    while (1) {
        print_menu();
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
                search_book(books, num_books);
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}