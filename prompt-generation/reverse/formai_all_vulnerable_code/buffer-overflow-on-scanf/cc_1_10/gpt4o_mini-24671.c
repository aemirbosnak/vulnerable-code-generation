//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DB_NAME "library.db"

void create_table(sqlite3 *db) {
    char *err_msg = 0;
    
    const char *sql = "CREATE TABLE IF NOT EXISTS Books("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Title TEXT NOT NULL,"
                      "Author TEXT NOT NULL,"
                      "Year INTEGER NOT NULL);";

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void add_book(sqlite3 *db, const char *title, const char *author, int year) {
    char *err_msg = 0;
    char sql[256];

    snprintf(sql, sizeof(sql), "INSERT INTO Books (Title, Author, Year) VALUES ('%s', '%s', %d);", title, author, year);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Book added successfully!\n");
    }
}

void view_books(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM Books;";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    printf("\nBooks in the Library:\n");
    printf("ID | Title                       | Author               | Year\n");
    printf("---|-----------------------------|---------------------|------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        const char *author = (const char *)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        printf("%-3d | %-27s | %-19s | %d\n", id, title, author, year);
    }

    sqlite3_finalize(stmt);
}

void search_book(sqlite3 *db, const char *search_term) {
    sqlite3_stmt *stmt;
    char sql[256];

    snprintf(sql, sizeof(sql), "SELECT * FROM Books WHERE Title LIKE '%%%s%%' OR Author LIKE '%%%s%%';", search_term, search_term);
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    printf("\nSearch Results for '%s':\n", search_term);
    printf("ID | Title                       | Author               | Year\n");
    printf("---|-----------------------------|---------------------|------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        const char *author = (const char *)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        printf("%-3d | %-27s | %-19s | %d\n", id, title, author, year);
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int exit = sqlite3_open(DB_NAME, &db);

    if (exit) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    create_table(db);

    int choice;
    char title[100], author[100];
    int year;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                printf("Enter Book Title: ");
                scanf(" %[^\n]s", title);
                printf("Enter Book Author: ");
                scanf(" %[^\n]s", author);
                printf("Enter Publication Year: ");
                scanf("%d", &year);
                add_book(db, title, author, year);
                break;
            case 2:
                view_books(db);
                break;
            case 3:
                printf("Enter search term (title or author): ");
                char search_term[100];
                scanf(" %[^\n]s", search_term);
                search_book(db, search_term);
                break;
            case 4:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    sqlite3_close(db);
    return 0;
}