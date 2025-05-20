//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: scalable
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

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    Book new_book;
    printf("Enter book title: ");
    getchar();  // Consume the leftover newline character
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0';  // Remove newline character

    printf("Enter author's name: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';  // Remove newline character

    printf("Enter year of publication: ");
    scanf("%d", &new_book.year);

    library[book_count] = new_book;
    book_count++;

    printf("Book added successfully!\n");
}

void view_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of books in the library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", library[i].title, library[i].author, library[i].year);
    }
}

void search_book() {
    char search_title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search for: ");
    getchar();  // Consume the leftover newline character
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    search_title[strcspn(search_title, "\n")] = '\0';  // Remove newline character

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Book found: Title: %s, Author: %s, Year: %d\n", library[i].title, library[i].author, library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No book found with the title \"%s\".\n", search_title);
    }
}

void display_menu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("Select an option: ");
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
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}