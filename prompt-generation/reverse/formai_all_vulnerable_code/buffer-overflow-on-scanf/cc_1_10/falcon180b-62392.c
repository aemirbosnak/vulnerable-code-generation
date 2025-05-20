//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

int numRecords = 0;
Record database[MAX_RECORDS];

void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    Record newRecord;
    printf("Enter record name: ");
    scanf("%s", newRecord.name);

    printf("Enter record value: ");
    scanf("%s", newRecord.value);

    strcpy(database[numRecords].name, newRecord.name);
    strcpy(database[numRecords].value, newRecord.value);

    numRecords++;
    printf("Record added successfully.\n");
}

void viewRecords() {
    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Record Name\tRecord Value\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s\t%s\n", database[i].name, database[i].value);
    }
}

void searchRecord() {
    char searchName[MAX_NAME_LENGTH];

    printf("Enter record name to search: ");
    scanf("%s", searchName);

    int index = -1;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
    } else {
        printf("Record found:\n");
        printf("Name: %s\n", database[index].name);
        printf("Value: %s\n", database[index].value);
    }
}

void deleteRecord() {
    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    char deleteName[MAX_NAME_LENGTH];

    printf("Enter record name to delete: ");
    scanf("%s", deleteName);

    int index = -1;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, deleteName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
    } else {
        for (int i = index; i < numRecords - 1; i++) {
            strcpy(database[i].name, database[i + 1].name);
            strcpy(database[i].value, database[i + 1].value);
        }

        numRecords--;
        printf("Record deleted successfully.\n");
    }
}

int main() {
    int choice;

    do {
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
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}