//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100
#define FILENAME "books.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

void addBook();
void viewBooks();
void searchBook();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }

    Book book;
    printf("Enter book title: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = 0; // remove newline character

    printf("Enter author name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = 0; // remove newline character

    fprintf(file, "%s;%s\n", book.title, book.author);
    fclose(file);
    printf("Book added successfully!\n");
}

void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Unable to open file for reading.\n");
        return;
    }

    char line[256];
    printf("\n--- List of Books ---\n");
    while (fgets(line, sizeof(line), file)) {
        char *title = strtok(line, ";");
        char *author = strtok(NULL, ";");

        if (author) {
            printf("Title: %s, Author: %s\n", title, author);
        } else {
            printf("Title: %s (no author)\n", title);
        }
    }

    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Unable to open file for reading.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // remove newline character

    char line[256];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *bookTitle = strtok(line, ";");
        char *author = strtok(NULL, ";");

        if (strcmp(bookTitle, title) == 0) {
            printf("Found Book - Title: %s, Author: %s\n", bookTitle, author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with the title \"%s\".\n", title);
    }

    fclose(file);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}