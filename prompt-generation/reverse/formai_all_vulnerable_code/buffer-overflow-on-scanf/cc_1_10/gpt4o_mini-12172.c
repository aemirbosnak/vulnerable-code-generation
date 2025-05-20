//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define DATABASE_NAME "user_db.sqlite"

void check_sqlite_error(int rc, sqlite3 *db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_free(db);
        exit(EXIT_FAILURE);
    }
}

void create_table(sqlite3 *db) {
    const char *create_table_sql = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "email TEXT NOT NULL UNIQUE);";
    
    char *error_message = 0;
    int rc = sqlite3_exec(db, create_table_sql, 0, 0, &error_message);
    check_sqlite_error(rc, db);
}

void add_user(sqlite3 *db, const char *name, const char *email) {
    const char *insert_sql = "INSERT INTO users (name, email) VALUES (?, ?);";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, 0);
    check_sqlite_error(rc, db);

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    check_sqlite_error(rc, db);

    sqlite3_finalize(stmt);
    printf("User %s added successfully.\n", name);
}

void fetch_users(sqlite3 *db) {
    const char *select_sql = "SELECT id, name, email FROM users;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, 0);
    check_sqlite_error(rc, db);

    printf("ID\tName\t\tEmail\n");
    printf("---------------------------------------\n");

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *email = (const char *)sqlite3_column_text(stmt, 2);

        printf("%d\t%s\t%s\n", id, name, email);
    }
    
    if (rc != SQLITE_DONE) {
        check_sqlite_error(rc, db);
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open(DATABASE_NAME, &db);
    check_sqlite_error(rc, db);
    
    create_table(db);

    int choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Fetch Users\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                
                add_user(db, name, email);
                break;

            case 2:
                fetch_users(db);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    sqlite3_close(db);
    return 0;
}