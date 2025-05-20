//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 512
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} User;

void execute_query(sqlite3 *db, const char *query) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, query, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

int callback(void *data, int argc, char **argv, char **azColName) {
    User *user = (User *)data;
    user->id = atoi(argv[0]);
    strncpy(user->name, argv[1], MAX_NAME_LENGTH);
    strncpy(user->email, argv[2], MAX_EMAIL_LENGTH);
    
    printf("User ID: %d\nName: %s\nEmail: %s\n", user->id, user->name, user->email);
    return 0;
}

void query_users(sqlite3 *db) {
    const char *sql = "SELECT * FROM Users;";
    User user;
    char *err_msg = 0;

    int rc = sqlite3_exec(db, sql, callback, &user, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Query error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Users("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Name TEXT NOT NULL,"
                      "Email TEXT NOT NULL UNIQUE);";
    execute_query(db, sql);
}

void insert_user(sqlite3 *db, const char *name, const char *email) {
    char sql[MAX_QUERY_LENGTH];
    snprintf(sql, MAX_QUERY_LENGTH, "INSERT INTO Users (Name, Email) VALUES ('%s', '%s');", name, email);
    execute_query(db, sql);
}

void delete_user(sqlite3 *db, int userId) {
    char sql[MAX_QUERY_LENGTH];
    snprintf(sql, MAX_QUERY_LENGTH, "DELETE FROM Users WHERE ID = %d;", userId);
    execute_query(db, sql);
}

void print_menu() {
    printf("\n=== User Database Menu ===\n");
    printf("1. Add User\n");
    printf("2. List Users\n");
    printf("3. Delete User\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("user_database.db", &db);
    
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    create_table(db);
    
    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    int userId;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                insert_user(db, name, email);
                break;
            case 2:
                printf("\n--- User List ---\n");
                query_users(db);
                break;
            case 3:
                printf("Enter User ID to delete: ");
                scanf("%d", &userId);
                delete_user(db, userId);
                break;
            case 4:
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}