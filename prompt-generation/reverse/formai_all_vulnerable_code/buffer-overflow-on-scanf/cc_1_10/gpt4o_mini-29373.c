//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addBook(Database* db, const char* title, const char* author, int year) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full! Cannot add more books.\n");
        return;
    }
    strncpy(db->books[db->count].title, title, TITLE_LENGTH);
    strncpy(db->books[db->count].author, author, AUTHOR_LENGTH);
    db->books[db->count].year = year;
    db->count++;
    printf("Book added: %s by %s (%d)\n", title, author, year);
}

void viewBooks(Database* db) {
    if (db->count == 0) {
        printf("No books in the database.\n");
        return;
    }
    printf("\nBooks in Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Title: %s, Author: %s, Year: %d\n", 
               db->books[i].title, db->books[i].author, db->books[i].year);
    }
}

void searchBook(Database* db, const char* query) {
    int found = 0;
    printf("\nSearch Results for '%s':\n", query);
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->books[i].title, query) != NULL || 
            strstr(db->books[i].author, query) != NULL) {
            printf("Title: %s, Author: %s, Year: %d\n", 
                   db->books[i].title, db->books[i].author, db->books[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found with that query.\n");
    }
}

void menu() {
    printf("\nLibrary Database System\n");
    printf("1. Add Book\n");
    printf("2. View All Books\n");
    printf("3. Search for a Book\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf(" %[^\n]", title);  // Read string with spaces
                printf("Enter author: ");
                scanf(" %[^\n]", author);  // Read string with spaces
                printf("Enter year: ");
                scanf("%d", &year);
                addBook(&db, title, author, year);
                break;
            case 2:
                viewBooks(&db);
                break;
            case 3:
                printf("Enter title or author to search: ");
                char query[TITLE_LENGTH + AUTHOR_LENGTH];
                scanf(" %[^\n]", query);
                searchBook(&db, query);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}