//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 // Maximum number of records in the database

// Record struct to represent each record in the database
typedef struct {
    int id;
    char name[20];
    int age;
    char address[50];
} Record;

int num_records = 0; // Current number of records in the database
Record database[MAX_RECORDS]; // Array to store the records

// Function to print the main menu and get user input
int show_menu() {
    int choice;
    printf("Enter an option:\n");
    printf("1. Add a new record\n");
    printf("2. View all records\n");
    printf("3. Search for a record\n");
    printf("4. Delete a record\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new record to the database
void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }
    Record new_record;
    printf("Enter the ID: ");
    scanf("%d", &new_record.id);
    printf("Enter the name: ");
    scanf("%s", new_record.name);
    printf("Enter the age: ");
    scanf("%d", &new_record.age);
    printf("Enter the address: ");
    scanf("%s", new_record.address);
    database[num_records] = new_record;
    num_records++;
}

// Function to print a single record
void print_record(Record record) {
    printf("%d %s %d %s\n", record.id, record.name, record.age, record.address);
}

// Function to view all records in the database
void view_records() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 0; i < num_records; i++) {
        print_record(database[i]);
    }
}

// Function to search for a record by ID and print it
void search_record() {
    int id;
    printf("Enter the ID to search for: ");
    scanf("%d", &id);
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            print_record(database[i]);
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to delete a record by ID
void delete_record() {
    int id;
    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            for (int j = i; j < (num_records - 1); j++) {
                database[j] = database[j+1];
            }
            num_records--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    printf("Welcome to the C Database Simulator\n");
    int choice = 0;
    while (choice != 5) {
        choice = show_menu();
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}