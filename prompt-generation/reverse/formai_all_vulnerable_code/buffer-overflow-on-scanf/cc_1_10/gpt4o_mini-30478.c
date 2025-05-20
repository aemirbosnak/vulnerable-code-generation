//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 15

// Function to open a database connection
int open_database(sqlite3 **db) {
    int rc = sqlite3_open("phonebook.db", db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    }
    return 0;
}

// Function to create a table if it doesn't exist
void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Contacts ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Name TEXT NOT NULL, "
                      "Phone TEXT NOT NULL);";
    char *err_msg = 0;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// Callback function for displaying query results
int callback(void *unused, int count, char **data, char **columns) {
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", columns[i], data[i] ? data[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Function to insert a new contact
void insert_contact(sqlite3 *db, const char *name, const char *phone) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Contacts (Name, Phone) VALUES ('%s', '%s');", name, phone);
    
    char *err_msg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Insert error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("New contact added: %s, %s\n", name, phone);
    }
}

// Function to display all contacts
void display_contacts(sqlite3 *db) {
    const char *sql = "SELECT * FROM Contacts;";
    char *err_msg = 0;

    if (sqlite3_exec(db, sql, callback, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Display error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// Function to search for a contact by name
void search_contact(sqlite3 *db, const char *name) {
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM Contacts WHERE Name LIKE '%%%s%%';", name);
    
    char *err_msg = 0;
    if (sqlite3_exec(db, sql, callback, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Search error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// Main interface
void interface(sqlite3 *db) {
    while (1) {
        printf("\n=== Simple Phone Book ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        int option;
        scanf("%d", &option);
        getchar(); // Consume newline

        char name[MAX_NAME_LEN];
        char phone[MAX_PHONE_LEN];

        switch (option) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter Phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline

                insert_contact(db, name, phone);
                break;

            case 2:
                display_contacts(db);
                break;

            case 3:
                printf("Enter Name to Search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                search_contact(db, name);
                break;

            case 4:
                printf("Exiting Phone Book...\n");
                sqlite3_close(db);
                return;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

int main() {
    sqlite3 *db;

    if (open_database(&db) == 0) {
        create_table(db);
        interface(db);
    }

    return 0;
}