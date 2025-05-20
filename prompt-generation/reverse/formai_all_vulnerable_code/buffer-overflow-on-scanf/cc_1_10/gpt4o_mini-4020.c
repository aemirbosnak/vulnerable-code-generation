//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 30
#define FILENAME "library.dat"

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

void addBook();
void viewBooks();
void saveBookToFile(Book book);
void loadBooksFromFile(Book *books, int *count);
void displayBook(Book book);

int main() {
    int choice;

    while (1) {
        printf("\n== Library Management System ==\n");
        printf("1. Add a Book\n");
        printf("2. View all Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addBook() {
    Book newBook;

    printf("Enter book title: ");
    getchar(); // To consume the newline character left by previous scanf
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    saveBookToFile(newBook);
    printf("Book added successfully!\n");
}

void saveBookToFile(Book book) {
    FILE *file = fopen(FILENAME, "ab"); // Append binary mode
    if (file == NULL) {
        perror("Could not open file");
        return;
    }
    fwrite(&book, sizeof(Book), 1, file);
    fclose(file);
}

void viewBooks() {
    Book books[MAX_BOOKS];
    int count = 0;

    loadBooksFromFile(books, &count);
    if (count == 0) {
        printf("No books found!\n");
        return;
    }

    printf("\n== List of Books ==\n");
    for (int i = 0; i < count; i++) {
        displayBook(books[i]);
    }
}

void loadBooksFromFile(Book *books, int *count) {
    FILE *file = fopen(FILENAME, "rb"); // Read binary mode
    if (file == NULL) {
        perror("Could not open file");
        return;
    }
    
    while (fread(&books[*count], sizeof(Book), 1, file)) {
        (*count)++;
        if (*count >= MAX_BOOKS) break; // Prevent overflow
    }
    fclose(file);
}

void displayBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("-------------------------------\n");
}