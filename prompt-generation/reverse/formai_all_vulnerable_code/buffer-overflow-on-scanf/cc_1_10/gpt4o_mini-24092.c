//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} DatabaseEntry;

typedef struct {
    DatabaseEntry entries[MAX_ENTRIES];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

int addEntry(Database *db, const char *key, const char *value) {
    if (db->count >= MAX_ENTRIES) {
        printf("Database is full!\n");
        return -1;
    }
    snprintf(db->entries[db->count].key, MAX_KEY_LENGTH, "%s", key);
    snprintf(db->entries[db->count].value, MAX_VALUE_LENGTH, "%s", value);
    db->count++;
    return 0;
}

DatabaseEntry* searchEntry(Database *db, const char *key) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return &db->entries[i];
        }
    }
    return NULL;
}

void displayEntries(Database *db) {
    if (db->count == 0) {
        printf("No entries in the database.\n");
        return;
    }
    printf("Database Entries:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Key: %s, Value: %s\n", db->entries[i].key, db->entries[i].value);
    }
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("Database cleared!\n");
}

int main() {
    Database db;
    initDatabase(&db);
    
    int choice;
    char key[MAX_KEY_LENGTH], value[MAX_VALUE_LENGTH];

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display Entries\n");
        printf("4. Clear Database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter key: ");
                fgets(key, MAX_KEY_LENGTH, stdin);
                key[strcspn(key, "\n")] = '\0'; // Remove newline

                printf("Enter value: ");
                fgets(value, MAX_VALUE_LENGTH, stdin);
                value[strcspn(value, "\n")] = '\0'; // Remove newline

                if (addEntry(&db, key, value) == 0) {
                    printf("Entry added successfully!\n");
                }
                break;

            case 2:
                printf("Enter key to search: ");
                fgets(key, MAX_KEY_LENGTH, stdin);
                key[strcspn(key, "\n")] = '\0'; // Remove newline

                DatabaseEntry *entry = searchEntry(&db, key);
                if (entry) {
                    printf("Found Entry - Key: %s, Value: %s\n", entry->key, entry->value);
                } else {
                    printf("Entry not found!\n");
                }
                break;

            case 3:
                displayEntries(&db);
                break;

            case 4:
                clearDatabase(&db);
                break;

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}