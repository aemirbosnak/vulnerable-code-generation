//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50
#define ID_LENGTH 10

typedef struct {
    char id[ID_LENGTH];
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} BookDatabase;

void initializeDatabase(BookDatabase *db) {
    db->count = 0;
}

void addBook(BookDatabase *db) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full. Cannot add more books.\n");
        return;
    }
    
    Book newBook;
    printf("Enter Book ID: ");
    scanf("%s", newBook.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook.title);  // Reads until newline
    printf("Enter Book Author: ");
    scanf(" %[^\n]", newBook.author);  // Reads until newline
    
    db->books[db->count] = newBook;
    db->count++;
    printf("Book added successfully!\n");
}

void viewBooks(const BookDatabase *db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nBooks in Database:\n");
    printf("%-10s %-50s %-50s\n", "Book ID", "Title", "Author");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < db->count; i++) {
        printf("%-10s %-50s %-50s\n", db->books[i].id, db->books[i].title, db->books[i].author);
    }
    printf("---------------------------------------------------------------\n");
}

void searchBook(const BookDatabase *db) {
    if (db->count == 0) {
        printf("No books in the database to search.\n");
        return;
    }

    char searchId[ID_LENGTH];
    printf("Enter Book ID to search: ");
    scanf("%s", searchId);
    
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->books[i].id, searchId) == 0) {
            printf("Book found!\n");
            printf("Book ID: %s\n", db->books[i].id);
            printf("Title: %s\n", db->books[i].title);
            printf("Author: %s\n", db->books[i].author);
            return;
        }
    }
    printf("Book with ID %s not found in the database.\n", searchId);
}

void displayMenu() {
    printf("\n--- Book Database Menu ---\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
}

int main() {
    BookDatabase db;
    initializeDatabase(&db);
    
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                viewBooks(&db);
                break;
            case 3:
                searchBook(&db);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}