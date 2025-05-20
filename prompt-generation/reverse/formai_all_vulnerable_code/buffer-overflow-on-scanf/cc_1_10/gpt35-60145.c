//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

// Define a struct to hold information about each record
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

// Define an array to hold all records
Record records[MAX_RECORDS];
int num_records = 0;

// Function to add a new record to the database
void add_record() {
    // Make sure there is room for a new record
    if (num_records < MAX_RECORDS) {
        // Prompt the user for record information
        Record new_record;
        printf("Enter ID: ");
        scanf("%d", &new_record.id);
        printf("Enter name: ");
        scanf("%s", new_record.name);
        printf("Enter age: ");
        scanf("%d", &new_record.age);

        // Add the new record to the database
        records[num_records] = new_record;
        num_records++;
        printf("Record added.\n");
    } else {
        printf("Error: database is full.\n");
    }
}

// Function to print information about a specific record
void print_record(int id) {
    // Find the record with the given ID
    Record *found_record = NULL;
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            found_record = &records[i];
            break;
        }
    }

    // Print the record information or an error message if the record was not found
    if (found_record) {
        printf("Record ID: %d\n", found_record->id);
        printf("Name: %s\n", found_record->name);
        printf("Age: %d\n", found_record->age);
    } else {
        printf("Error: record not found.\n");
    }
}

// Function to print all records in the database
void print_all_records() {
    // Print header row
    printf("ID\tName\t\tAge\n");

    // Loop through all records and print each one
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t\t%d\n", records[i].id, records[i].name, records[i].age);
    }
}

int main() {
    char command[10];

    // Loop to read user commands
    while (1) {
        // Prompt the user for a command
        printf("Enter a command (add, print, print_all, exit): ");
        scanf("%s", command);

        // Execute the appropriate command function or exit the program
        if (strcmp(command, "add") == 0) {
            add_record();
        } else if (strcmp(command, "print") == 0) {
            int id;
            printf("Enter record ID: ");
            scanf("%d", &id);
            print_record(id);
        } else if (strcmp(command, "print_all") == 0) {
            print_all_records();
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: invalid command.\n");
        }
    }

    return 0;
}