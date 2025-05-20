//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: decentralized
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

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    Record newRecord;
    newRecord.id = db->count + 1; // Simple auto-increment ID

    printf("Enter name: ");
    fgets(newRecord.name, MAX_NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(newRecord.email, MAX_EMAIL_LENGTH, stdin);
    newRecord.email[strcspn(newRecord.email, "\n")] = '\0'; // Remove newline

    db->records[db->count] = newRecord;
    db->count++;

    printf("Record added successfully!\n");
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\nRecords in Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", 
                db->records[i].id, 
                db->records[i].name, 
                db->records[i].email);
    }
}

void deleteRecord(Database *db) {
    if (db->count == 0) {
        printf("No records to delete.\n");
        return;
    }

    int idToDelete;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &idToDelete);
    getchar(); // Clear newline from input buffer

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == idToDelete) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift left
            }
            db->count--;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", idToDelete);
    }
}

void saveDatabaseToFile(const Database *db, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database saved to %s successfully.\n", filename);
}

void loadDatabaseFromFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Unable to open file for reading.\n");
        return;
    }
    fread(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database loaded from %s successfully.\n", filename);
}

void displayMenu() {
    printf("\n=== Database Management System ===\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Save Database to File\n");
    printf("5. Load Database from File\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline from input buffer

        switch (option) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                deleteRecord(&db);
                break;
            case 4:
                saveDatabaseToFile(&db, "database.bin");
                break;
            case 5:
                loadDatabaseFromFile(&db, "database.bin");
                break;
            case 6:
                printf("Exiting the database management system.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}