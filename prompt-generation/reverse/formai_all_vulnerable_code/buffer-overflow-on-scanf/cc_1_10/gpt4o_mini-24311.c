//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: unmistakable
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

void addRecord(Database *db, const char *name, const char *email) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = db->count + 1;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH - 1);
        db->records[db->count].name[MAX_NAME_LENGTH - 1] = '\0'; // Null-terminating
        strncpy(db->records[db->count].email, email, MAX_EMAIL_LENGTH - 1);
        db->records[db->count].email[MAX_EMAIL_LENGTH - 1] = '\0'; // Null-terminating
        db->count++;
        printf("Record added successfully.\n");
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records found in the database.\n");
        return;
    }
    printf("\nList of Records:\n");
    printf("ID\tName\t\t\tEmail\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%-20s\t%s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

void searchRecordById(const Database *db, int id) {
    if (id <= 0 || id > db->count) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    Record record = db->records[id - 1];
    printf("\nRecord Found:\n");
    printf("ID: %d\nName: %s\nEmail: %s\n", record.id, record.name, record.email);
}

void deleteRecord(Database *db, int id) {
    if (id <= 0 || id > db->count) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Record with ID %d deleted successfully.\n", id);
}

void saveDatabaseToFile(const Database *db, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database saved to '%s' successfully.\n", filename);
}

void loadDatabaseFromFile(Database *db, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database loaded from '%s' successfully.\n", filename);
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice, id;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    const char *filename = "database.dat";

    while (1) {
        printf("\n-----------------------\n");
        printf(" Simple Database Menu\n");
        printf("-----------------------\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Delete Record by ID\n");
        printf("5. Save Database to File\n");
        printf("6. Load Database from File\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter Email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                addRecord(&db, name, email);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecordById(&db, id);
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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}