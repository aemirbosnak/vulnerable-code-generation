//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define FILENAME "books_database.txt"

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nBooks in database:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: '%s', Author: '%s'\n", books[i].id, books[i].title, books[i].author);
    }
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Database is full, unable to add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = *count + 1; // Simple ID generation based on position
    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter author name: ");
    scanf(" %[^\n]", newBook.author);

    books[*count] = newBook;
    (*count)++;
    printf("Book added! ID: %d\n", newBook.id);
}

void saveToFile(Book books[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s\n", books[i].id, books[i].title, books[i].author);
    }
    fclose(file);
    printf("Database saved to %s\n", FILENAME);
}

void loadFromFile(Book books[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No existing database found. Starting a new one.\n");
        return;
    }

    while (fscanf(file, "%d,%99[^,],%99[^\n]\n", &books[*count].id, books[*count].title, books[*count].author) == 3) {
        (*count)++;
        if (*count >= MAX_BOOKS) break; // Prevent overflow
    }
    fclose(file);
    printf("Loaded %d books from %s\n", *count, FILENAME);
}

void searchBook(Book books[], int count) {
    char query[TITLE_LENGTH];
    printf("Enter title or author to search: ");
    scanf(" %[^\n]", query);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, query) || strstr(books[i].author, query)) {
            printf("Found Book -> ID: %d, Title: '%s', Author: '%s'\n", books[i].id, books[i].title, books[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching books found.\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int bookCount = 0;
    loadFromFile(books, &bookCount);

    int choice;
    while (1) {
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Save Books\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(books, &bookCount); break;
            case 2: displayBooks(books, bookCount); break;
            case 3: searchBook(books, bookCount); break;
            case 4: saveToFile(books, bookCount); break;
            case 5: 
                saveToFile(books, bookCount);
                printf("Exiting program. Goodbye!\n");
                return 0;
            default: 
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}