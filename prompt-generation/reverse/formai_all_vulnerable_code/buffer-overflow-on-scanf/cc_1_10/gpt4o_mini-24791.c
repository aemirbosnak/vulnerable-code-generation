//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_NAME_LENGTH 100
#define DATABASE_NAME "contacts.db"

// Function to execute a SQL statement
void execute_sql(sqlite3 *db, const char *sql) {
    char *errMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

// Function to display contacts
int display_contacts(void *data, int argc, char **argv, char **azColName) {
    printf("ID: %s, Name: %s, Phone: %s\n", argv[0], argv[1], argv[2]);
    return 0;
}

// Function to add a new contact
void add_contact(sqlite3 *db) {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char sql[256];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter phone: ");
    fgets(phone, MAX_NAME_LENGTH, stdin);
    phone[strcspn(phone, "\n")] = 0;

    snprintf(sql, sizeof(sql), "INSERT INTO Contacts (Name, Phone) VALUES ('%s', '%s');", name, phone);
    execute_sql(db, sql);
}

// Function to search for a contact by name
void search_contact(sqlite3 *db) {
    char name[MAX_NAME_LENGTH];
    char sql[256];

    printf("Enter name to search: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    snprintf(sql, sizeof(sql), "SELECT * FROM Contacts WHERE Name LIKE '%%%s%%';", name);
    execute_sql(db, sql);
}

// Function to display all contacts
void list_contacts(sqlite3 *db) {
    char *sql = "SELECT * FROM Contacts;";
    sqlite3_exec(db, sql, display_contacts, 0, 0);
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    // Open or create the database
    rc = sqlite3_open(DATABASE_NAME, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    // Create the Contacts table
    const char *sql_create = "CREATE TABLE IF NOT EXISTS Contacts (ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT NOT NULL, Phone TEXT NOT NULL);";
    execute_sql(db, sql_create);

    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                add_contact(db);
                break;
            case 2:
                search_contact(db);
                break;
            case 3:
                list_contacts(db);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Close the database
    sqlite3_close(db);
    return 0;
}