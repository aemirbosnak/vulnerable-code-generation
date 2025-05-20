//FormAI DATASET v1.0 Category: Database simulation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 50
#define MAX_RECORDS 100

// Define the structure for a Record
struct Record {
    int id;
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
};

typedef struct Record Record;

// Define the database as an array of records
Record database[MAX_RECORDS];

// Define the current number of records in the database
int num_records = 0;

// Function to add a new record to the database
void add_record() {
    Record new_record;
    printf("Enter id: ");
    scanf("%d", &(new_record.id));
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter email: ");
    scanf("%s", new_record.email);
    database[num_records] = new_record;
    num_records++;
}

// Function to print all records in the database
void print_all_records() {
    if (num_records == 0) {
        printf("Database is empty\n");
        return;
    }
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
}

// Function to search for a record by ID
void search_record() {
    int search_id;
    printf("Enter ID to search for: ");
    scanf("%d", &search_id);
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == search_id) {
            printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
            return;
        }
    }
    printf("Record with ID %d not found\n", search_id);
}

int main() {
    int choice;
    while(1) {
        printf("Select an option: \n");
        printf("1. Add a record\n");
        printf("2. Print all records\n");
        printf("3. Search for a record\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a record
                add_record();
                break;
            case 2: // Print all records
                print_all_records();
                break;
            case 3: // Search for a record
                search_record();
                break;
            case 4: // Exit
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}