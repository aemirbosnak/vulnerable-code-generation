//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 30

// Define a structure to represent a book
typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int is_borrowed; // 0 if available, 1 if borrowed
} Book;

// Function prototypes
void addBook(Book *books, int *count);
void displayBooks(Book *books, int count);
void borrowBook(Book *books, int count);
void returnBook(Book *books, int count);
void saveBooksToFile(Book *books, int count);
void loadBooksFromFile(Book *books, int *count);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    loadBooksFromFile(books, &count);

    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                borrowBook(books, count);
                break;
            case 4:
                returnBook(books, count);
                break;
            case 5:
                saveBooksToFile(books, count);
                printf("Exiting the system...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(Book *books, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    scanf(" %[^\n]", new_book.title);
    printf("Enter author name: ");
    scanf(" %[^\n]", new_book.author);
    new_book.is_borrowed = 0; // Book is initially available

    books[*count] = new_book;
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(Book *books, int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < count; i++) {
        if (books[i].is_borrowed == 0) {
            printf("Title: %s, Author: %s\n", books[i].title, books[i].author);
        }
    }
}

void borrowBook(Book *books, int count) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to borrow: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            if (books[i].is_borrowed == 1) {
                printf("Sorry, this book is already borrowed.\n");
            } else {
                books[i].is_borrowed = 1;
                printf("You have successfully borrowed the book.\n");
            }
            return;
        }
    }
    printf("Book not found in the library.\n");
}

void returnBook(Book *books, int count) {
    char title[TITLE_LENGTH];
    printf("Enter the title of the book to return: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            if (books[i].is_borrowed == 0) {
                printf("This book wasn't borrowed.\n");
            } else {
                books[i].is_borrowed = 0;
                printf("You have successfully returned the book.\n");
            }
            return;
        }
    }
    printf("Book not found in the library.\n");
}

void saveBooksToFile(Book *books, int count) {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Error saving books to file.\n");
        return;
    }
    fwrite(books, sizeof(Book), count, file);
    fclose(file);
}

void loadBooksFromFile(Book *books, int *count) {
    FILE *file = fopen("books.dat", "rb");
    if (file != NULL) {
        *count = fread(books, sizeof(Book), MAX_BOOKS, file);
        fclose(file);
    }
}