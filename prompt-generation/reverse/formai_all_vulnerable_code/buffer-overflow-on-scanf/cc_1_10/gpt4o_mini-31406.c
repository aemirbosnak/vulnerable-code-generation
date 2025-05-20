//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int year;
} Book;

void addBook(const char *filename);
void viewBooks(const char *filename);
void searchBook(const char *filename);
void deleteBook(const char *filename);
void clearInputBuffer();

int main() {
    char filename[] = "books.txt";
    int choice;

    do {
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook(filename);
                break;
            case 2:
                viewBooks(filename);
                break;
            case 3:
                searchBook(filename);
                break;
            case 4:
                deleteBook(filename);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Book book;

    printf("Enter book title: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0'; // Remove newline

    printf("Enter author name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0'; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &book.year);
    clearInputBuffer();

    fprintf(file, "%s;%s;%d\n", book.title, book.author, book.year);
    printf("Book added successfully!\n");

    fclose(file);
}

void viewBooks(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("\nList of Books:\n");
    printf("Title;Author;Year\n");
    printf("---------------\n");

    while (fgets(line, sizeof(line), file)) {
        char *title = strtok(line, ";");
        char *author = strtok(NULL, ";");
        char *year = strtok(NULL, ";");

        if (title && author && year) {
            printf("%s; %s; %s", title, author, year);
        }
    }

    fclose(file);
}

void searchBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char title[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int found = 0;

    printf("Enter the title of the book to search: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    while (fgets(line, sizeof(line), file)) {
        char *bookTitle = strtok(line, ";");
        char *author = strtok(NULL, ";");
        char *year = strtok(NULL, ";");

        if (bookTitle && strcmp(bookTitle, title) == 0) {
            printf("Book found: %s; %s; %s", bookTitle, author, year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

void deleteBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return;
    }

    char title[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int found = 0;

    printf("Enter the title of the book to delete: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    while (fgets(line, sizeof(line), file)) {
        char *bookTitle = strtok(line, ";");

        if (bookTitle && strcmp(bookTitle, title) != 0) {
            fputs(line, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);
        rename("temp.txt", filename);
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found.\n");
        remove("temp.txt"); // Clean up temp file
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}