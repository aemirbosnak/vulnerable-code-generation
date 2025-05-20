//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 150

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

Database db;

void initializeDatabase() {
    db.count = 0;
}

void addRecord() {
    if (db.count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    Record newRecord;
    newRecord.id = db.count + 1; // Assign an ID based on current count

    printf("Enter name for record %d: ", newRecord.id);
    scanf(" %[^\n]%*c", newRecord.name); // Read string with spaces

    printf("Enter description for record %d: ", newRecord.id);
    scanf(" %[^\n]%*c", newRecord.description);

    db.records[db.count] = newRecord;
    db.count++;
    printf("Record added successfully!\n");
}

void viewRecords() {
    if (db.count == 0) {
        printf("No records in the database.\n");
        return;
    }
    
    printf("\n--- Records ---\n");
    for (int i = 0; i < db.count; i++) {
        printf("ID: %d\n", db.records[i].id);
        printf("Name: %s\n", db.records[i].name);
        printf("Description: %s\n\n", db.records[i].description);
    }
}

void searchRecord() {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]%*c", name);

    int found = 0;
    for (int i = 0; i < db.count; i++) {
        if (strcmp(db.records[i].name, name) == 0) {
            printf("Record found:\n");
            printf("ID: %d\n", db.records[i].id);
            printf("Name: %s\n", db.records[i].name);
            printf("Description: %s\n", db.records[i].description);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No record found with the name: %s\n", name);
    }
}

void deleteRecord() {
    int id;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > db.count) {
        printf("Invalid ID. Record cannot be found.\n");
        return;
    }

    for (int i = id - 1; i < db.count - 1; i++) {
        db.records[i] = db.records[i + 1]; // Shift records to the left
    }
    
    db.count--;
    printf("Record deleted successfully!\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    initializeDatabase();
    menu();
    return 0;
}