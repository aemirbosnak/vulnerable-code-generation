//FormAI DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the database

typedef struct {
    int id;
    char name[20];
    char email[30];
    int age;
} Record; // Define a struct for the database records

// Function prototypes
void display_menu();
int add_record(Record arr[], int size);
void display_records(Record arr[], int size);
void search_record(Record arr[], int size);
int delete_record(Record arr[], int size);

int main() {
    Record db[MAX_SIZE]; // Initialize the database
    int size = 0; // Initialize the size of the database
    int option;

    do {
        display_menu();
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                size = add_record(db, size);
                break;
            case 2:
                display_records(db, size);
                break;
            case 3:
                search_record(db, size);
                break;
            case 4:
                size = delete_record(db, size);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

// Display the menu options
void display_menu() {
    printf("------------------------------\n");
    printf("DATABASE SIMULATION PROGRAM\n");
    printf("------------------------------\n\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit Program\n\n");
}

// Add a record to the database
int add_record(Record arr[], int size) {
    if (size == MAX_SIZE) {
        printf("Database is full, cannot add record.\n");
        return size;
    }

    Record new_record;

    printf("Enter the ID: ");
    scanf("%d", &new_record.id);

    // Check for duplicate IDs
    for (int i = 0; i < size; i++) {
        if (arr[i].id == new_record.id) {
            printf("ID already exists, please try again.\n");
            return size;
        }
    }

    printf("Enter the Name: ");
    scanf("%s", new_record.name);

    printf("Enter the Email: ");
    scanf("%s", new_record.email);

    printf("Enter the Age: ");
    scanf("%d", &new_record.age);

    arr[size] = new_record;
    printf("Record added successfully!\n");

    return size + 1;
}

// Display all records in the database
void display_records(Record arr[], int size) {
    if (size == 0) {
        printf("Database is empty, no records to display.\n");
        return;
    }

    printf("------------------------------\n");
    printf("DATABASE RECORDS\n");
    printf("------------------------------\n\n");
    printf("ID\tNAME\tEMAIL\t\tAGE\n\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%s\t%d\n", arr[i].id, arr[i].name, arr[i].email, arr[i].age);
    }
}

// Search for a record by ID
void search_record(Record arr[], int size) {
    if (size == 0) {
        printf("Database is empty, cannot search for record.\n");
        return;
    }

    int id;
    printf("Enter the ID: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (arr[i].id == id) {
            printf("------------------------------\n");
            printf("RECORD FOUND\n");
            printf("------------------------------\n\n");
            printf("ID\tNAME\tEMAIL\t\tAGE\n\n");
            printf("%d\t%s\t%s\t%d\n", arr[i].id, arr[i].name, arr[i].email, arr[i].age);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

// Delete a record by ID
int delete_record(Record arr[], int size) {
    if (size == 0) {
        printf("Database is empty, cannot delete record.\n");
        return size;
    }

    int id;
    printf("Enter the ID: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (arr[i].id == id) {
            // Shift all records after the deleted record over by one
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j+1];
            }

            printf("Record with ID %d deleted successfully!\n", id);
            return size - 1;
        }
    }

    printf("Record with ID %d not found.\n", id);
    return size;
}