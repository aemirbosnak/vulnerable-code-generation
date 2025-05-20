//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 30
#define MAX_ENTRIES 100

/* Password entry structure */
typedef struct {
    char service_name[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

/* Password database structure */
typedef struct {
    PasswordEntry entries[MAX_ENTRIES];
    int num_entries;
} PasswordDatabase;

/* Function prototypes */
void add_entry(PasswordDatabase *db);
void remove_entry(PasswordDatabase *db);
void list_entries(PasswordDatabase *db);

int main() {
    PasswordDatabase db;
    db.num_entries = 0;
    int choice;

    /* Main menu loop */
    while (1) {
        printf("\nPassword Manager\n");
        printf("-----------------\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. List Entries\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&db);
                break;
            case 2:
                remove_entry(&db);
                break;
            case 3:
                list_entries(&db);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

/* Adds a password entry to the database */
void add_entry(PasswordDatabase *db) {
    if (db->num_entries == MAX_ENTRIES) {
        printf("Database is full.\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter service name: ");
    scanf("%s", entry.service_name);
    printf("Enter username: ");
    scanf("%s", entry.username);
    printf("Enter password: ");
    scanf("%s", entry.password);

    db->entries[db->num_entries++] = entry;
    printf("Entry added successfully.\n");
}

/* Removes a password entry from the database */
void remove_entry(PasswordDatabase *db) {
    if (db->num_entries == 0) {
        printf("Database is empty.\n");
        return;
    }

    char service_name[MAX_PASSWORD_LENGTH];
    printf("Enter service name of entry to remove: ");
    scanf("%s", service_name);

    /* Find the entry to remove */
    int found = 0, i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].service_name, service_name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
        return;
    }

    /* Shift the entries down to remove the entry */
    for (; i < db->num_entries - 1; i++) {
        db->entries[i] = db->entries[i+1];
    }

    db->num_entries--;
    printf("Entry removed successfully.\n");
}

/* Lists all password entries in the database */
void list_entries(PasswordDatabase *db) {
    if (db->num_entries == 0) {
        printf("Database is empty.\n");
        return;
    }

    int i;
    printf("%-20s %-20s %-20s\n", "Service", "Username", "Password");
    printf("-------------------------------------------------------\n");
    for (i = 0; i < db->num_entries; i++) {
        printf("%-20s %-20s %-20s\n", db->entries[i].service_name, db->entries[i].username, db->entries[i].password);
    }
}