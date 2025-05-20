//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_SIZE 100
#define ADDRESS_SIZE 200

typedef struct {
    int id;
    char name[NAME_SIZE];
    char address[ADDRESS_SIZE];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function declarations
void initDatabase(Database* db);
void addRecord(Database* db);
void displayRecords(const Database* db);
void searchRecord(const Database* db);
void deleteRecord(Database* db);
void saveDatabaseToFile(const Database* db, const char* filename);
void loadDatabaseFromFile(Database* db, const char* filename);

int main() {
    Database db;
    initDatabase(&db);
    int choice;
    
    while (1) {
        printf("\n=== Simple Database Management ===\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                deleteRecord(&db);
                break;
            case 5:
                saveDatabaseToFile(&db, "database.txt");
                break;
            case 6:
                loadDatabaseFromFile(&db, "database.txt");
                break;
            case 7:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initDatabase(Database* db) {
    db->count = 0;
}

void addRecord(Database* db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    Record new_record;
    new_record.id = db->count + 1;

    printf("Enter name: ");
    fgets(new_record.name, NAME_SIZE, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = '\0';  // Remove newline

    printf("Enter address: ");
    fgets(new_record.address, ADDRESS_SIZE, stdin);
    new_record.address[strcspn(new_record.address, "\n")] = '\0';  // Remove newline

    db->records[db->count] = new_record;
    db->count++;
    printf("Record added successfully.\n");
}

void displayRecords(const Database* db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- Records in Database ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Address: %s\n", 
               db->records[i].id, db->records[i].name, db->records[i].address);
    }
}

void searchRecord(const Database* db) {
    int id;
    printf("Enter record ID to search: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    if (id < 1 || id > db->count) {
        printf("Record not found.\n");
        return;
    }

    Record rec = db->records[id - 1];
    printf("Record found -> ID: %d, Name: %s, Address: %s\n", 
           rec.id, rec.name, rec.address);
}

void deleteRecord(Database* db) {
    int id;
    printf("Enter record ID to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline character

    if (id < 1 || id > db->count) {
        printf("Record not found.\n");
        return;
    }

    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->count--;
    printf("Record deleted successfully.\n");
}

void saveDatabaseToFile(const Database* db, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }

    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database saved to %s.\n", filename);
}

void loadDatabaseFromFile(Database* db, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }

    fread(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Database loaded from %s.\n", filename);
}