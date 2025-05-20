//FormAI DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
} Record;

Record database[MAX_RECORDS];
int currentRecords = 0;

void addRecord() {
    if (currentRecords < MAX_RECORDS) {
        Record newRecord;
        printf("Enter name: ");
        scanf("%s", newRecord.name);
        printf("Enter address: ");
        scanf("%s", newRecord.address);
        printf("Enter age: ");
        scanf("%d", &newRecord.age);
        database[currentRecords] = newRecord;
        currentRecords++;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full, cannot add more records!\n");
    }
}

void searchRecord() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i=0; i<currentRecords; i++) {
        if (strcmp(name, database[i].name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("Address: %s\n", database[i].address);
            printf("Age: %d\n", database[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

void deleteRecord() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i=0; i<currentRecords; i++) {
        if (strcmp(name, database[i].name) == 0) {
            for (int j=i+1; j<currentRecords; j++) {
                database[j-1] = database[j];
            }
            currentRecords--;
            printf("Record deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

void printAllRecords() {
    if (currentRecords == 0) {
        printf("Database is empty!\n");
    } else {
        printf("All records in database:\n");
        for (int i=0; i<currentRecords; i++) {
            printf("Name: %s\n", database[i].name);
            printf("Address: %s\n", database[i].address);
            printf("Age: %d\n", database[i].age);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Print All Records\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                printAllRecords();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}