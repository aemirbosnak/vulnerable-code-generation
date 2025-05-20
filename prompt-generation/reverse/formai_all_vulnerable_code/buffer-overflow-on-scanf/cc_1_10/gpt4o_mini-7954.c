//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;
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
    printf("Enter book title: ");
    getchar(); // To consume newline character left by previous input
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);

    db->books[db->count] = newBook;
    db->count++;
    printf("Book added successfully!\n");
}

void displayBooks(const BookDatabase *db) {
    if (db->count == 0) {
        printf("No books in database.\n");
        return;
    }

    printf("\nBooks in Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Book %d: \n", i + 1);
        printf("  Title: %s\n", db->books[i].title);
        printf("  Author: %s\n", db->books[i].author);
        printf("  Year: %d\n\n", db->books[i].year);
    }
}

void searchBook(const BookDatabase *db) {
    if (db->count == 0) {
        printf("No books in database.\n");
        return;
    }

    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // To consume the newline from previous input
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strncasecmp(db->books[i].title, searchTitle, TITLE_LENGTH) == 0) {
            printf("Book Found: \n");
            printf("  Title: %s\n", db->books[i].title);
            printf("  Author: %s\n", db->books[i].author);
            printf("  Year: %d\n", db->books[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void showMenu() {
    printf("Book Database Management:\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search for a Book\n");
    printf("4. Exit\n");
}

int main() {
    BookDatabase db;
    initializeDatabase(&db);

    int choice;
    do {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(&db);
                break;
            case 2:
                displayBooks(&db);
                break;
            case 3:
                searchBook(&db);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}