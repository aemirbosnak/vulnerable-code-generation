//FormAI DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records
#define RECORD_SIZE 32 // Size of each record

// Structure for a single record
typedef struct {
    char name[16];
    int id;
    float salary;
} Record;

// Database variable for storing records
Record database[MAX_RECORDS];

// Function for adding a new record
void add_record() {
    int index = -1;
    
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Database is full\n");
        return;
    }
    
    Record new_record;
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter id: ");
    scanf("%d", &new_record.id);
    printf("Enter salary: ");
    scanf("%f", &new_record.salary);
    
    database[index] = new_record;
    printf("Record added successfully\n");
}

// Function for deleting a record
void delete_record() {
    int id, index = -1;
    
    printf("Enter id of the record to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Record not found\n");
        return;
    }
    
    database[index].id = 0;
    printf("Record deleted successfully\n");
}

// Function for displaying all records
void display_records() {
    printf("Name\t\tID\t\tSalary\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id != 0) {
            printf("%s\t\t%d\t\t%.2f\n", database[i].name, database[i].id, database[i].salary);
        }
    }
}

int main() {
    int choice;
    memset(database, 0, MAX_RECORDS * sizeof(Record)); // Initialize database
    
    printf("Welcome to the Cyberpunk Database Simulator\n\n");
    
    do {
        printf("Choose an option:\n");
        printf("1. Add a new record\n");
        printf("2. Delete a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}