//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DATABASE "library.db"

void create_table(sqlite3 *db);
void add_book(sqlite3 *db, const char *title, const char *author);
void display_books(sqlite3 *db);
void update_book(sqlite3 *db, int id, const char *new_title);
void delete_book(sqlite3 *db, int id);
int callback(void *data, int argc, char **argv, char **azColName);

int main() {
    sqlite3 *db;
    char *messageError;

    if (sqlite3_open(DATABASE, &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    create_table(db);
    int choice;
    char title[100], author[100];
    int id;
    
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Update Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf(" %[^\n]", title);
                printf("Enter book author: ");
                scanf(" %[^\n]", author);
                add_book(db, title, author);
                break;
            case 2:
                display_books(db);
                break;
            case 3:
                printf("Enter book ID to update: ");
                scanf("%d", &id);
                printf("Enter new title: ");
                scanf(" %[^\n]", title);
                update_book(db, id, title);
                break;
            case 4:
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                delete_book(db, id);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    sqlite3_close(db);
    return 0;
}

void create_table(sqlite3 *db) {
    char *sql = "CREATE TABLE IF NOT EXISTS Books("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                "Title TEXT NOT NULL, "
                "Author TEXT NOT NULL);";
    char *messageError;

    if (sqlite3_exec(db, sql, 0, 0, &messageError) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", messageError);
        sqlite3_free(messageError);
    }
}

void add_book(sqlite3 *db, const char *title, const char *author) {
    char sql[256];
    sprintf(sql, "INSERT INTO Books (Title, Author) VALUES ('%s', '%s');", title, author);
    char *messageError;

    if (sqlite3_exec(db, sql, 0, 0, &messageError) != SQLITE_OK) {
        fprintf(stderr, "Error adding book: %s\n", messageError);
        sqlite3_free(messageError);
    } else {
        printf("Book added successfully!\n");
    }
}

void display_books(sqlite3 *db) {
    const char *sql = "SELECT * FROM Books;";
    char *messageError;
    
    printf("\nBooks:\n");
    if (sqlite3_exec(db, sql, callback, 0, &messageError) != SQLITE_OK) {
        fprintf(stderr, "Error retrieving books: %s\n", messageError);
        sqlite3_free(messageError);
    }
}

int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s: %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void update_book(sqlite3 *db, int id, const char *new_title) {
    char sql[256];
    sprintf(sql, "UPDATE Books SET Title = '%s' WHERE ID = %d;", new_title, id);
    char *messageError;

    if (sqlite3_exec(db, sql, 0, 0, &messageError) != SQLITE_OK) {
        fprintf(stderr, "Error updating book: %s\n", messageError);
        sqlite3_free(messageError);
    } else {
        printf("Book updated successfully!\n");
    }
}

void delete_book(sqlite3 *db, int id) {
    char sql[256];
    sprintf(sql, "DELETE FROM Books WHERE ID = %d;", id);
    char *messageError;

    if (sqlite3_exec(db, sql, 0, 0, &messageError) != SQLITE_OK) {
        fprintf(stderr, "Error deleting book: %s\n", messageError);
        sqlite3_free(messageError);
    } else {
        printf("Book deleted successfully!\n");
    }
}