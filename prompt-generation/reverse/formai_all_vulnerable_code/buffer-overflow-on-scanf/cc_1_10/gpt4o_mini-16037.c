//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 50
#define AUTHOR_SIZE 30

typedef struct {
    int id;
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

void addBook(Database *db) {
    if (db->count < MAX_BOOKS) {
        Book newBook;
        newBook.id = db->count + 1; // Simple incremental ID
        printf("Enter title: ");
        getchar(); // Consume newline character
        fgets(newBook.title, TITLE_SIZE, stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline

        printf("Enter author: ");
        fgets(newBook.author, AUTHOR_SIZE, stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline

        db->books[db->count] = newBook;
        db->count++;
        printf("Book added successfully!\n");
    } else {
        printf("Database is full, cannot add more books.\n");
    }
}

void viewBooks(const Database *db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }
    printf("Books in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d | Title: %s | Author: %s\n", db->books[i].id, db->books[i].title, db->books[i].author);
    }
}

void searchBook(const Database *db) {
    char searchTitle[TITLE_SIZE];
    printf("Enter title to search: ");
    getchar(); // Consume newline character
    fgets(searchTitle, TITLE_SIZE, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->books[i].title, searchTitle) == 0) {
            printf("Found Book - ID: %d | Title: %s | Author: %s\n",
                   db->books[i].id, db->books[i].title, db->books[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No book found with the title: %s\n", searchTitle);
    }
}

void displayMenu() {
    printf("\n--- Book Database Menu ---\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Database db;
    initDatabase(&db);
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
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
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}