//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LENGTH 30
#define MAX_ADDRESS_LENGTH 100

// Struct to represent a record in the database
typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
} Record;

// Function to print out the records in the database
void print_database(Record *database, int size) {
    for (int i = 0; i < size; i++) {
        printf("Record %d:\n", i+1);
        printf("\tName: %s\n", database[i].name);
        printf("\tAddress: %s\n", database[i].address);
        printf("\tAge: %d\n", database[i].age);
    }
}

int main() {
    // Allocate memory for the database
    Record *database = malloc(sizeof(Record) * MAX_RECORDS);
    int database_size = 0;

    // Start the menu loop
    while (1) {
        printf("Please choose an option:\n");
        printf("\t1. Add a record.\n");
        printf("\t2. Print the database.\n");
        printf("\t3. Quit.\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: ; // Add a record
                Record new_record;

                printf("Enter the name:\n");
                scanf("%s", &new_record.name);

                printf("Enter the address:\n");
                scanf("%s", &new_record.address);

                printf("Enter the age:\n");
                scanf("%d", &new_record.age);

                database[database_size] = new_record;
                database_size++;

                printf("Record added successfully.\n");
                break;

            case 2: ; // Print the database
                printf("Printing database:\n");
                print_database(database, database_size);
                break;

            case 3: // Quit
                printf("Goodbye!\n");
                free(database);
                return 0;

            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }

        // Clear the input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}