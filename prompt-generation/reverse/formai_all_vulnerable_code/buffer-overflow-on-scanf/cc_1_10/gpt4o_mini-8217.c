//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int id;
} Book;

void addBook();
void viewBooks();
void deleteBook();
void clearBuffer();

const char *filename = "library.dat";

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline character left in the buffer

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addBook() {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    // Generate book ID by counting existing books
    fseek(file, 0, SEEK_END);
    newBook.id = ftell(file) / sizeof(Book) + 1;

    fwrite(&newBook, sizeof(Book), 1, file);
    fclose(file);

    printf("Book added successfully! ID: %d\n", newBook.id);
}

void viewBooks() {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Book book;
    printf("\n--- List of Books ---\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("ID: %d | Title: %s | Author: %s\n", book.id, book.title, book.author);
    }

    fclose(file);
}

void deleteBook() {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Unable to open temporary file");
        fclose(file);
        return;
    }

    int idToDelete;
    printf("Enter ID of book to delete: ");
    scanf("%d", &idToDelete);
    clearBuffer(); // Clear newline character left in the buffer

    Book book;
    int found = 0;

    while (fread(&book, sizeof(Book), 1, file)) {
        if (book.id == idToDelete) {
            found = 1;
            printf("Deleted Book - ID: %d | Title: %s | Author: %s\n", book.id, book.title, book.author);
            continue; // Skip writing this book to temp file
        }
        fwrite(&book, sizeof(Book), 1, tempFile);
    }

    if (!found) {
        printf("Book with ID %d not found.\n", idToDelete);
    }

    fclose(file);
    fclose(tempFile);
    remove(filename); // Remove original file
    rename("temp.dat", filename); // Rename temp file to original

    printf("Operation completed.\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}