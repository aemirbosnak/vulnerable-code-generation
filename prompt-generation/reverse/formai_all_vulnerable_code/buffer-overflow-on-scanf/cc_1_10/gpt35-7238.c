//FormAI DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    float price;
} Book;

void display_menu() {
    printf("Welcome to Sherlock Holmes bookstore!\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Find a book by title\n");
    printf("4. Find a book by author\n");
    printf("5. Exit\n");
    printf("\n");
}

void add_book(Book *books, int *num_books) {
    if (*num_books >= MAX_BOOKS) {
        printf("Sorry, the bookstore is full!\n");
        return;
    }

    printf("Enter the book title: ");
    scanf("%s", books[*num_books].title);

    printf("Enter the author name: ");
    scanf("%s", books[*num_books].author);

    printf("Enter the number of pages: ");
    scanf("%d", &books[*num_books].num_pages);

    printf("Enter the price: ");
    scanf("%f", &books[*num_books].price);

    printf("Book added successfully!\n");
    printf("\n");

    (*num_books)++;
}

void display_books(Book *books, int num_books) {
    if (num_books == 0) {
        printf("No books found!\n");
        printf("\n");
        return;
    }

    printf("Title\t\tAuthor\t\tPages\tPrice\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t\t%s\t\t%d\t%.2f\n", 
            books[i].title, books[i].author, books[i].num_pages, books[i].price);
    }
    printf("\n");
}

void find_book_by_title(Book *books, int num_books) {
    char title[MAX_TITLE_LENGTH];
    int found = 0;

    printf("Enter the book title: ");
    scanf("%s", title);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(title, books[i].title) == 0) {
            printf("Title\t\tAuthor\t\tPages\tPrice\n");
            printf("--------------------------------------------------\n");
            printf("%s\t\t%s\t\t%d\t%.2f\n", 
                books[i].title, books[i].author, books[i].num_pages, books[i].price);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No books found with title %s\n", title);
        printf("\n");
    }
}

void find_book_by_author(Book *books, int num_books) {
    char author[MAX_AUTHOR_LENGTH];
    int found = 0;

    printf("Enter the author name: ");
    scanf("%s", author);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(author, books[i].author) == 0) {
            printf("Title\t\tAuthor\t\tPages\tPrice\n");
            printf("--------------------------------------------------\n");
            printf("%s\t\t%s\t\t%d\t%.2f\n", 
                books[i].title, books[i].author, books[i].num_pages, books[i].price);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with author %s\n", author);
        printf("\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;
    int choice;

    display_menu();

    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &num_books);
                break;
            case 2:
                display_books(books, num_books);
                break;
            case 3:
                find_book_by_title(books, num_books);
                break;
            case 4:
                find_book_by_author(books, num_books);
                break;
            case 5:
                printf("Thank you for visiting Sherlock Holmes bookstore!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}