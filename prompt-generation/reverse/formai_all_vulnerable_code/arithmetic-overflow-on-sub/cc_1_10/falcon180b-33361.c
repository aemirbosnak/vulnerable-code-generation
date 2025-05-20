//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    char address[MAX_FIELD_SIZE];
} Record;

Record database[MAX_RECORDS];
int numRecords = 0;

void addRecord() {
    if (numRecords == MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[numRecords].name);

    printf("Enter age: ");
    scanf("%d", &database[numRecords].age);

    printf("Enter address: ");
    scanf("%s", database[numRecords].address);

    numRecords++;
}

void displayRecord(int index) {
    if (index >= numRecords || index < 0) {
        printf("Invalid record index.\n");
        return;
    }

    printf("Name: %s\n", database[index].name);
    printf("Age: %d\n", database[index].age);
    printf("Address: %s\n", database[index].address);
}

void searchRecord(char *name) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            displayRecord(i);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    int choice;
    char name[MAX_NAME_SIZE];

    do {
        printf("\nDatabase Management System\n");
        printf("1. Add record\n");
        printf("2. Display record\n");
        printf("3. Search record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printf("Enter record index: ");
                scanf("%d", &choice);
                displayRecord(choice - 1);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchRecord(name);
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