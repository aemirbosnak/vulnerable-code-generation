//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    char city[MAX_FIELD_SIZE];
} Record;

Record database[MAX_RECORDS];
int numRecords = 0;

void createTable() {
    printf("Enter table name: ");
    scanf("%s", &database[0].name);
    printf("Enter number of fields: ");
    scanf("%d", &numRecords);
}

void addRecord() {
    printf("Enter record values:\n");
    printf("Name: ");
    scanf("%s", &database[numRecords].name);
    printf("Age: ");
    scanf("%d", &database[numRecords].age);
    printf("City: ");
    scanf("%s", &database[numRecords].city);
    numRecords++;
}

void displayRecord() {
    printf("Record:\n");
    printf("Name: %s\n", database[numRecords - 1].name);
    printf("Age: %d\n", database[numRecords - 1].age);
    printf("City: %s\n", database[numRecords - 1].city);
}

int main() {
    createTable();

    while (1) {
        printf("\n1. Add Record\n2. Display Record\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecord();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}