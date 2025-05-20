//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: real-life
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

// Function declarations
void addBook();
void viewBooks();
void searchBook();
void clearInputBuffer();

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a new book\n");
        printf("2. View all books\n");
        printf("3. Search for a book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer before taking string input

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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    Book newBook;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author's name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    clearInputBuffer(); // Clear input buffer

    fprintf(file, "%s|%s|%d\n", newBook.title, newBook.author, newBook.year);
    
    printf("Book added successfully!\n");
    fclose(file);
}

void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        if (token != NULL) {
            printf("Title: %s\n", token);
            token = strtok(NULL, "|");
            if (token != NULL) {
                printf("Author: %s\n", token);
                token = strtok(NULL, "|");
                if (token != NULL) {
                    printf("Year: %s\n", token);
                }
            }
        }
        printf("-------------------------\n");
    }
    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter book title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        if (token != NULL && strcasecmp(token, searchTitle) == 0) {
            printf("Book found!\n");
            printf("Title: %s\n", token);
            token = strtok(NULL, "|");
            if (token != NULL) {
                printf("Author: %s\n", token);
                token = strtok(NULL, "|");
                if (token != NULL) {
                    printf("Year: %s\n", token);
                }
            }
            found = 1;
            break; // Exit after finding the first match
        }
    }

    if (!found) {
        printf("No book found with the title '%s'.\n", searchTitle);
    }

    fclose(file);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}