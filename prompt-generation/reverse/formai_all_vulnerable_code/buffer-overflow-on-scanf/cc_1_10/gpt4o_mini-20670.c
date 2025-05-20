//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

void addBook(FILE *file);
void displayBooks(FILE *file);
void searchBook(FILE *file);
void clearInputBuffer();

int main() {
    FILE *file;
    int choice;

    // Open the file in append and read mode.
    file = fopen("library.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Get user choice
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 4: ");
            clearInputBuffer();
        }
        
        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                displayBooks(file);
                break;
            case 3:
                searchBook(file);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    fclose(file);
    return 0;
}

// Function to add a book to the file.
void addBook(FILE *file) {
    Book newBook;

    // Clear the input buffer first.
    clearInputBuffer();
    
    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove trailing newline

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove trailing newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    // Write the book information to the file.
    fprintf(file, "%s;%s;%d\n", newBook.title, newBook.author, newBook.year);
    fflush(file); // Ensure the data is written now

    printf("Book added successfully!\n");
}

// Function to display all books in the file.
void displayBooks(FILE *file) {
    char line[256];
    rewind(file); // Go back to the beginning of the file

    printf("\n--- List of Books ---\n");
    while (fgets(line, sizeof(line), file)) {
        char *token;
        Book book;

        // Parse the line
        token = strtok(line, ";");
        if (token != NULL) {
            strncpy(book.title, token, MAX_TITLE_LENGTH);
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            strncpy(book.author, token, MAX_AUTHOR_LENGTH);
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            book.year = atoi(token);
        }

        printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
    }
}

// Function to search for a book by title.
void searchBook(FILE *file) {
    char searchTitle[MAX_TITLE_LENGTH];
    char line[256];
    int found = 0;

    clearInputBuffer();
    printf("Enter the book title to search for: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove trailing newline

    rewind(file); // Go back to the beginning of the file

    while (fgets(line, sizeof(line), file)) {
        char *token;
        Book book;

        // Parse the line
        token = strtok(line, ";");
        if (token != NULL) {
            strncpy(book.title, token, MAX_TITLE_LENGTH);
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            strncpy(book.author, token, MAX_AUTHOR_LENGTH);
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            book.year = atoi(token);
        }

        // Check if the title matches
        if (strcasecmp(book.title, searchTitle) == 0) {
            printf("Book Found! Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with the title: %s\n", searchTitle);
    }
}

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}