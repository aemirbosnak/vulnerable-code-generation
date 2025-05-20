//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DATABASE_NAME "library.db"

void create_database() {
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open(DATABASE_NAME, &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Books("  \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "Title TEXT NOT NULL," \
                      "Author TEXT NOT NULL," \
                      "Year INT NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    
    sqlite3_close(db);
}

void add_book(const char *title, const char *author, int year) {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DATABASE_NAME, &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Books(Title, Author, Year) VALUES('%s', '%s', %d);", title, author, year);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Book added successfully.\n");
    }
    
    sqlite3_close(db);
}

void list_books() {
    sqlite3 *db;
    sqlite3_stmt *res;
    
    int rc = sqlite3_open(DATABASE_NAME, &db);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    const char *sql = "SELECT * FROM Books;";
    
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Books in the library:\n");
        while (sqlite3_step(res) == SQLITE_ROW) {
            int id = sqlite3_column_int(res, 0);
            const unsigned char *title = sqlite3_column_text(res, 1);
            const unsigned char *author = sqlite3_column_text(res, 2);
            int year = sqlite3_column_int(res, 3);
            printf("ID: %d, Title: %s, Author: %s, Year: %d\n", id, title, author, year);
        }
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
}

int main() {
    int choice;
    create_database();

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1: {
            char title[256], author[256];
            int year;
            printf("Enter book title: ");
            scanf(" %255[^\n]", title);
            printf("Enter author name: ");
            scanf(" %255[^\n]", author);
            printf("Enter publication year: ");
            scanf("%d", &year);
            add_book(title, author, year);
            break;
        }
        case 2:
            list_books();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}