//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50
#define FILENAME "books.txt"

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

// Function Prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void saveToFile(Book books[], int count);
int loadFromFile(Book books[]);
void clearBuffer();

// Main function
int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a book
void addBook() {
    Book newBook;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    clearBuffer();

    FILE *file = fopen(FILENAME, "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s|%s|%d\n", newBook.title, newBook.author, newBook.year);
    fclose(file);
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count == 0) {
        printf("No books found!\n");
        return;
    }

    printf("\nBooks in the library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s | Author: %s | Year: %d\n", i + 1, books[i].title, books[i].author, books[i].year);
    }
}

// Function to search for a book
void searchBook() {
    char searchTitle[TITLE_LEN];
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count == 0) {
        printf("No books found!\n");
        return;
    }

    printf("Enter the title of the book to search: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, searchTitle) == 0) {
            printf("\nFound Book:\nTitle: %s | Author: %s | Year: %d\n", books[i].title, books[i].author, books[i].year);
            return;
        }
    }

    printf("Book not found!\n");
}

// Function to delete a book
void deleteBook() {
    char deleteTitle[TITLE_LEN];
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count == 0) {
        printf("No books found!\n");
        return;
    }

    printf("Enter the title of the book to delete: ");
    fgets(deleteTitle, TITLE_LEN, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // Remove newline character

    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, deleteTitle) != 0) {
            fprintf(file, "%s|%s|%d\n", books[i].title, books[i].author, books[i].year);
        } else {
            found = 1;
        }
    }

    fclose(file);

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found!\n");
    }
}

// Function to load books from the file
int loadFromFile(Book books[]) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0; // No books found
    }

    int count = 0;
    while (!feof(file) && count < MAX_BOOKS) {
        fscanf(file, " %[^\n]|%[^\n]|%d\n", books[count].title, books[count].author, &books[count].year);
        count++;
    }

    fclose(file);
    return count;
}

// Function to clear input buffer
void clearBuffer() {
    while (getchar() != '\n');
}