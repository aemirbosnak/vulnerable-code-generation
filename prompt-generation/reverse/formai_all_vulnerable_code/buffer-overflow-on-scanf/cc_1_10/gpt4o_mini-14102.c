//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define MAX_QUERY_LENGTH 256
#define MAX_NAME_LENGTH 50

// Function to print SQLite error
void print_sqlite_error(int rc, sqlite3 *db) {
    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
}

// Callback function for SQLite
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Function to execute a SQL query
void execute_query(sqlite3 *db, const char *query) {
    char *errMsg = 0;
    int rc = sqlite3_exec(db, query, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        print_sqlite_error(rc, db);
        sqlite3_free(errMsg);
    }
}

// Function to create a table
void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Users("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Name TEXT NOT NULL,"
                      "Age INTEGER NOT NULL);";
    execute_query(db, sql);
}

// Function to insert user data
void insert_user(sqlite3 *db, const char *name, int age) {
    char sql[MAX_QUERY_LENGTH];
    snprintf(sql, sizeof(sql), "INSERT INTO Users (Name, Age) VALUES ('%s', %d);", name, age);
    execute_query(db, sql);
}

// Function to fetch and display users
void list_users(sqlite3 *db) {
    const char *sql = "SELECT * FROM Users;";
    execute_query(db, sql);
}

// Function to update user age
void update_user_age(sqlite3 *db, int id, int new_age) {
    char sql[MAX_QUERY_LENGTH];
    snprintf(sql, sizeof(sql), "UPDATE Users SET Age = %d WHERE ID = %d;", new_age, id);
    execute_query(db, sql);
}

// Function to delete a user
void delete_user(sqlite3 *db, int id) {
    char sql[MAX_QUERY_LENGTH];
    snprintf(sql, sizeof(sql), "DELETE FROM Users WHERE ID = %d;", id);
    execute_query(db, sql);
}

// Function to display menu
void display_menu() {
    printf("1. Add User\n");
    printf("2. List Users\n");
    printf("3. Update User Age\n");
    printf("4. Delete User\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    sqlite3 *db;
    int exit;

    // Open SQLite database
    exit = sqlite3_open("users.db", &db);
    if (exit) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    create_table(db);

    int choice;
    char name[MAX_NAME_LENGTH];
    int age, id;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add User
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insert_user(db, name, age);
                break;

            case 2:
                // List Users
                printf("Current Users:\n");
                list_users(db);
                break;

            case 3:
                // Update User Age
                printf("Enter user ID to update: ");
                scanf("%d", &id);
                printf("Enter new age: ");
                scanf("%d", &age);
                update_user_age(db, id, age);
                break;

            case 4:
                // Delete User
                printf("Enter user ID to delete: ");
                scanf("%d", &id);
                delete_user(db, id);
                break;

            case 5:
                // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    // Close the SQLite database
    sqlite3_close(db);
    return 0;
}