//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
}

int addRecord(Database* db, char* name, char* email) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return -1;
    }
    Record* newRecord = &db->records[db->count];
    newRecord->id = db->count + 1; // IDs start from 1
    strncpy(newRecord->name, name, MAX_NAME_LENGTH);
    strncpy(newRecord->email, email, MAX_EMAIL_LENGTH);
    db->count++;
    printf("Record added: ID = %d, Name = %s, Email = %s\n", newRecord->id, newRecord->name, newRecord->email);
    return 0;
}

void displayRecords(const Database* db) {
    printf("\nCurrent Records in the Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

Record* findRecordById(const Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

int updateRecord(Database* db, int id, char* name, char* email) {
    Record* record = findRecordById(db, id);
    if (record == NULL) {
        printf("Record with ID %d not found.\n", id);
        return -1;
    }
    strncpy(record->name, name, MAX_NAME_LENGTH);
    strncpy(record->email, email, MAX_EMAIL_LENGTH);
    printf("Record updated: ID = %d, Name = %s, Email = %s\n", record->id, record->name, record->email);
    return 0;
}

int deleteRecord(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift left
            }
            db->count--;
            printf("Record with ID %d deleted.\n", id);
            return 0;
        }
    }
    printf("Record with ID %d not found.\n", id);
    return -1;
}

void saveDatabaseToFile(const Database* db, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database saved to %s\n", filename);
}

void loadDatabaseFromFile(Database* db, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database loaded from %s\n", filename);
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int id;
    const char* filename = "database.dat";

    while (1) {
        printf("\n1. Add Record\n2. Display Records\n3. Update Record\n4. Delete Record\n5. Save Database\n6. Load Database\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addRecord(&db, name, email);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new name: ");
                scanf("%s", name);
                printf("Enter new email: ");
                scanf("%s", email);
                updateRecord(&db, id, name, email);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            case 5:
                saveDatabaseToFile(&db, filename);
                break;
            case 6:
                loadDatabaseFromFile(&db, filename);
                break;
            case 7:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}