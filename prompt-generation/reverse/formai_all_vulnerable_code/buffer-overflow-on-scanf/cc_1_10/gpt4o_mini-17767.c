//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

void initializeDatabase(Record db[], int *currentIndex) {
    *currentIndex = 0;
    printf("Database initialized. Ready to store records.\n");
}

void addRecord(Record db[], int *currentIndex) {
    if (*currentIndex >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record newRecord;
    newRecord.id = *currentIndex + 1; // ID starts from 1
    printf("Enter name: ");
    scanf(" %[^\n]s", newRecord.name);
    printf("Enter email: ");
    scanf(" %[^\n]s", newRecord.email);

    db[*currentIndex] = newRecord;
    (*currentIndex)++;
    printf("Record added successfully!\n");
}

void displayRecords(Record db[], int currentIndex) {
    if (currentIndex == 0) {
        printf("No records in the database.\n");
        return;
    }
    printf("\n--- Database Records ---\n");
    for (int i = 0; i < currentIndex; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", db[i].id, db[i].name, db[i].email);
    }
}

void deleteRecord(Record db[], int *currentIndex) {
    if (*currentIndex == 0) {
        printf("No records to delete.\n");
        return;
    }
    int id;
    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *currentIndex; i++) {
        if (db[i].id == id) {
            for (int j = i; j < *currentIndex - 1; j++) {
                db[j] = db[j + 1];
            }
            (*currentIndex)--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record with ID %d not found!\n", id);
}

void searchRecord(Record db[], int currentIndex) {
    if (currentIndex == 0) {
        printf("No records to search.\n");
        return;
    }
    char query[NAME_LENGTH];
    printf("Enter name or email to search: ");
    scanf(" %[^\n]s", query);

    int found = 0;
    for (int i = 0; i < currentIndex; i++) {
        if (strstr(db[i].name, query) || strstr(db[i].email, query)) {
            printf("Found - ID: %d, Name: %s, Email: %s\n", db[i].id, db[i].name, db[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found matching '%s'.\n", query);
    }
}

void menu() {
    printf("\n--- Simple Database Menu ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Search Record\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Record db[MAX_RECORDS];
    int currentIndex;

    initializeDatabase(db, &currentIndex);

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(db, &currentIndex);
                break;
            case 2:
                displayRecords(db, currentIndex);
                break;
            case 3:
                deleteRecord(db, &currentIndex);
                break;
            case 4:
                searchRecord(db, currentIndex);
                break;
            case 5:
                printf("Exiting... Thank you for using the database!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}