//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define FILENAME "library.txt"

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

void display_menu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void add_book() {
    Book book;
    FILE *file;

    file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    printf("Enter book title: ");
    getchar(); // Clear newline from previous input
    fgets(book.title, TITLE_LEN, stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Remove newline character

    printf("Enter author: ");
    fgets(book.author, AUTHOR_LEN, stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &book.year);

    fwrite(&book, sizeof(Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void view_books() {
    Book book;
    FILE *file;

    file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    printf("\n--- List of Books ---\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
    }

    fclose(file);
}

void search_book() {
    char searchTitle[TITLE_LEN];
    Book book;
    FILE *file;

    printf("Enter the title of the book to search: ");
    getchar(); // Clear newline from previous input
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline character

    file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    int found = 0;
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcasecmp(book.title, searchTitle) == 0) {
            printf("Book found! Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with title '%s' not found.\n", searchTitle);
    }

    fclose(file);
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
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}