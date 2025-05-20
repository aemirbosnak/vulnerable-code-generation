//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define FILENAME "library.txt"

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook();
void viewBooks();
void searchBooks();

int main() {
    int choice;

    while (1) {
        printf("\n=== Simple Library System ===\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBooks();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void addBook() {
    Book book;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(book.title, TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // remove newline

    printf("Enter author's name: ");
    fgets(book.author, AUTHOR_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // remove newline

    printf("Enter year of publication: ");
    scanf("%d", &book.year);
    getchar(); // to consume newline

    fwrite(&book, sizeof(Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void viewBooks() {
    Book book;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\n=== List of Books ===\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s\nAuthor: %s\nYear: %d\n\n", book.title, book.author, book.year);
    }
    fclose(file);
}

void searchBooks() {
    char query[TITLE_LENGTH];
    Book book;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("Enter book title to search: ");
    fgets(query, TITLE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // remove newline

    int found = 0;
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strstr(book.title, query) != NULL) {
            printf("Title: %s\nAuthor: %s\nYear: %d\n\n", book.title, book.author, book.year);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching the title '%s'.\n", query);
    }

    fclose(file);
}