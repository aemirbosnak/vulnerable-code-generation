//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field in a record
#define MAX_FIELD_LENGTH 50

// Define the number of fields in a record
#define NUM_FIELDS 3

// Define the data types of the fields in a record
typedef char string[MAX_FIELD_LENGTH];
typedef int integer;
typedef float real;

// Define the structure of a record
typedef struct {
    string name;
    integer age;
    real height;
} record;

// Define the database as an array of records
record database[MAX_RECORDS];

// Define the current number of records in the database
int num_records = 0;

// Define the menu options
enum menu_options {
    ADD_RECORD,
    DELETE_RECORD,
    EDIT_RECORD,
    PRINT_DATABASE,
    QUIT
};

// Function to add a record to the database
void add_record() {
    // Get the record data from the user
    printf("Enter the name: ");
    scanf("%s", database[num_records].name);
    printf("Enter the age: ");
    scanf("%d", &database[num_records].age);
    printf("Enter the height: ");
    scanf("%f", &database[num_records].height);

    // Increment the number of records in the database
    num_records++;
}

// Function to delete a record from the database
void delete_record() {
    // Get the record number from the user
    int record_number;
    printf("Enter the record number: ");
    scanf("%d", &record_number);

    // Check if the record number is valid
    if (record_number < 1 || record_number > num_records) {
        printf("Invalid record number\n");
        return;
    }

    // Shift the records after the deleted record down one position
    for (int i = record_number; i < num_records; i++) {
        database[i] = database[i + 1];
    }

    // Decrement the number of records in the database
    num_records--;
}

// Function to edit a record in the database
void edit_record() {
    // Get the record number from the user
    int record_number;
    printf("Enter the record number: ");
    scanf("%d", &record_number);

    // Check if the record number is valid
    if (record_number < 1 || record_number > num_records) {
        printf("Invalid record number\n");
        return;
    }

    // Get the new record data from the user
    printf("Enter the new name: ");
    scanf("%s", database[record_number - 1].name);
    printf("Enter the new age: ");
    scanf("%d", &database[record_number - 1].age);
    printf("Enter the new height: ");
    scanf("%f", &database[record_number - 1].height);
}

// Function to print the database
void print_database() {
    // Print the header
    printf("Name\tAge\tHeight\n");

    // Print the records
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].height);
    }
}

// Function to quit the program
void quit() {
    // Exit the program
    exit(0);
}

// Main function
int main() {
    // Display the menu options
    printf("1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Edit record\n");
    printf("4. Print database\n");
    printf("5. Quit\n");

    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
        case ADD_RECORD:
            add_record();
            break;
        case DELETE_RECORD:
            delete_record();
            break;
        case EDIT_RECORD:
            edit_record();
            break;
        case PRINT_DATABASE:
            print_database();
            break;
        case QUIT:
            quit();
            break;
        default:
            printf("Invalid choice\n");
    }

    // Return to the menu
    main();

    return 0;
}