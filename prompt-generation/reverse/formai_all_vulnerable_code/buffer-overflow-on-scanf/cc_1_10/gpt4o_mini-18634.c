//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ID_LENGTH 10

typedef struct {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
} Record;

Record database[MAX_RECORDS];
int recordCount = 0;

void addRecord();
void viewRecords();
void deleteRecord();
void menu();

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        menu();
        return;
    }
    
    Record newRecord;
    printf("Enter ID: ");
    scanf("%s", newRecord.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newRecord.name);
    
    database[recordCount++] = newRecord;
    printf("Record added successfully!\n");
    menu();
}

void viewRecords() {
    if (recordCount == 0) {
        printf("No records found.\n");
    } else {
        printf("\nRecords:\n");
        for (int i = 0; i < recordCount; i++) {
            printf("ID: %s, Name: %s\n", database[i].id, database[i].name);
        }
    }
    menu();
}

void deleteRecord() {
    char idToDelete[ID_LENGTH];
    printf("Enter ID of record to delete: ");
    scanf("%s", idToDelete);
    
    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(database[i].id, idToDelete) == 0) {
            found = 1;
            for (int j = i; j < recordCount - 1; j++) {
                database[j] = database[j + 1];  // Shift records left
            }
            recordCount--;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("No record found with ID: %s\n", idToDelete);
    }
    menu();
}

void menu() {
    printf("\nDatabase Menu:\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Delete Record\n");
    printf("4. Exit\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            printf("Exiting the database program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            menu();  // Recursive call
    }
}

int main() {
    printf("Welcome to the Simple Database Simulation!\n");
    menu();  // Start the menu
    return 0;
}