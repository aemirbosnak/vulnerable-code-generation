//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct record {
    int id;
    char name[50];
    int age;
} Record;

void addRecord(Record records[MAX_RECORDS], int *numRecords);
void displayRecords(Record records[MAX_RECORDS], int numRecords);
void searchRecord(Record records[MAX_RECORDS], int numRecords);
void deleteRecord(Record records[MAX_RECORDS], int *numRecords);

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int choice;
    while (1) {
        printf("\nPress 1 to add record.\n");
        printf("Press 2 to display records.\n");
        printf("Press 3 to search record.\n");
        printf("Press 4 to delete record.\n");
        printf("Press 5 to exit.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(records, &numRecords);
                    break;
            case 2: displayRecords(records, numRecords);
                    break;
            case 3: searchRecord(records, numRecords);
                    break;
            case 4: deleteRecord(records, &numRecords);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice entered!\n");
        }
    }
    return 0;
}

void addRecord(Record records[MAX_RECORDS], int *numRecords) {
    if (*numRecords == MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    Record newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    printf("Enter Age: ");
    scanf("%d", &newRecord.age);

    records[*numRecords] = newRecord;
    (*numRecords)++;
    printf("Record added successfully!\n");
}

void displayRecords(Record records[MAX_RECORDS], int numRecords) {
    if (numRecords == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("ID \tName \tAge \n");
    for (int i = 0; i < numRecords; ++i) {
        printf("%d \t%s \t%d \n", records[i].id, records[i].name, records[i].age);
    }
}

void searchRecord(Record records[MAX_RECORDS], int numRecords) {
    if (numRecords == 0) {
        printf("Database is empty!\n");
        return;
    }

    int searchId;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    int found = 0;
    for (int i = 0; i < numRecords; ++i) {
        if (records[i].id == searchId) {
            printf("Record Found!\n");
            printf("ID: %d\nName: %s\nAge: %d\n", records[i].id, records[i].name, records[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

void deleteRecord(Record records[MAX_RECORDS], int *numRecords) {
    if (*numRecords == 0) {
        printf("Database is empty!\n");
        return;
    }

    int deleteId;
    printf("Enter ID to delete: ");
    scanf("%d", &deleteId);

    int found = 0;
    for (int i = 0; i < *numRecords; ++i) {
        if (records[i].id == deleteId) {
            found = 1;
            for (int j = i; j < *numRecords - 1; ++j) {
                records[j] = records[j+1];
            }
            (*numRecords)--;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}