//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50
#define FILENAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

Record records[MAX_RECORDS];
int recordCount = 0;

void loadRecords() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %s", &records[recordCount].id, 
                      records[recordCount].name, 
                      records[recordCount].email) == 3) {
            recordCount++;
        }
        fclose(file);
    }
}

void saveRecords() {
    FILE *file = fopen(FILENAME, "w");
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s %s\n", records[i].id, records[i].name, records[i].email);
    }
    fclose(file);
}

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full! Can't add more records.\n");
        return;
    }
    
    Record newRecord;
    newRecord.id = recordCount + 1; // Auto-incrementing ID
    
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    
    printf("Enter email: ");
    scanf("%s", newRecord.email);
    
    records[recordCount] = newRecord;
    recordCount++;
    printf("Record added! ID: %d\n", newRecord.id);
    saveRecords();
}

void searchRecord() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (strcasecmp(records[i].name, searchName) == 0) {
            printf("Found Record - ID: %d, Name: %s, Email: %s\n", 
                    records[i].id, records[i].name, records[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record with name '%s' not found.\n", searchName);
    }
}

void displayRecords() {
    if (recordCount == 0) {
        printf("No records to display!\n");
        return;
    }
    
    printf("Displaying all records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", 
                records[i].id, records[i].name, records[i].email);
    }
}

int main() {
    loadRecords();
    int choice;
    
    while (1) {
        printf("\n===== Simple Database Indexing System =====\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("=============================================\n");
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
                displayRecords();
                break;
            case 4:
                printf("Exiting the program! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}