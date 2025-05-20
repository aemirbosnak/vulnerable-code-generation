//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field1;
    char *field2;
    int field3;
} Record;

Record records[MAX_RECORDS];
int numRecords = 0;

void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Sorry, database full!\n");
        return;
    }

    Record *newRecord = &records[numRecords];
    newRecord->field1 = malloc(MAX_FIELD_SIZE);
    newRecord->field2 = malloc(MAX_FIELD_SIZE);
    newRecord->field3 = 0;

    printf("Enter field 1: ");
    scanf("%s", newRecord->field1);

    printf("Enter field 2: ");
    scanf("%s", newRecord->field2);

    numRecords++;
}

void displayRecords() {
    for (int i = 0; i < numRecords; i++) {
        printf("Record %d:\n", i + 1);
        printf("Field 1: %s\n", records[i].field1);
        printf("Field 2: %s\n", records[i].field2);
        printf("Field 3: %d\n\n", records[i].field3);
    }
}

void searchRecord() {
    char searchTerm[MAX_FIELD_SIZE];

    printf("Enter search term: ");
    scanf("%s", searchTerm);

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].field1, searchTerm) == 0 || strcmp(records[i].field2, searchTerm) == 0) {
            printf("Record %d:\n", i + 1);
            printf("Field 1: %s\n", records[i].field1);
            printf("Field 2: %s\n", records[i].field2);
            printf("Field 3: %d\n\n", records[i].field3);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Search record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            printf("Exiting database...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}