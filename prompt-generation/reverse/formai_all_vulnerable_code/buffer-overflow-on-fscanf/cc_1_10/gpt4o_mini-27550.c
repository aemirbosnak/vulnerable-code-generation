//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, const char *name, const char *description) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = db->count + 1; // Auto-increment ID
        strncpy(db->records[db->count].name, name, NAME_LENGTH - 1);
        db->records[db->count].name[NAME_LENGTH - 1] = '\0'; // Ensure null-terminated
        strncpy(db->records[db->count].description, description, DESC_LENGTH - 1);
        db->records[db->count].description[DESC_LENGTH - 1] = '\0'; // Ensure null-terminated
        db->count++;
        printf("Record added: ID = %d, Name = %s\n", db->records[db->count - 1].id, db->records[db->count - 1].name);
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void displayRecords(Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n--- Database Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d\nName: %s\nDescription: %s\n\n", db->records[i].id, db->records[i].name, db->records[i].description);
    }
}

void findRecordByID(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID = %d, Name = %s, Description = %s\n", db->records[i].id, db->records[i].name, db->records[i].description);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecordByID(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift records left
            }
            db->count--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void saveDatabaseToFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        fprintf(file, "%d;%s;%s\n", db->records[i].id, db->records[i].name, db->records[i].description);
    }
    fclose(file);
    printf("Database saved to %s.\n", filename);
}

void loadDatabaseFromFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file for reading.\n");
        return;
    }
    initializeDatabase(db);
    while (!feof(file) && db->count < MAX_RECORDS) {
        Record rec;
        fscanf(file, "%d;%49[^;];%199[^\n]\n", &rec.id, rec.name, rec.description);
        db->records[db->count++] = rec;
    }
    fclose(file);
    printf("Database loaded from %s with %d records.\n", filename, db->count);
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;
    char name[NAME_LENGTH], description[DESC_LENGTH];
    char filename[100];

    do {
        printf("\n--- Simple Database Simulation ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Find Record by ID\n");
        printf("4. Delete Record by ID\n");
        printf("5. Save Database to File\n");
        printf("6. Load Database from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter description: ");
                scanf(" %[^\n]", description);
                addRecord(&db, name, description);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                printf("Enter ID to find: ");
                int findID;
                scanf("%d", &findID);
                findRecordByID(&db, findID);
                break;
            case 4:
                printf("Enter ID to delete: ");
                int deleteID;
                scanf("%d", &deleteID);
                deleteRecordByID(&db, deleteID);
                break;
            case 5:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveDatabaseToFile(&db, filename);
                break;
            case 6:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadDatabaseFromFile(&db, filename);
                break;
            case 7:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}