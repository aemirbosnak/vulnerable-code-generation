//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DATABASE_FILE "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database* db) {
    db->count = 0;
}

int addRecord(Database* db, int id, const char* name) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return -1;
    }
    db->records[db->count].id = id;
    strncpy(db->records[db->count].name, name, NAME_LENGTH - 1);
    db->records[db->count].name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    db->count++;
    return 0;
}

int findRecordById(Database* db, int id, Record* result) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            *result = db->records[i];
            return 0; // Record found
        }
    }
    return -1; // Record not found
}

void displayDatabase(Database* db) {
    printf("Database Records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
}

void saveDatabaseToFile(Database* db) {
    FILE* file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        fprintf(file, "%d,%s\n", db->records[i].id, db->records[i].name);
    }
    fclose(file);
    printf("Database saved to %s\n", DATABASE_FILE);
}

void loadDatabaseFromFile(Database* db) {
    FILE* file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Could not open file for reading.\n");
        return;
    }
    initDatabase(db);
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        int id;
        char name[NAME_LENGTH];
        if (sscanf(line, "%d,%49s", &id, name) == 2) {
            addRecord(db, id, name);
        }
    }
    fclose(file);
    printf("Database loaded from %s\n", DATABASE_FILE);
}

int main() {
    Database db;
    initDatabase(&db);
    
    loadDatabaseFromFile(&db);
    
    int choice, id;
    char name[NAME_LENGTH];
    
    while (1) {
        printf("\nDatabase Indexing System Menu:\n");
        printf("1. Add Record\n");
        printf("2. Find Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(&db, id, name);
                break;
            case 2:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                Record foundRecord;
                if (findRecordById(&db, id, &foundRecord) == 0) {
                    printf("Found - ID: %d, Name: %s\n", foundRecord.id, foundRecord.name);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 3:
                displayDatabase(&db);
                break;
            case 4:
                saveDatabaseToFile(&db);
                break;
            case 5:
                loadDatabaseFromFile(&db);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}