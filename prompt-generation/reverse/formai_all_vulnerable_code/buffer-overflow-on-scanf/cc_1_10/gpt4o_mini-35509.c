//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

typedef struct {
    Book *books;
    int size;
    int capacity;
} BookDatabase;

// Function to initialize the database
void initDatabase(BookDatabase *db, int capacity) {
    db->size = 0;
    db->capacity = capacity;
    db->books = malloc(sizeof(Book) * capacity);
    if (!db->books) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to resize the database when full
void resizeDatabase(BookDatabase *db) {
    db->capacity *= 2;
    db->books = realloc(db->books, sizeof(Book) * db->capacity);
    if (!db->books) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to add a book to the database
void addBook(BookDatabase *db, const char *title, const char *author, int year) {
    if (db->size == db->capacity) {
        resizeDatabase(db);
    }
    strcpy(db->books[db->size].title, title);
    strcpy(db->books[db->size].author, author);
    db->books[db->size].year = year;
    db->size++;
    printf("Book added: %s by %s (%d)\n", title, author, year);
}

// Function to remove a book from the database
void removeBook(BookDatabase *db, const char *title) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->books[i].title, title) == 0) {
            for (int j = i; j < db->size - 1; j++) {
                db->books[j] = db->books[j + 1];
            }
            db->size--;
            printf("Book removed: %s\n", title);
            return;
        }
    }
    printf("Book not found: %s\n", title);
}

// Function to list all books in the database
void listBooks(const BookDatabase *db) {
    if (db->size == 0) {
        printf("No books in the database.\n");
        return;
    }
    printf("Books in the Database:\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, db->books[i].title, db->books[i].author, db->books[i].year);
    }
}

// Function to free the allocated memory
void freeDatabase(BookDatabase *db) {
    free(db->books);
}

int main() {
    BookDatabase db;
    initDatabase(&db, 2);
    
    int choice;
    char title[100], author[100];
    int year;

    do {
        printf("\n--- Book Database Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. List Books\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline character

                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0;  // Remove newline character

                printf("Enter publication year: ");
                scanf("%d", &year);
                addBook(&db, title, author, year);
                break;
            case 2:
                printf("Enter book title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline character
                removeBook(&db, title);
                break;
            case 3:
                listBooks(&db);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeDatabase(&db);
    return 0;
}