//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records that can be stored in the database
#define MAX_RECORDS 100

typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

Record database[MAX_RECORDS]; // The database array
int numRecords = 0; // The number of records currently in the database

void menu() {
    printf("Database Menu:\n");
    printf("1. Add record\n");
    printf("2. Search record\n");
    printf("3. Display all records\n");
    printf("4. Exit\n");
}

void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Database is full. Cannot add record.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", &database[numRecords].name);

    printf("Enter age: ");
    scanf("%d", &database[numRecords].age);

    printf("Enter salary: ");
    scanf("%f", &database[numRecords].salary);

    numRecords++;

    printf("Record added successfully.\n");
}

void searchRecord() {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(name, database[i].name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Salary: %f\n", database[i].salary);
            return;
        }
    }

    printf("Record not found.\n");
}

void displayAllRecords() {
    if (numRecords == 0) {
        printf("No records in database.\n");
        return;
    }

    printf("All records:\n");
    int i;
    for (i = 0; i < numRecords; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Salary: %f\n", database[i].salary);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                displayAllRecords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}