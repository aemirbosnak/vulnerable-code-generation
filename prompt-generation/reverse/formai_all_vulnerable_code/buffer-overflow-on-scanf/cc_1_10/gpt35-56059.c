//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for storing database record
typedef struct Record {
    int id;
    char name[20];
    char email[50];
    int age;
} Record;

// function to add a new record
void addRecord(Record* db[], int* count) {
    // allocate memory for new record
    Record* newRecord = (Record*) malloc(sizeof(Record));
    
    // get data from user
    printf("Enter ID: ");
    scanf("%d", &newRecord->id);
    printf("Enter Name: ");
    scanf("%s", newRecord->name);
    printf("Enter Email: ");
    scanf("%s", newRecord->email);
    printf("Enter Age: ");
    scanf("%d", &newRecord->age);
    
    // add record to database
    db[*count] = newRecord;
    (*count)++;
    
    printf("Record added successfully!\n");
}

// function to display all records in database
void displayRecords(Record* db[], int count) {
    printf("ID\tName\t\tEmail\t\tAge\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t\t%d\n", db[i]->id, db[i]->name, db[i]->email, db[i]->age);
    }
    printf("-----------------------------------------------\n");
}

// function to search for a record by ID
void searchRecord(Record* db[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (db[i]->id == id) {
            printf("Record Found!\n");
            printf("ID\tName\t\tEmail\t\tAge\n");
            printf("-----------------------------------------------\n");
            printf("%d\t%s\t\t%s\t\t%d\n", db[i]->id, db[i]->name, db[i]->email, db[i]->age);
            printf("-----------------------------------------------\n");
            return;
        }
    }
    printf("Record Not Found!\n");
}

// function to delete a record by ID
void deleteRecord(Record* db[], int* count, int id) {
    for (int i = 0; i < *count; i++) {
        if (db[i]->id == id) {
            // free memory allocated for record
            free(db[i]);
            // shift all records to fill the gap
            for (int j = i; j < (*count - 1); j++) {
                db[j] = db[j+1];
            }
            (*count)--;
            printf("Record Deleted Successfully!\n");
            return;
        }
    }
    printf("Record Not Found!\n");
}

int main() {
    // initialize database
    Record* db[100];
    int count = 0;
    int choice, id;
    
    // display menu
    while (1) {
        printf("\n1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(db, &count);
                break;
            case 2:
                displayRecords(db, count);
                break;
            case 3:
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                searchRecord(db, count, id);
                break;
            case 4:
                printf("Enter ID to Delete: ");
                scanf("%d", &id);
                deleteRecord(db, &count, id);
                break;
            case 5:
                // free memory allocated for all records
                for (int i = 0; i < count; i++) {
                    free(db[i]);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}