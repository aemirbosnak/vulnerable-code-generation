//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

void addBook(Book *library, int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = *bookCount + 1; // Assigning a new ID

    printf("Enter book title: ");
    getchar(); // Clear newline character from buffer
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    library[*bookCount] = newBook;
    (*bookCount)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book *library, int bookCount) {
    printf("\nList of books in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

void deleteBook(Book *library, int *bookCount, int id) {
    int found = 0;
    for (int i = 0; i < *bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < *bookCount - 1; j++) {
                library[j] = library[j + 1]; // Shift books left
            }
            (*bookCount)--;
            printf("Book with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void saveToFile(Book *library, int bookCount) {
    FILE *file = fopen("library.dat", "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(library, sizeof(Book), bookCount, file);
    fclose(file);
    printf("Library data saved to file.\n");
}

void loadFromFile(Book *library, int *bookCount) {
    FILE *file = fopen("library.dat", "rb");
    if (!file) {
        printf("No existing library data found.\n");
        return;
    }
    *bookCount = fread(library, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    printf("Library data loaded successfully. %d books found.\n", *bookCount);
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice, id;

    loadFromFile(library, &bookCount);
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(library, &bookCount, id);
                break;
            case 4:
                saveToFile(library, bookCount);
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}