//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 100
#define AUTHOR_SIZE 100

typedef struct {
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int year;
} Book;

typedef struct {
    Book *books[MAX_BOOKS];
    int count;
} BookDatabase;

// Function prototypes
void addBook(BookDatabase *db);
void viewBooks(BookDatabase *db);
void deleteBook(BookDatabase *db);
void freeBooks(BookDatabase *db);

int main() {
    BookDatabase db;
    db.count = 0;
    int choice;

    while (1) {
        printf("\n--- Book Database Menu ---\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear the buffer
            continue;
        }

        switch (choice) {
            case 1: 
                if (db.count < MAX_BOOKS) {
                    addBook(&db);
                } else {
                    printf("Database is full! Cannot add more books.\n");
                }
                break;
            case 2:
                viewBooks(&db);
                break;
            case 3:
                deleteBook(&db);
                break;
            case 4:
                freeBooks(&db);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addBook(BookDatabase *db) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    printf("Enter book title: ");
    getchar(); // consume newline character
    fgets(newBook->title, TITLE_SIZE, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = '\0'; // remove newline

    printf("Enter author name: ");
    fgets(newBook->author, AUTHOR_SIZE, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = '\0'; // remove newline

    printf("Enter publication year: ");
    scanf("%d", &newBook->year);

    db->books[db->count] = newBook;
    db->count++;
    printf("Book '%s' added successfully!\n", newBook->title);
}

void viewBooks(BookDatabase *db) {
    if (db->count == 0) {
        printf("No books available in the database.\n");
        return;
    }

    printf("\n--- List of Books ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", db->books[i]->title);
        printf("Author: %s\n", db->books[i]->author);
        printf("Year: %d\n", db->books[i]->year);
        printf("-----------------------\n");
    }
}

void deleteBook(BookDatabase *db) {
    if (db->count == 0) {
        printf("No books to delete.\n");
        return;
    }

    int index;
    viewBooks(db);
    printf("Enter the book number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > db->count) {
        printf("Invalid book number!\n");
        return;
    }

    free(db->books[index - 1]); // free memory for the book
    for (int i = index - 1; i < db->count - 1; i++) {
        db->books[i] = db->books[i + 1]; // shift books left
    }
    db->count--; // decrease the count
    printf("Book deleted successfully!\n");
}

void freeBooks(BookDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        free(db->books[i]); // free each book
    }
}