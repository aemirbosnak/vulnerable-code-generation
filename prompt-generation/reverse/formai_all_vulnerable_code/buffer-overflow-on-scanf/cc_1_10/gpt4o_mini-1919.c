//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_ISBN_LENGTH 20

void check_sql_error(int rc, sqlite3 *db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
}

static int callback(void *data, int argc, char **argv, char **azColName) {
    printf("%s: ", (const char *)data);
    for (int i = 0; i < argc; i++) {
        printf("%s = %s ", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void create_table(sqlite3 *db) {
    char *sql = "CREATE TABLE IF NOT EXISTS BOOKS("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                "TITLE TEXT NOT NULL,"
                "AUTHOR TEXT NOT NULL,"
                "ISBN TEXT NOT NULL UNIQUE);";
    char *err_msg = 0;

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    check_sql_error(rc, db);
}

void add_book(sqlite3 *db, const char *title, const char *author, const char *isbn) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO BOOKS (TITLE, AUTHOR, ISBN) VALUES ('%s', '%s', '%s');",
             title, author, isbn);
    char *err_msg = 0;

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    check_sql_error(rc, db);
}

void display_books(sqlite3 *db) {
    const char *data = "Callback function called";
    char *sql = "SELECT * FROM BOOKS;";
    char *err_msg = 0;

    int rc = sqlite3_exec(db, sql, callback, (void *)data, &err_msg);
    check_sql_error(rc, db);
}

void delete_book(sqlite3 *db, const char *isbn) {
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM BOOKS WHERE ISBN='%s';", isbn);
    char *err_msg = 0;

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    check_sql_error(rc, db);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("library.db", &db);
    check_sql_error(rc, db);

    create_table(db);
    
    int choice;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH], isbn[MAX_ISBN_LENGTH];

    while (1) {
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Delete Book by ISBN\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clean the newline from the input buffer

        switch (choice) {
            case 1:
                printf("Enter Book Title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;  // removing newline character

                printf("Enter Book Author: ");
                fgets(author, MAX_AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = 0;

                printf("Enter Book ISBN: ");
                fgets(isbn, MAX_ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                add_book(db, title, author, isbn);
                break;

            case 2:
                display_books(db);
                break;

            case 3:
                printf("Enter ISBN of Book to Delete: ");
                fgets(isbn, MAX_ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                delete_book(db, isbn);
                break;

            case 4:
                sqlite3_close(db);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    sqlite3_close(db);
    return 0;
}