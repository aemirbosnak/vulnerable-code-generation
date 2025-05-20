//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100
#define FILENAME "library.dat"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

void addBook();
void listBooks();
void searchBook();
void deleteBook();
void saveBooks(Book books[], int count);
int loadBooks(Book books[]);

int main() {
    int choice;

    do {
        printf("\n--- Mini Library Management System ---\n");
        printf("1. Add a Book\n");
        printf("2. List All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Delete a Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting the Mini Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook() {
    Book newBook;
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        perror("Failed to open file for adding book");
        return;
    }
    
    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // remove newline

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // remove newline

    fwrite(&newBook, sizeof(Book), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void listBooks() {
    Book books[MAX_BOOKS];
    int count = loadBooks(books);
    
    if (count == 0) {
        printf("No books found in the library.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. '%s' by %s\n", i + 1, books[i].title, books[i].author);
    }
}

void searchBook() {
    Book books[MAX_BOOKS];
    int count = loadBooks(books);
    
    if (count == 0) {
        printf("No books found in the library.\n");
        return;
    }

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search for: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, searchTitle) == 0) {
            printf("Book found: '%s' by %s\n", books[i].title, books[i].author);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Book not found in the library.\n");
    }
}

void deleteBook() {
    Book books[MAX_BOOKS];
    int count = loadBooks(books);
    
    if (count == 0) {
        printf("No books found in the library.\n");
        return;
    }

    listBooks();
    int deleteIndex;
    printf("Enter the number of the book to delete: ");
    scanf("%d", &deleteIndex);
    
    if (deleteIndex < 1 || deleteIndex > count) {
        printf("Invalid book number.\n");
        return;
    }

    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        perror("Failed to open file for deleting book");
        return;
    }

    // Write all books except the deleted one back into the file
    for (int i = 0; i < count; i++) {
        if (i != deleteIndex - 1) {
            fwrite(&books[i], sizeof(Book), 1, file);
        }
    }

    fclose(file);
    printf("Book deleted successfully!\n");
}

int loadBooks(Book books[]) {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        return 0;  // No books found (file does not exist)
    }

    int count = 0;
    while (fread(&books[count], sizeof(Book), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}