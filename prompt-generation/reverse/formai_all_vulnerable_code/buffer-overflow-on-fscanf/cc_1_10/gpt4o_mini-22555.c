//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DATA_LENGTH 255

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char data[DATA_LENGTH];
} DatabaseEntry;

typedef struct {
    DatabaseEntry entries[MAX_ENTRIES];
    int size;
} Database;

// Function prototypes
void initializeDatabase(Database* db);
void addEntry(Database* db);
void displayEntries(const Database* db);
void searchEntry(const Database* db);
void deleteEntry(Database* db);
void saveDatabaseToFile(const Database* db, const char* filename);
void loadDatabaseFromFile(Database* db, const char* filename);

int main() {
    Database db;
    char choice;
    char filename[] = "database.txt";

    loadDatabaseFromFile(&db, filename);
    
    while (1) {
        printf("\n--- Simple Database Management ---\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Please select an option (1-6): ");
        choice = getchar();
        getchar(); // Consume newline character

        switch (choice) {
            case '1':
                addEntry(&db);
                break;
            case '2':
                displayEntries(&db);
                break;
            case '3':
                searchEntry(&db);
                break;
            case '4':
                deleteEntry(&db);
                break;
            case '5':
                saveDatabaseToFile(&db, filename);
                printf("Database saved to %s.\n", filename);
                break;
            case '6':
                saveDatabaseToFile(&db, filename);
                printf("Exiting program. Database saved to %s.\n", filename);
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}

void initializeDatabase(Database* db) {
    db->size = 0;
}

void addEntry(Database* db) {
    if (db->size >= MAX_ENTRIES) {
        printf("Database is full. Cannot add more entries.\n");
        return;
    }

    int id = db->size + 1;
    DatabaseEntry entry;
    entry.id = id;

    printf("Enter Name: ");
    fgets(entry.name, NAME_LENGTH, stdin);
    entry.name[strcspn(entry.name, "\n")] = 0; // Remove newline

    printf("Enter Data: ");
    fgets(entry.data, DATA_LENGTH, stdin);
    entry.data[strcspn(entry.data, "\n")] = 0; // Remove newline

    db->entries[db->size] = entry;
    db->size++;
    printf("Entry added successfully with ID: %d\n", id);
}

void displayEntries(const Database* db) {
    printf("\n--- Database Entries ---\n");
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s, Data: %s\n", db->entries[i].id, db->entries[i].name, db->entries[i].data);
    }
}

void searchEntry(const Database* db) {
    int id;
    printf("Enter ID of the entry to search: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    for (int i = 0; i < db->size; i++) {
        if (db->entries[i].id == id) {
            printf("Found Entry - ID: %d, Name: %s, Data: %s\n", db->entries[i].id, db->entries[i].name, db->entries[i].data);
            return;
        }
    }
    printf("Entry with ID %d not found.\n", id);
}

void deleteEntry(Database* db) {
    int id;
    printf("Enter ID of the entry to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    for (int i = 0; i < db->size; i++) {
        if (db->entries[i].id == id) {
            for (int j = i; j < db->size - 1; j++) {
                db->entries[j] = db->entries[j + 1];
            }
            db->size--;
            printf("Entry with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Entry with ID %d not found.\n", id);
}

void saveDatabaseToFile(const Database* db, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < db->size; i++) {
        fprintf(file, "%d,%s,%s\n", db->entries[i].id, db->entries[i].name, db->entries[i].data);
    }
    
    fclose(file);
}

void loadDatabaseFromFile(Database* db, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No existing database found. Starting a new one.\n");
        initializeDatabase(db);
        return;
    }

    db->size = 0;
    while (fscanf(file, "%d,%49[^,],%254[^\n]\n", &db->entries[db->size].id, db->entries[db->size].name, db->entries[db->size].data) == 3) {
        db->size++;
        if (db->size >= MAX_ENTRIES) break; // Prevent overflow
    }

    fclose(file);
}