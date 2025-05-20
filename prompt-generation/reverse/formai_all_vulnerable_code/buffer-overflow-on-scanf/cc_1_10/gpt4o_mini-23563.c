//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_BOOKS 100
#define FILENAME "books.dat"

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
} Book;

void addBook(FILE *file);
void listBooks(FILE *file);
void searchBooks(FILE *file);
void deleteBook(FILE *file);
void displayMenu();

int main() {
    FILE *file;
    int choice;

    // Open the file in binary mode. Create if it doesn't exist.
    file = fopen(FILENAME, "a+b");
    if (file == NULL) {
        printf("Could not open file %s\n", FILENAME);
        return 1;
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                listBooks(file);
                break;
            case 3:
                searchBooks(file);
                break;
            case 4:
                deleteBook(file);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add a Book\n");
    printf("2. List Books\n");
    printf("3. Search Books\n");
    printf("4. Delete a Book\n");
    printf("5. Exit\n");
}

void addBook(FILE *file) {
    Book book;

    printf("Enter book title: ");
    fgets(book.title, MAX_TITLE, stdin);
    strtok(book.title, "\n"); // Remove newline character

    printf("Enter author name: ");
    fgets(book.author, MAX_AUTHOR, stdin);
    strtok(book.author, "\n"); // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &book.year);
    getchar(); // To consume the newline character

    fseek(file, 0, SEEK_END);
    fwrite(&book, sizeof(Book), 1, file);
    printf("Book added successfully!\n");
}

void listBooks(FILE *file) {
    Book book;
    rewind(file);
    
    printf("\nList of Books:\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
    }
}

void searchBooks(FILE *file) {
    Book book;
    char searchTitle[MAX_TITLE];
    int found = 0;

    printf("Enter the title of the book to search: ");
    fgets(searchTitle, MAX_TITLE, stdin);
    strtok(searchTitle, "\n"); // Remove newline character

    rewind(file);
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcmp(book.title, searchTitle) == 0) {
            printf("Book found!\n");
            printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook(FILE *file) {
    Book book;
    FILE *tempFile;
    char deleteTitle[MAX_TITLE];
    int found = 0;

    printf("Enter the title of the book to delete: ");
    fgets(deleteTitle, MAX_TITLE, stdin);
    strtok(deleteTitle, "\n"); // Remove newline character

    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Could not open temporary file.\n");
        return;
    }

    rewind(file);
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcmp(book.title, deleteTitle) != 0) {
            fwrite(&book, sizeof(Book), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    
    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found.\n");
        remove("temp.dat"); // Clean up if book not found
    }
    
    file = fopen(FILENAME, "a+b"); // Re-open the main file
}