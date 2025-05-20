//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define ISBN_LEN 13

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    char isbn[ISBN_LEN];
    int is_issued;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book new_book;
    printf("Enter book title: ");
    getchar(); // clear newline from buffer
    fgets(new_book.title, TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(new_book.author, AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; 

    printf("Enter ISBN number: ");
    fgets(new_book.isbn, ISBN_LEN, stdin);
    new_book.isbn[strcspn(new_book.isbn, "\n")] = 0; 

    new_book.is_issued = 0; // Book is not issued
    library[book_count++] = new_book;
    printf("Book '%s' added successfully!\n", new_book.title);
}

void issue_book() {
    char isbn[ISBN_LEN];
    printf("Enter ISBN of the book to issue: ");
    getchar();
    fgets(isbn, ISBN_LEN, stdin);
    isbn[strcspn(isbn, "\n")] = 0; 

    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (library[i].is_issued) {
                printf("Book '%s' is already issued.\n", library[i].title);
            } else {
                library[i].is_issued = 1;
                printf("Book '%s' has been issued successfully.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ISBN '%s' not found.\n", isbn);
}

void return_book() {
    char isbn[ISBN_LEN];
    printf("Enter ISBN of the book to return: ");
    getchar();
    fgets(isbn, ISBN_LEN, stdin);
    isbn[strcspn(isbn, "\n")] = 0; 

    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            if (!library[i].is_issued) {
                printf("Book '%s' was not issued.\n", library[i].title);
            } else {
                library[i].is_issued = 0;
                printf("Book '%s' has been returned successfully.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ISBN '%s' not found.\n", isbn);
}

void view_books() {
    printf("List of books in the library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Title: %s, Author: %s, ISBN: %s, Status: %s\n",
               library[i].title,
               library[i].author,
               library[i].isbn,
               library[i].is_issued ? "Issued" : "Available");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. View Books\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                issue_book();
                break;
            case 3:
                return_book();
                break;
            case 4:
                view_books();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}