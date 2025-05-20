//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void create_database(const char *db_name);
void add_contact(sqlite3 *db);
void view_contacts(sqlite3 *db);
void execute_query(sqlite3 *db, const char *sql);
static int contact_callback(void *data, int argc, char **argv, char **azColName);

int main() {
    const char *db_name = "contacts.db";
    create_database(db_name);

    sqlite3 *db;
    if (sqlite3_open(db_name, &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    int choice;
    do {
        printf("\n1. Add Contact\n2. View Contacts\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(db);
                break;
            case 2:
                view_contacts(db);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 3);

    sqlite3_close(db);
    return 0;
}

void create_database(const char *db_name) {
    sqlite3 *db;
    char *err_msg = 0;

    if (sqlite3_open(db_name, &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Contacts(Id INTEGER PRIMARY KEY, Name TEXT, Phone TEXT);";
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

void add_contact(sqlite3 *db) {
    char name[100];
    char phone[15];

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Phone: ");
    scanf("%s", phone);

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Contacts (Name, Phone) VALUES ('%s', '%s');", name, phone);
    execute_query(db, sql);
}

void view_contacts(sqlite3 *db) {
    const char *sql = "SELECT * FROM Contacts;";
    char *err_msg = 0;

    printf("\nContacts:\n");
    if (sqlite3_exec(db, sql, contact_callback, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void execute_query(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Operation completed successfully.\n");
    }
}

static int contact_callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}