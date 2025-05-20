//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function prototypes
void addRecord(Database* db, int id, const char* name);
void displayRecords(const Database* db);
int binarySearch(const Database* db, int id);
void sortRecords(Database* db);
void freeDatabase(Database* db);

int main() {
    Database db;
    db.count = 0;
    int choice, id;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\n--- Simple Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
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
                displayRecords(&db);
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int index = binarySearch(&db, id);
                if (index != -1) {
                    printf("Record Found - ID: %d, Name: %s\n", db.records[index].id, db.records[index].name);
                } else {
                    printf("Record not found!\n");
                }
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeDatabase(&db);
    return 0;
}

void addRecord(Database* db, int id, const char* name) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        db->count++;
        sortRecords(db);
        printf("Record added successfully.\n");
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void displayRecords(const Database* db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\nRecords in the Database:\n");
    printf("%-10s %-20s\n", "ID", "Name");
    printf("-----------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%-10d %-20s\n", db->records[i].id, db->records[i].name);
    }
}

int binarySearch(const Database* db, int id) {
    int left = 0;
    int right = db->count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (db->records[mid].id == id) {
            return mid; // Record found
        }
        
        if (db->records[mid].id < id) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    
    return -1; // Record not found
}

void sortRecords(Database* db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (db->records[j].id > db->records[j + 1].id) {
                Record temp = db->records[j];
                db->records[j] = db->records[j + 1];
                db->records[j + 1] = temp;
            }
        }
    }
}

void freeDatabase(Database* db) {
    // Currently, we don't have dynamic memory allocation but a function can help in future scalability.
    memset(db, 0, sizeof(Database)); // Reset the database
}