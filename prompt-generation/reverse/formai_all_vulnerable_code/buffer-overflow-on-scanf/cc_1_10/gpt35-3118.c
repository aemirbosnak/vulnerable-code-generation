//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

void insertRecord(Record records[], int *numRecords) {
    if (*numRecords >= MAX_RECORDS) {
        printf("Error: maximum number of records reached.\n");
        return;
    }

    Record newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter age: ");
    scanf("%d", &newRecord.age);
    printf("Enter salary: ");
    scanf("%f", &newRecord.salary);

    records[*numRecords] = newRecord;
    (*numRecords)++;

    printf("Record inserted successfully.\n");
}

void deleteRecord(Record records[], int *numRecords) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int foundIndex = -1;
    for (int i = 0; i < *numRecords; i++) {
        if (records[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Error: record not found.\n");
        return;
    }

    for (int i = foundIndex; i < (*numRecords) - 1; i++) {
        records[i] = records[i + 1];
    }
    (*numRecords)--;

    printf("Record deleted successfully.\n");
}

void updateRecord(Record records[], int numRecords) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int foundIndex = -1;
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Error: record not found.\n");
        return;
    }

    printf("Current name: %s\n", records[foundIndex].name);
    printf("Enter new name (or enter '.' to skip): ");
    char newName[50];
    scanf("%s", newName);

    if (strcmp(newName, ".") != 0) {
        strcpy(records[foundIndex].name, newName);
    }

    printf("Current age: %d\n", records[foundIndex].age);
    printf("Enter new age (or enter -1 to skip): ");
    int newAge;
    scanf("%d", &newAge);

    if (newAge != -1) {
        records[foundIndex].age = newAge;
    }

    printf("Current salary: %.2f\n", records[foundIndex].salary);
    printf("Enter new salary (or enter -1 to skip): ");
    float newSalary;
    scanf("%f", &newSalary);

    if (newSalary != -1) {
        records[foundIndex].salary = newSalary;
    }

    printf("Record updated successfully.\n");
}

void displayRecord(Record record) {
    printf("%d\t%s\t%d\t%.2f\n", record.id, record.name, record.age, record.salary);
}

void displayAllRecords(Record records[], int numRecords) {
    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("ID\tName\tAge\tSalary\n");

    for (int i = 0; i < numRecords; i++) {
        displayRecord(records[i]);
    }
}

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int choice;

    do {
        printf("\n1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Update record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRecord(records, &numRecords);
                break;
            case 2:
                deleteRecord(records, &numRecords);
                break;
            case 3:
                updateRecord(records, numRecords);
                break;
            case 4:
                displayAllRecords(records, numRecords);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}