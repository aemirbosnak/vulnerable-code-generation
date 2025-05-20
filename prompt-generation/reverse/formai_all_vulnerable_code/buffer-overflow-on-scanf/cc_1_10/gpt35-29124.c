//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 5
#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 30

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Record;

void createRecord(Record *record) {
    printf("Enter ID: ");
    scanf("%d", &record->id);
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter email: ");
    scanf("%s", record->email);
}

void printRecord(Record record) {
    printf("--------------------------------\n");
    printf("ID: %d\nName: %s\nEmail: %s\n", record.id, record.name, record.email);
}

void createDatabase(Record *database, int *numRecords) {
    printf("Creating database...\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        createRecord(&database[i]);
        (*numRecords)++;
    }
}

int findRecordById(Record *database, int numRecords, int id) {
    for (int i = 0; i < numRecords; i++) {
        if (id == database[i].id) {
            return i;
        }
    }
    return -1;
}

void updateRecord(Record *database, int numRecords, int id) {
    int index = findRecordById(database, numRecords, id);
    if (index >= 0) {
        createRecord(&database[index]);
        printf("Record updated successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

void deleteRecord(Record *database, int *numRecords, int id) {
    int index = findRecordById(database, *numRecords, id);
    if (index >= 0) {
        for (int i = index; i < (*numRecords) - 1; i++) {
            database[i] = database[i + 1];
        }
        (*numRecords)--;
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

void printDatabase(Record *database, int numRecords) {
    printf("Printing database...\n");
    for (int i = 0; i < numRecords; i++) {
        printRecord(database[i]);
    }
}

int main() {
    Record database[MAX_RECORDS];
    int numRecords = 0;
    int choice;
    int id;

    while (1) {
        printf("1. Create database\n");
        printf("2. Update record\n");
        printf("3. Delete record\n");
        printf("4. Print records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createDatabase(database, &numRecords);
                break;
            case 2:
                printf("Enter ID of record to update: ");
                scanf("%d", &id);
                updateRecord(database, numRecords, id);
                break;
            case 3:
                printf("Enter ID of record to delete: ");
                scanf("%d", &id);
                deleteRecord(database, &numRecords, id);
                break;
            case 4:
                printDatabase(database, numRecords);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}