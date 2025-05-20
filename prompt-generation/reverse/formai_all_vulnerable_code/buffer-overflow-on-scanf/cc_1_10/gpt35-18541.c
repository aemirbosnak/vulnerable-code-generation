//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    int age;
};

void displayMenu();
void addRecord(struct Record records[], int *numRecords);
void searchRecord(struct Record records[], int numRecords);
void deleteRecord(struct Record records[], int *numRecords);
void displayRecords(struct Record records[], int numRecords);

int main() {
    struct Record records[MAX_RECORDS];
    int choice, numRecords = 0;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &numRecords);
                break;
            case 2:
                searchRecord(records, numRecords);
                break;
            case 3:
                deleteRecord(records, &numRecords);
                break;
            case 4:
                displayRecords(records, numRecords);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n");
    printf("==== Database Simulation ====\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Delete Record\n");
    printf("4. Display All Records\n");
    printf("5. Exit\n");
}

void addRecord(struct Record records[], int *numRecords) {
    if (*numRecords == MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    struct Record newRecord;

    printf("Enter the following details:\n");
    printf("ID: ");
    scanf("%d", &newRecord.id);
    printf("Name: ");
    scanf("%s", newRecord.name);
    printf("Age: ");
    scanf("%d", &newRecord.age);

    records[*numRecords] = newRecord;
    *numRecords += 1;

    printf("Record added successfully!\n");
}

void searchRecord(struct Record records[], int numRecords) {
    int idToSearch, i;

    printf("Enter ID to search: ");
    scanf("%d", &idToSearch);

    for (i = 0; i < numRecords; i++) {
        if (records[i].id == idToSearch) {
            printf("Record Found!\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            return;
        }
    }

    printf("Record not found!\n");
}

void deleteRecord(struct Record records[], int *numRecords) {
    int idToDelete, i, j;

    printf("Enter ID to delete: ");
    scanf("%d", &idToDelete);

    for (i = 0; i < *numRecords; i++) {
        if (records[i].id == idToDelete) {
            // shift all elements after i by one position to the left
            for (j = i; j < *numRecords - 1; j++) {
                records[j] = records[j+1];
            }

            *numRecords -= 1;

            printf("Record deleted successfully!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void displayRecords(struct Record records[], int numRecords) {
    int i;

    if (numRecords == 0) {
        printf("No records found!\n");
        return;
    }

    printf("ID | Name | Age\n");
    printf("------------------------\n");

    for (i = 0; i < numRecords; i++) {
        printf("%d | %s | %d\n", records[i].id, records[i].name, records[i].age);
    }
}