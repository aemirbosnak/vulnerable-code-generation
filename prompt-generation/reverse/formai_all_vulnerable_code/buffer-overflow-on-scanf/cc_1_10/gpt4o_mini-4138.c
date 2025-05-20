//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: relaxed
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
    Book *books[MAX_BOOKS];
    int count;
} BookDatabase;

void initializeDatabase(BookDatabase *db) {
    db->count = 0;
}

Book* createBook(const char *title, const char *author, int year) {
    Book *newBook = malloc(sizeof(Book));
    if (newBook == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newBook->title, title, TITLE_LENGTH);
    strncpy(newBook->author, author, AUTHOR_LENGTH);
    newBook->year = year;
    return newBook;
}

void addBook(BookDatabase *db) {
    if (db->count >= MAX_BOOKS) {
        printf("Database is full! Cannot add more books.\n");
        return;
    }
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int year;

    printf("Enter book title: ");
    fgets(title, TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    printf("Enter author name: ");
    fgets(author, AUTHOR_LENGTH, stdin);
    author[strcspn(author, "\n")] = 0;

    printf("Enter publication year: ");
    scanf("%d", &year);
    getchar(); // To consume the newline left by scanf

    db->books[db->count++] = createBook(title, author, year);
    printf("Book added successfully!\n");
}

void viewBooks(const BookDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        Book *book = db->books[i];
        printf("Book %d: Title: %s, Author: %s, Year: %d\n", 
            i + 1, book->title, book->author, book->year);
    }
}

void searchBook(const BookDatabase *db) {
    char searchTitle[TITLE_LENGTH];
    printf("Enter title of the book to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < db->count; i++) {
        Book *book = db->books[i];
        if (strcmp(book->title, searchTitle) == 0) {
            printf("Found Book: Title: %s, Author: %s, Year: %d\n", 
                book->title, book->author, book->year);
            return;
        }
    }
    printf("Book not found!\n");
}

void deleteBook(BookDatabase *db) {
    char deleteTitle[TITLE_LENGTH];
    printf("Enter title of the book to delete: ");
    fgets(deleteTitle, TITLE_LENGTH, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0;

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->books[i]->title, deleteTitle) == 0) {
            free(db->books[i]);
            for (int j = i; j < db->count - 1; j++) {
                db->books[j] = db->books[j + 1];
            }
            db->count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

int main() {
    BookDatabase db;
    initializeDatabase(&db);
    int choice;

    while (1) {
        printf("\nSimple Book Database\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline left by scanf

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
                deleteBook(&db);
                break;
            case 5:
                printf("Exiting database. Goodbye!\n");
                for (int i = 0; i < db.count; i++) {
                    free(db.books[i]);
                }
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}