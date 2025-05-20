//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_BOOKS 1000
#define FILE_NAME "library.dat"

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
} Book;

void addBook(FILE *file);
void listBooks(FILE *file);
void searchBook(FILE *file, const char *title);
void clearBuffer();

int main() {
    int choice;
    FILE *file;

    // Opening the file in binary read/write mode
    file = fopen(FILE_NAME, "ab+");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                listBooks(file);
                break;
            case 3: {
                char title[MAX_TITLE];
                printf("Enter title of the book to search: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                searchBook(file, title);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    fclose(file);
    return EXIT_SUCCESS;
}

void addBook(FILE *file) {
    Book book;

    printf("Enter book title: ");
    fgets(book.title, MAX_TITLE, stdin);
    book.title[strcspn(book.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(book.author, MAX_AUTHOR, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &book.year);
    clearBuffer(); // Clear input buffer after integer input

    // Move the file pointer to the end and write new book
    fseek(file, 0, SEEK_END);
    fwrite(&book, sizeof(Book), 1, file);
    printf("Book added successfully!\n");
}

void listBooks(FILE *file) {
    Book book;
    rewind(file); // Move to the beginning of the file

    printf("\nList of Books:\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
    }
}

void searchBook(FILE *file, const char *title) {
    Book book;
    rewind(file); // Move to the beginning of the file

    int found = 0;
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcasecmp(book.title, title) == 0) {
            printf("Book Found: Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with the title: %s\n", title);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Clear the input buffer
}