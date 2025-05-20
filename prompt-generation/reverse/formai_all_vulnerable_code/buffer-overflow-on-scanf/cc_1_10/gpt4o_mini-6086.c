//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

Book database[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("The database is full! Cannot add more books.\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    getchar(); // To consume the newline from previous input
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline character

    printf("Enter author's name: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &new_book.year);

    database[book_count++] = new_book;
    printf("Book added successfully! Thank you for contributing to our collection.\n");
}

void view_books() {
    printf("\n**** Current Book Collection ****\n");
    if (book_count == 0) {
        printf("No books in the database.\n");
        return;
    }

    for (int i = 0; i < book_count; ++i) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", database[i].title);
        printf("Author: %s\n", database[i].author);
        printf("Year: %d\n", database[i].year);
        printf("------------------------\n");
    }
}

void search_book() {
    char search_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // To consume the newline from previous input
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline character

    int found = 0;
    printf("\n**** Search Results ****\n");
    for (int i = 0; i < book_count; ++i) {
        if (strcasecmp(database[i].title, search_title) == 0) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", database[i].title);
            printf("Author: %s\n", database[i].author);
            printf("Year: %d\n", database[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Sorry, no book found with the title \"%s\".\n", search_title);
    }
}

void display_menu() {
    printf("**** Welcome to the Book Database ****\n");
    printf("1. Add a new book\n");
    printf("2. View all books\n");
    printf("3. Search for a book by title\n");
    printf("0. Exit\n");
    printf("Please select an option (0-3): ");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                search_book();
                break;
            case 0:
                printf("Thank you for using the Book Database. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}