//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void create_table(sqlite3* db) {
    const char* sql = "CREATE TABLE IF NOT EXISTS books ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "title TEXT NOT NULL,"
                      "author TEXT NOT NULL,"
                      "year INTEGER NOT NULL);";
    char* err_msg = 0;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to create table: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Table created successfully.\n");
    }
}

void insert_book(sqlite3* db, const char* title, const char* author, int year) {
    char sql[256];
    sprintf(sql, "INSERT INTO books (title, author, year) VALUES ('%s', '%s', %d);", title, author, year);
    char* err_msg = 0;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to insert book: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Book '%s' added successfully.\n", title);
    }
}

void list_books(sqlite3* db) {
    const char* sql = "SELECT * FROM books;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\nList of Books:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* title = (const char*)sqlite3_column_text(stmt, 1);
        const char* author = (const char*)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n", id, title, author, year);
    }
    
    sqlite3_finalize(stmt);
}

void search_book(sqlite3* db, const char* title) {
    char sql[256];
    sprintf(sql, "SELECT * FROM books WHERE title='%s';", title);
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\nSearch Results:\n");
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* book_title = (const char*)sqlite3_column_text(stmt, 1);
        const char* author = (const char*)sqlite3_column_text(stmt, 2);
        int year = sqlite3_column_int(stmt, 3);
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n", id, book_title, author, year);
    } else {
        printf("No book found with the title '%s'.\n", title);
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;

    if (sqlite3_open("bookstore.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    create_table(db);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        if (choice == 1) {
            char title[100];
            char author[100];
            int year;
            printf("Enter book title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline
            
            printf("Enter author name: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0; // Remove newline

            printf("Enter publication year: ");
            scanf("%d", &year);
            insert_book(db, title, author, year);
        } else if (choice == 2) {
            list_books(db);
        } else if (choice == 3) {
            char title[100];
            printf("Enter book title to search: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove newline
            search_book(db, title);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}