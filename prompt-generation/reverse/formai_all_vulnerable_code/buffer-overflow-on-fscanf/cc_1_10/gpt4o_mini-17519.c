//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: retro
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

void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void saveBook(Book book);
void loadBooks();
int bookExists(char *title);

int main() {
    int choice;

    while (1) {
        printf("\n--- Welcome to the Retro Library System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addBook() {
    Book book;
    printf("Enter book title: ");
    fgets(book.title, TITLE_LENGTH, stdin);
    book.title[strcspn(book.title, "\n")] = 0;  // Remove the trailing newline

    if (bookExists(book.title)) {
        printf("Book already exists in the library!\n");
        return;
    }

    printf("Enter author name: ");
    fgets(book.author, AUTHOR_LENGTH, stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove the trailing newline

    printf("Enter publication year: ");
    scanf("%d", &book.year);
    getchar(); // consume newline character

    saveBook(book);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file for reading!\n");
        return;
    }

    Book book;
    printf("\n--- List of Books ---\n");
    while (fscanf(file, "%99[^\n]\n%99[^\n]\n%d\n", book.title, book.author, &book.year) != EOF) {
        printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
    }

    fclose(file);
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove the trailing newline

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file for reading!\n");
        return;
    }

    Book book;
    int found = 0;
    while (fscanf(file, "%99[^\n]\n%99[^\n]\n%d\n", book.title, book.author, &book.year) != EOF) {
        if (strcmp(book.title, searchTitle) == 0) {
            printf("Found: Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in the library.\n");
    }

    fclose(file);
}

void deleteBook() {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter the title of the book to delete: ");
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove the trailing newline

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file for reading!\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Could not open temporary file for writing!\n");
        fclose(file);
        return;
    }

    Book book;
    int found = 0;
    while (fscanf(file, "%99[^\n]\n%99[^\n]\n%d\n", book.title, book.author, &book.year) != EOF) {
        if (strcmp(book.title, deleteTitle) == 0) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%s\n%s\n%d\n", book.title, book.author, book.year);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found in the library.\n");
        remove("temp.txt");
    }
}

void saveBook(Book book) {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Could not open file for writing!\n");
        return;
    }

    fprintf(file, "%s\n%s\n%d\n", book.title, book.author, book.year);
    fclose(file);
}

int bookExists(char *title) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return 0; // return false if file doesn't exist
    }

    Book book;
    while (fscanf(file, "%99[^\n]\n%99[^\n]\n%d\n", book.title, book.author, &book.year) != EOF) {
        if (strcmp(book.title, title) == 0) {
            fclose(file);
            return 1; // return true if found
        }
    }

    fclose(file);
    return 0; // return false if not found
}