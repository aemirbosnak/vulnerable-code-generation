//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

// Function to add a new record
void add_record() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    Record new_record;
    new_record.id = record_count + 1; // Incremental ID
    printf("Enter name for record %d: ", new_record.id);
    scanf("%s", new_record.name);
    
    database[record_count] = new_record;
    record_count++;
    printf("Record added successfully.\n");
}

// Function to display all records
void display_records() {
    if (record_count == 0) {
        printf("No records in the database.\n");
        return;
    }

    printf("\nRecords in the Database:\n");
    printf("ID\tName\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%s\n", database[i].id, database[i].name);
    }
}

// Function to update a record
void update_record() {
    int id;
    printf("Enter ID of the record to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > record_count) {
        printf("Record with ID %d does not exist.\n", id);
        return;
    }

    printf("Enter new name for record %d: ", id);
    scanf("%s", database[id - 1].name);
    printf("Record updated successfully.\n");
}

// Function to delete a record
void delete_record() {
    int id;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > record_count) {
        printf("Record with ID %d does not exist.\n", id);
        return;
    }

    for (int i = id - 1; i < record_count - 1; i++) {
        database[i] = database[i + 1]; // Shift records
    }
    record_count--;
    printf("Record deleted successfully.\n");
}

// Display menu options
void display_menu() {
    printf("\nSimple C Database Simulation\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
}

// Main function
int main() {
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                update_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Exiting the database simulation.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}