//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

int numRecords = 0;
Record records[MAX_RECORDS];

int addRecord(char* name, char* value) {
    if (numRecords >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return 1;
    }

    strcpy(records[numRecords].name, name);
    strcpy(records[numRecords].value, value);
    numRecords++;

    return 0;
}

int searchRecord(char* name) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Record found:\nName: %s\nValue: %s\n", records[i].name, records[i].value);
            return 0;
        }
    }

    printf("Record not found.\n");
    return 1;
}

int deleteRecord(char* name) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, name) == 0) {
            memcpy(&records[i], &records[numRecords - 1], sizeof(Record));
            numRecords--;

            printf("Record deleted.\n");
            return 0;
        }
    }

    printf("Record not found.\n");
    return 1;
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];

    do {
        printf("1. Add record\n2. Search record\n3. Delete record\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter value: ");
                scanf("%s", value);
                addRecord(name, value);
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchRecord(name);
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteRecord(name);
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