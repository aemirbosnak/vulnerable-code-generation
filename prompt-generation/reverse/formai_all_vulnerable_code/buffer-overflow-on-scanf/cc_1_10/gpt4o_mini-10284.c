//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DATABASE "contacts.db"

void create_table(sqlite3 *db);
void insert_contact(sqlite3 *db, const char *name, const char *phone);
void display_contacts(sqlite3 *db);
void update_contact(sqlite3 *db, const char *old_name, const char *new_name, const char *new_phone);
void delete_contact(sqlite3 *db, const char *name);
void input_contact_info(char *name, char *phone);

int main() {
    sqlite3 *db;

    // Open database
    if (sqlite3_open(DATABASE, &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    // Create table
    create_table(db);

    int choice;
    char name[50], phone[15];

    do {
        printf("\nMind-Bending Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                input_contact_info(name, phone);
                insert_contact(db, name, phone);
                break;
            case 2:
                display_contacts(db);
                break;
            case 3:
                printf("Enter the name of the contact to update: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline
                printf("Enter the new name: ");
                fgets(phone, sizeof(phone), stdin); // Reusing phone variable for new name
                strtok(phone, "\n"); // Remove newline
                printf("Enter the new phone: ");
                fgets(phone, sizeof(phone), stdin); 
                strtok(phone, "\n"); // Remove newline
                update_contact(db, name, phone, phone);
                break;
            case 4:
                printf("Enter the name of the contact to delete: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n"); // Remove newline
                delete_contact(db, name);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    sqlite3_close(db);
    return 0;
}

void create_table(sqlite3 *db) {
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Contacts(Id INTEGER PRIMARY KEY, Name TEXT, Phone TEXT);";

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to create table: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void insert_contact(sqlite3 *db, const char *name, const char *phone) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Contacts (Name, Phone) VALUES ('%s', '%s');", name, phone);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to insert contact: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        printf("Contact '%s' added successfully!\n", name);
    }
}

void display_contacts(sqlite3 *db) {
    const char *sql = "SELECT * FROM Contacts;";
    sqlite3_stmt *stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch contacts: %s\n", sqlite3_errmsg(db));
    } else {
        printf("\nContacts List:\n");
        printf("ID\tName\tPhone\n");
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            printf("%d\t%s\t%s\n", sqlite3_column_int(stmt, 0),
                                    sqlite3_column_text(stmt, 1),
                                    sqlite3_column_text(stmt, 2));
        }
        sqlite3_finalize(stmt);
    }
}

void update_contact(sqlite3 *db, const char *old_name, const char *new_name, const char *new_phone) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "UPDATE Contacts SET Name = '%s', Phone = '%s' WHERE Name = '%s';", new_name, new_phone, old_name);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to update contact: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        printf("Contact updated successfully!\n");
    }
}

void delete_contact(sqlite3 *db, const char *name) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM Contacts WHERE Name = '%s';", name);

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Failed to delete contact: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        printf("Contact '%s' deleted successfully!\n", name);
    }
}

void input_contact_info(char *name, char *phone) {
    printf("Enter contact name: ");
    fgets(name, 50, stdin);
    strtok(name, "\n"); // Remove newline
    printf("Enter contact phone: ");
    fgets(phone, 15, stdin);
    strtok(phone, "\n"); // Remove newline
}