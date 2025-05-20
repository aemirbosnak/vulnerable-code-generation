//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_ISBN_LENGTH 20
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
} Book;

void addBook(FILE *file);
void viewBooks(FILE *file);
void searchBook(FILE *file);
void clearBuffer();

int main() {
    FILE *file;
    int choice;

    file = fopen("library.txt", "a+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // To clear input buffer

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                viewBooks(file);
                break;
            case 3:
                searchBook(file);
                break;
            case 4:
                fclose(file);
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(FILE *file) {
    Book book;
    printf("Enter book title: ");
    fgets(book.title, MAX_TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(book.author, MAX_AUTHOR_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline character

    printf("Enter ISBN: ");
    fgets(book.isbn, MAX_ISBN_LENGTH, stdin);
    book.isbn[strcspn(book.isbn, "\n")] = 0; // Remove newline character

    fprintf(file, "%s;%s;%s\n", book.title, book.author, book.isbn);
    printf("Book added successfully!\n");
}

void viewBooks(FILE *file) {
    rewind(file); // Move to the beginning of the file

    char line[256];
    printf("\nList of Books:\n");
    printf("Title;Author;ISBN\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

void searchBook(FILE *file) {
    char searchTitle[MAX_TITLE_LENGTH];
    char line[256];
    int found = 0;

    printf("Enter the title of the book to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    rewind(file); // Move to the beginning of the file

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, searchTitle) != NULL) {
            printf("Found: %s", line);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with the title '%s'.\n", searchTitle);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}