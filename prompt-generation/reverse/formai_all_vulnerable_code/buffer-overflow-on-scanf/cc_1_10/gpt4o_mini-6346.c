//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

// Function declarations
void addBook(Book *library, int *count);
void viewBooks(Book *library, int count);
void searchBook(Book *library, int count);
void saveBooksToFile(Book *library, int count);
void loadBooksFromFile(Book *library, int *count);
void displayMenu();

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    loadBooksFromFile(library, &count);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character after entering the choice

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                viewBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                saveBooksToFile(library, count);
                printf("Books saved to file.\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Save Books to File\n");
    printf("0. Exit\n");
}

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = *count + 1;

    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  // remove newline

    printf("Enter book author: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';  // remove newline

    library[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book *library, int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n--- List of Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

void searchBook(Book *library, int count) {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';  // remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Book found: ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void saveBooksToFile(Book *library, int count) {
    FILE *file = fopen("library.dat", "wb");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(library, sizeof(Book), count, file);
    fclose(file);
}

void loadBooksFromFile(Book *library, int *count) {
    FILE *file = fopen("library.dat", "rb");
    if (!file) {
        printf("No previous data found.\n");
        return;
    }
    *count = fread(library, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
}