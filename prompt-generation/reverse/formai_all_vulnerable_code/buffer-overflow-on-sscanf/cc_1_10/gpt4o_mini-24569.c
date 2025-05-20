//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function prototypes
void initializeDatabase(Database* db);
void addRecord(Database* db);
void displayRecords(const Database* db);
void searchRecord(const Database* db);
void saveDatabaseToFile(const Database* db, const char* filename);
void loadDatabaseFromFile(Database* db, const char* filename);

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    while (1) {
        printf("Database Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To capture the newline character after the integer input

        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                searchRecord(&db);
                break;
            case 4:
                saveDatabaseToFile(&db, "database.txt");
                break;
            case 5:
                loadDatabaseFromFile(&db, "database.txt");
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addRecord(Database* db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Unable to add more records.\n");
        return;
    }

    Record newRecord;
    newRecord.id = db->count + 1; // Unique ID for each record
    
    printf("Enter name: ");
    fgets(newRecord.name, NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // Remove newline character

    printf("Enter age: ");
    scanf("%d", &newRecord.age);
    getchar(); // Capture the newline character

    db->records[db->count] = newRecord;
    db->count++;
    printf("Record added successfully!\n");
}

void displayRecords(const Database* db) {
    if (db->count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nDisplaying all records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    printf("\n");
}

void searchRecord(const Database* db) {
    int id;
    printf("Enter record ID to search: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > db->count) {
        printf("Record not found!\n");
        return;
    }
    
    Record record = db->records[id - 1];
    printf("Record found: ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
}

void saveDatabaseToFile(const Database* db, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < db->count; i++) {
        fprintf(file, "%d,%s,%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    fclose(file);
    printf("Database saved to %s successfully!\n", filename);
}

void loadDatabaseFromFile(Database* db, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading!\n");
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) && db->count < MAX_RECORDS) {
        sscanf(buffer, "%d,%49[^,],%d", &db->records[db->count].id,
               db->records[db->count].name,
               &db->records[db->count].age);
        db->count++;
    }
    fclose(file);
    printf("Database loaded from %s successfully!\n", filename);
}