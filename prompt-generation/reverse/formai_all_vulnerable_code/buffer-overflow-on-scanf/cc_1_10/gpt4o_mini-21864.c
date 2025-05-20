//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
    int is_checked_out;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count < MAX_BOOKS) {
        Book new_book;
        printf("Enter book title: ");
        fgets(new_book.title, TITLE_LEN, stdin);
        new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline
        printf("Enter author name: ");
        fgets(new_book.author, AUTHOR_LEN, stdin);
        new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline
        printf("Enter publication year: ");
        scanf("%d", &new_book.year);
        new_book.is_checked_out = 0; // Initially not checked out
        getchar(); // Clear newline from input buffer
        
        library[book_count] = new_book;
        book_count++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full! Cannot add more books.\n");
    }
}

void list_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s by %s (%d) [%s]\n", 
               i + 1, library[i].title, library[i].author, library[i].year, 
               library[i].is_checked_out ? "Checked out" : "Available");
    }
}

void check_out_book() {
    int choice;
    list_books();
    if (book_count > 0) {
        printf("Enter the number of the book to check out: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        if (choice > 0 && choice <= book_count) {
            if (!library[choice - 1].is_checked_out) {
                library[choice - 1].is_checked_out = 1;
                printf("You have checked out \"%s\".\n", library[choice - 1].title);
            } else {
                printf("Sorry, this book is already checked out!\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
    }
}

void return_book() {
    int choice;
    list_books();
    if (book_count > 0) {
        printf("Enter the number of the book to return: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        if (choice > 0 && choice <= book_count) {
            if (library[choice - 1].is_checked_out) {
                library[choice - 1].is_checked_out = 0;
                printf("You have returned \"%s\".\n", library[choice - 1].title);
            } else {
                printf("This book was not checked out!\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
    }
}

void display_menu() {
    printf("\nLibrary Management System Menu:\n");
    printf("1. Add a new book\n");
    printf("2. List all books\n");
    printf("3. Check out a book\n");
    printf("4. Return a book\n");
    printf("5. Exit\n");
}

int main() {
    int option;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Clear newline from input buffer

        switch (option) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                check_out_book();
                break;
            case 4:
                return_book();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}