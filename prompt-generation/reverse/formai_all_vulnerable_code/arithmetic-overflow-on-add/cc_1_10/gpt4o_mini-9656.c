//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define INDEX_LENGTH 150

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} Database;

void init_database(Database *db) {
    db->count = 0;
}

void add_entry(Database *db, int id, const char *name) {
    if (db->count >= MAX_ENTRIES) {
        printf("Database is full. Unable to add new entry.\n");
        return;
    }
    db->entries[db->count].id = id;
    strncpy(db->entries[db->count].name, name, NAME_LENGTH - 1);
    db->entries[db->count].name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    db->count++;
    printf("Entry added: [%d] %s\n", id, name);
}

void search_entry(Database *db, const char *query) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->entries[i].name, query) != NULL) {
            printf("Found Entry: [%d] %s\n", db->entries[i].id, db->entries[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found matching '%s'.\n", query);
    }
}

void list_entries(Database *db) {
    printf("Listing all entries in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("[%d] %s\n", db->entries[i].id, db->entries[i].name);
    }
}

void save_to_file(Database *db) {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        fprintf(file, "%d,%s\n", db->entries[i].id, db->entries[i].name);
    }
    fclose(file);
    printf("Database saved to 'database.txt'.\n");
}

void load_from_file(Database *db) {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("No database file found, starting with an empty database.\n");
        return;
    }
    
    db->count = 0;
    while (fscanf(file, "%d,%49[^\n]\n", &db->entries[db->count].id, db->entries[db->count].name) == 2) {
        db->count++;
    }
    fclose(file);
    printf("Database loaded from 'database.txt'.\n");
}

int main() {
    Database myDatabase;
    init_database(&myDatabase);
    
    load_from_file(&myDatabase);

    int choice;
    do {
        printf("\n=== Sherlock's Database Menu ===\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. List Entries\n");
        printf("4. Save Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        if (choice == 1) {
            int id;
            char name[NAME_LENGTH];
            printf("Enter ID: ");
            scanf("%d", &id);
            getchar(); // Clear newline character
            printf("Enter Name: ");
            fgets(name, NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0; // Remove trailing newline
            add_entry(&myDatabase, id, name);
        } else if (choice == 2) {
            char query[NAME_LENGTH];
            printf("Enter search term: ");
            fgets(query, NAME_LENGTH, stdin);
            query[strcspn(query, "\n")] = 0; // Remove trailing newline
            search_entry(&myDatabase, query);
        } else if (choice == 3) {
            list_entries(&myDatabase);
        } else if (choice == 4) {
            save_to_file(&myDatabase);
        }
    } while (choice != 5);

    printf("Departing from the case files, until next time!\n");
    return 0;
}