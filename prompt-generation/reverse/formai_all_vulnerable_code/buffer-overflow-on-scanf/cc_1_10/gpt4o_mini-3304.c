//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

void addBook();
void viewBooks();
void deleteBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== Welcome to the Library Management System ===\n");
        printf("1. Add a Book\n");
        printf("2. View Books\n");
        printf("3. Delete a Book\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        
        scanf("%d", &choice);
        clearInputBuffer();  // Clear the input buffer to avoid issues with scanf

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
                printf("Thank you for using the Library Management System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void addBook() {
    FILE *file = fopen("library.dat", "ab"); // Append mode to add a book
    if (!file) {
        perror("Could not open file");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove trailing newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove trailing newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    clearInputBuffer();  // Clear the input buffer

    fwrite(&newBook, sizeof(Book), 1, file); // Write book data to file
    fclose(file); // Close the file

    printf("Book added successfully!\n");
}

void viewBooks() {
    FILE *file = fopen("library.dat", "rb"); // Read mode to view books
    if (!file) {
        perror("Could not open file");
        return;
    }

    Book temp;
    printf("\n=== List of Books ===\n");
    while (fread(&temp, sizeof(Book), 1, file)) {
        printf("Title: %s, Author: %s, Year: %d\n", temp.title, temp.author, temp.year);
    }
    fclose(file); // Close the file
}

void deleteBook() {
    FILE *file = fopen("library.dat", "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Could not open temporary file");
        fclose(file);
        return;
    }

    char title[TITLE_LEN];
    printf("Enter the title of the book to delete: ");
    fgets(title, TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    Book temp;
    int found = 0;
    while (fread(&temp, sizeof(Book), 1, file)) {
        if (strcmp(temp.title, title) != 0) {
            fwrite(&temp, sizeof(Book), 1, tempFile); // Write to temporary file if not matching
        } else {
            found = 1; // Book found
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("library.dat"); // Remove original file
    rename("temp.dat", "library.dat"); // Rename temporary file to original file

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found!\n");
    }
}