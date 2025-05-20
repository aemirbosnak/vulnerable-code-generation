//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
} Book;

void addBook(const char *filename);
void listBooks(const char *filename);
void searchBook(const char *filename);
void displayBook(const Book *book);
void clearInputBuffer();

int main() {
    int choice;
    const char *filename = "library.txt";

    while (1) {
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook(filename);
                break;
            case 2:
                listBooks(filename);
                break;
            case 3:
                searchBook(filename);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addBook(const char *filename) {
    Book newBook;
    FILE *file = fopen(filename, "a");

    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, MAX_TITLE_LEN, stdin);
    strtok(newBook.title, "\n"); // remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, MAX_AUTHOR_LEN, stdin);
    strtok(newBook.author, "\n"); // remove newline character

    fprintf(file, "%s;%s\n", newBook.title, newBook.author);
    fclose(file);
    printf("Book added successfully!\n");
}

void listBooks(const char *filename) {
    char line[256];
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("\nList of Books:\n");
    while (fgets(line, sizeof(line), file)) {
        Book book;
        sscanf(line, "%99[^;];%99[^\n]", book.title, book.author);
        displayBook(&book);
    }

    fclose(file);
}

void searchBook(const char *filename) {
    char title[MAX_TITLE_LEN];
    char line[256];
    FILE *file = fopen(filename, "r");
    int found = 0;

    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Enter Book Title to Search: ");
    fgets(title, MAX_TITLE_LEN, stdin);
    strtok(title, "\n"); // remove newline character

    while (fgets(line, sizeof(line), file)) {
        Book book;
        sscanf(line, "%99[^;];%99[^\n]", book.title, book.author);
        if (strcasecmp(book.title, title) == 0) {
            printf("\nBook Found:\n");
            displayBook(&book);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }

    fclose(file);
}

void displayBook(const Book *book) {
    printf("Title: %s, Author: %s\n", book->title, book->author);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}