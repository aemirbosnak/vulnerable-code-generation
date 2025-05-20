//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100
#define FILENAME "library.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

void addBook(FILE *file) {
    Book book;
    printf("Enter book title: ");
    scanf(" %[^\n]", book.title); // Read title including spaces
    printf("Enter author name: ");
    scanf(" %[^\n]", book.author); // Read author name including spaces
    printf("Enter year of publication: ");
    scanf("%d", &book.year);

    fwrite(&book, sizeof(Book), 1, file);
    printf("Book added successfully!\n");
}

void listBooks(FILE *file) {
    Book book;
    rewind(file); // Move the file pointer to the beginning
    printf("\nBook List:\n");
    printf("--------------------------------------------------\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Year: %d\n", book.year);
        printf("--------------------------------------------------\n");
    }
}

void findBook(FILE *file) {
    char title[MAX_TITLE_LENGTH];
    Book book;
    int found = 0;

    printf("Enter the title of the book to find: ");
    scanf(" %[^\n]", title);

    rewind(file); // Move to the beginning of the file
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcmp(book.title, title) == 0) {
            printf("Book Found!\n");
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Year: %d\n", book.year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void deleteBook(FILE *file) {
    FILE *tempFile = fopen("temp.txt", "wb");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    Book book;
    int found = 0;

    printf("Enter the title of the book to delete: ");
    scanf(" %[^\n]", title);

    rewind(file);
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcmp(book.title, title) != 0) {
            fwrite(&book, sizeof(Book), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(tempFile);
    fclose(file);
    remove(FILENAME); // Delete original file
    rename("temp.txt", FILENAME); // Rename temp file

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found for deletion!\n");
    }
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("-------------------------\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Find Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FILE *file = fopen(FILENAME, "ab+"); // Open file for appending and reading
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                listBooks(file);
                break;
            case 3:
                findBook(file);
                break;
            case 4:
                deleteBook(file);
                file = fopen(FILENAME, "ab+"); // Reopen for further operations
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}