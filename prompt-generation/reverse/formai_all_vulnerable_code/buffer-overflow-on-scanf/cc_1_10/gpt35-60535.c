//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define the structure for our database record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define an array of records to hold our database entries
Record database[MAX_RECORDS];

// Keep track of the number of records in the database
int num_records = 0;

// Function to add a new record to the database
void add_record(int id, char* name, int age) {
    if(num_records >= MAX_RECORDS) {
        printf("Database is full. Cannot add record.\n");
        return;
    }
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.age = age;
    database[num_records++] = new_record;
    printf("Record added successfully.\n");
}

// Function to search for a record in the database by ID
int find_record(int id) {
    for(int i=0; i<num_records; i++) {
        if(database[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to update a record in the database by ID
void update_record(int id, char* name, int age) {
    int index = find_record(id);
    if(index == -1) {
        printf("Record not found.\n");
        return;
    }
    strcpy(database[index].name, name);
    database[index].age = age;
    printf("Record updated successfully.\n");
}

// Function to delete a record from the database by ID
void delete_record(int id) {
    int index = find_record(id);
    if(index == -1) {
        printf("Record not found.\n");
        return;
    }
    for(int i=index; i<num_records-1; i++) {
        database[i] = database[i+1];
    }
    num_records--;
    printf("Record deleted successfully.\n");
}

// Function to display all records in the database
void display_records() {
    if(num_records == 0) {
        printf("Database is empty.\n");
        return;
    }
    printf("ID\tName\tAge\n");
    printf("--------------------------------------------------------------\n");
    for(int i=0; i<num_records; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Main program loop
int main() {
    int choice, id, age;
    char name[50];
    while(1) {
        printf("\nDatabase Simulation Program\n");
        printf("1. Add Record\n");
        printf("2. Update Record\n");
        printf("3. Delete Record\n");
        printf("4. Display Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Add Record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                add_record(id, name, age);
                break;
            case 2: // Update Record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                update_record(id, name, age);
                break;
            case 3: // Delete Record
                printf("Enter ID: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 4: // Display Records
                display_records();
                break;
            case 5: // Exit
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}