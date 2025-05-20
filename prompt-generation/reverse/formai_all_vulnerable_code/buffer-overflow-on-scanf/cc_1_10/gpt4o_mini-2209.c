//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3
#define CITY_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char city[CITY_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full, cannot add more records.\n");
        return;
    }
    
    Record newRecord;
    printf("Enter name: ");
    scanf(" %[^\n]", newRecord.name);
    printf("Enter age: ");
    scanf("%d", &newRecord.age);
    printf("Enter city: ");
    scanf(" %[^\n]", newRecord.city);
    
    db->records[db->count++] = newRecord;
    printf("Record added successfully!\n");
}

void removeRecord(Database *db) {
    char name[NAME_LENGTH];
    printf("Enter the name of the record to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            db->records[i] = db->records[--db->count]; // Remove record by replacing it with the last one.
            printf("Record removed successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

void displayRecords(Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("Records in Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Record %d: Name: %s, Age: %d, City: %s\n",
               i + 1, db->records[i].name, db->records[i].age, db->records[i].city);
    }
}

void saveDatabaseToFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database saved successfully to %s\n", filename);
}

void loadDatabaseFromFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }
    fread(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database loaded successfully from %s\n", filename);
}

void menu(Database *db) {
    int choice;
    const char *filename = "database.bin";

    do {
        printf("\n--- Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Remove Record\n");
        printf("3. Display Records\n");
        printf("4. Save Database to File\n");
        printf("5. Load Database from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(db);
                break;
            case 2:
                removeRecord(db);
                break;
            case 3:
                displayRecords(db);
                break;
            case 4:
                saveDatabaseToFile(db, filename);
                break;
            case 5:
                loadDatabaseFromFile(db, filename);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    Database db;
    initializeDatabase(&db);
    menu(&db);
    return 0;
}