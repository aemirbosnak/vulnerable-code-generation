//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

void addBook(FILE *file);
void viewBooks(FILE *file);
void deleteBook(FILE *file);
void clearBuffer();

int main() {
    FILE *file;
    int choice;

    // Open the library file
    file = fopen("library.txt", "a+");
    if (file == NULL) {
        fprintf(stderr, "Could not open library.txt for reading and writing.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("\n---- Book Library Management System ----\n");
        printf("1. Add a Book\n");
        printf("2. View Books\n");
        printf("3. Delete a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                viewBooks(file);
                break;
            case 3:
                deleteBook(file);
                break;
            case 4:
                fclose(file);
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(FILE *file) {
    Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    clearBuffer();
    printf("Enter Book Title: ");
    fgets(book.title, MAX_TITLE_LENGTH, stdin);
    // Remove newline character from title
    book.title[strcspn(book.title, "\n")] = '\0';
    printf("Enter Book Author: ");
    fgets(book.author, MAX_AUTHOR_LENGTH, stdin);
    // Remove newline character from author
    book.author[strcspn(book.author, "\n")] = '\0';

    fseek(file, 0, SEEK_END); // Move the file pointer to the end of the file
    fwrite(&book, sizeof(Book), 1, file);
    printf("Book added successfully!\n");
}

void viewBooks(FILE *file) {
    Book book;
    fseek(file, 0, SEEK_SET); // Move to the beginning of the file
    printf("\n---- List of Books ----\n");
    while (fread(&book, sizeof(Book), 1, file) == 1) {
        printf("ID: %d | Title: %s | Author: %s\n", book.id, book.title, book.author);
    }
}

void deleteBook(FILE *file) {
    FILE *tempFile;
    Book book;
    int idToDelete, found = 0;

    // Create a temporary file
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "Could not open temporary file for writing.\n");
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d", &idToDelete);

    fseek(file, 0, SEEK_SET); // Move to the beginning of the original file
    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (book.id == idToDelete) {
            found = 1; // Mark as found
            printf("Deleted Book - ID: %d | Title: %s | Author: %s\n", book.id, book.title, book.author);
            continue; // Skip writing this book to temp file
        }
        fwrite(&book, sizeof(Book), 1, tempFile); // Write to temporary file
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temp file
    remove("library.txt");
    rename("temp.txt", "library.txt");
    
    // Reopen the library file for read/write
    file = fopen("library.txt", "a+");
    if (file == NULL) {
        fprintf(stderr, "Could not open library.txt for reading and writing.\n");
        exit(EXIT_FAILURE);
    }

    if (found) {
        printf("Book with ID %d deleted successfully!\n", idToDelete);
    } else {
        printf("No book found with ID %d.\n", idToDelete);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}