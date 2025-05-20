//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_KEY_LENGTH 50
#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char key[MAX_KEY_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int num_entries;
} Database;

void init_database(Database* db) {
    db->num_entries = 0;
}

bool add_entry(Database* db, char* key, char* entry) {
    if (db->num_entries >= MAX_ENTRIES) {
        printf("Database is full!\n");
        return false;
    }
    strncpy(db->entries[db->num_entries].key, key, MAX_KEY_LENGTH);
    strncpy(db->entries[db->num_entries].entry, entry, MAX_ENTRY_LENGTH);
    db->num_entries++;
    return true;
}

bool search_entry(Database* db, char* key, char* entry) {
    int i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            strcpy(entry, db->entries[i].entry);
            return true;
        }
    }
    return false;
}

void print_database(Database* db) {
    int i;
    printf("Database:\n");
    for (i = 0; i < db->num_entries; i++) {
        printf("%s -> %s\n", db->entries[i].key, db->entries[i].entry);
    }
}

int main() {
    Database db;
    init_database(&db);
    char key[MAX_KEY_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
    int choice;
    while (true) {
        printf("\n1. Add entry\n2. Search entry\n3. Print database\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter entry: ");
                scanf("%s", entry);
                add_entry(&db, key, entry);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                char result[MAX_ENTRY_LENGTH];
                if (search_entry(&db, key, result)) {
                    printf("Entry: %s\n", result);
                } else {
                    printf("No entry found!\n");
                }
                break;
            case 3:
                print_database(&db);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}