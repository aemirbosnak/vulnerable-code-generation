//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define FILENAME "library.dat"

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

// Function prototypes
void addBook();
void viewBooks();
void deleteBook();
void clearInputBuffer();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer to prevent issues with fgets

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add a Book\n");
    printf("2. View Books\n");
    printf("3. Delete a Book\n");
    printf("4. Exit\n");
}

void addBook() {
    Book book;
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter book title: ");
    fgets(book.title, TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Remove newline character
    printf("Enter author's name: ");
    fgets(book.author, AUTHOR_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // Remove newline character

    fwrite(&book, sizeof(Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void viewBooks() {
    Book book;
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- List of Books ---\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s, Author: %s\n", book.title, book.author);
    }
    fclose(file);
}

void deleteBook() {
    Book book;
    FILE *file = fopen(FILENAME, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char titleToDelete[TITLE_LENGTH];
    printf("Enter title of the book to delete: ");
    fgets(titleToDelete, TITLE_LENGTH, stdin);
    titleToDelete[strcspn(titleToDelete, "\n")] = '\0'; // Remove newline character

    int found = 0;
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcmp(book.title, titleToDelete) != 0) {
            fwrite(&book, sizeof(Book), 1, tempFile);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(FILENAME); // Remove the original file
    rename("temp.dat", FILENAME); // Rename temp file to the original file name

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found.\n");
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Clear the input buffer
}