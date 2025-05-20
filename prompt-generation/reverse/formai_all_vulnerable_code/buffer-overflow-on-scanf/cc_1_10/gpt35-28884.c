//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    float gpa;
} Record;

void printRecord(Record r) {
    printf("ID: %d\n", r.id);
    printf("Name: %s\n", r.name);
    printf("GPA: %.2f\n", r.gpa);
}

int addRecord(Record records[], int numRecords) {
    if (numRecords == MAX_RECORDS) {
        printf("Error: Database is full!\n");
        return numRecords;
    }
    
    Record newRecord;
    
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    
    for (int i = 0; i < numRecords; i++) {
        if (newRecord.id == records[i].id) {
            printf("Error: Record with ID %d already exists!\n", newRecord.id);
            return numRecords;
        }
    }
    
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    
    printf("Enter GPA: ");
    scanf("%f", &newRecord.gpa);
    
    records[numRecords] = newRecord;
    printf("Record added successfully!\n");
    return numRecords + 1;
}

int deleteRecord(Record records[], int numRecords, int id) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            break;
        }
    }
    
    if (i == numRecords) {
        printf("Error: Record with ID %d not found!\n", id);
        return numRecords;
    }
    
    for (int j = i; j < numRecords - 1; j++) {
        records[j] = records[j+1];
    }
    
    printf("Record deleted successfully!\n");
    return numRecords - 1;
}

void searchRecord(Record records[], int numRecords, int id) {
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            printf("Record found:\n");
            printRecord(records[i]);
            return;
        }
    }
    
    printf("Error: Record with ID %d not found!\n", id);
}

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    
    printf("Welcome to Database Simulation Program!\n\n");
    
    while(1) {
        printf("Please choose an option:\n");
        printf("1 - Add record\n");
        printf("2 - Delete record\n");
        printf("3 - Search record\n");
        printf("4 - Print all records\n");
        printf("5 - Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            numRecords = addRecord(records, numRecords);
        } else if (choice == 2) {
            printf("Enter ID of record to delete: ");
            int id;
            scanf("%d", &id);
            numRecords = deleteRecord(records, numRecords, id);
        } else if (choice == 3) {
            printf("Enter ID of record to search: ");
            int id;
            scanf("%d", &id);
            searchRecord(records, numRecords, id);
        } else if (choice == 4) {
            printf("Printing all records:\n");
            for (int i = 0; i < numRecords; i++) {
                printRecord(records[i]);
                printf("\n");
            }
        } else if (choice == 5) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}