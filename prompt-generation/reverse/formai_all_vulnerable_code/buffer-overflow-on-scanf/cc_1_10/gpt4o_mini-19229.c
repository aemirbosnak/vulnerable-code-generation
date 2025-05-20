//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: curious
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

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addBook(FILE *file) {
    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove trailing newline

    printf("Enter author: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove trailing newline

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    clearInputBuffer();

    fwrite(&newBook, sizeof(Book), 1, file);
    printf("Book added successfully!\n");
}

void displayBooks(FILE *file) {
    fseek(file, 0, SEEK_SET);
    Book book;
    int count = 0;

    printf("\n--- List of Books ---\n");
    while (fread(&book, sizeof(Book), 1, file) == 1) {
        printf("%d. %s by %s (%d)\n", ++count, book.title, book.author, book.year);
    }

    if (count == 0) {
        printf("No books found in the library.\n");
    }
}

void searchBook(FILE *file) {
    char searchTerm[TITLE_LEN];
    printf("Enter book title or author to search: ");
    fgets(searchTerm, TITLE_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;

    fseek(file, 0, SEEK_SET);
    Book book;
    int found = 0;

    printf("\n--- Search Results ---\n");
    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (strstr(book.title, searchTerm) || strstr(book.author, searchTerm)) {
            printf("Found: %s by %s (%d)\n", book.title, book.author, book.year);
            found = 1;
        }
    }

    if (!found) {
        printf("No books matching your search were found.\n");
    }
}

void deleteBook(FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        perror("Failed to create temporary file");
        return;
    }

    char titleToDelete[TITLE_LEN];
    printf("Enter title of the book to delete: ");
    fgets(titleToDelete, TITLE_LEN, stdin);
    titleToDelete[strcspn(titleToDelete, "\n")] = 0;

    fseek(file, 0, SEEK_SET);
    Book book;
    int found = 0;

    while (fread(&book, sizeof(Book), 1, file) == 1) {
        if (strcmp(book.title, titleToDelete) == 0) {
            found = 1;
            printf("Deleted: %s by %s (%d)\n", book.title, book.author, book.year);
            continue; // Skip writing this book to temporary file
        }
        fwrite(&book, sizeof(Book), 1, tempFile);
    }

    if (!found) {
        printf("No book found with title '%s'.\n", titleToDelete);
    }

    fclose(tempFile);
    fclose(file);

    // Remove the original file and rename the temporary file
    remove("books.dat");
    rename("temp.dat", "books.dat");

    printf("Update complete! Remaining books:");
    file = fopen("books.dat", "rb");
    displayBooks(file);
}

int main() {
    FILE *file = fopen("books.dat", "ab+");
    if (file == NULL) {
        perror("Failed to open the file");
        return EXIT_FAILURE;
    }

    int choice;
    while (1) {
        printf("\n--- Book Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

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
                deleteBook(file);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                fclose(file);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}