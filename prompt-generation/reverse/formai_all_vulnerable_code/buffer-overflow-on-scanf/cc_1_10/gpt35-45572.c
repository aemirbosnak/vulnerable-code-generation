//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max size of the database
#define MAX_SIZE 1000

// Define the structure of the database record
typedef struct {
    int id;
    char name[20];
    char email[50];
} Record;

// Define the database array and counters
Record database[MAX_SIZE];
int num_records = 0;

// Function to add a new record to the database
void add_record() {
    // Check if the database is full
    if (num_records >= MAX_SIZE) {
        printf("Error: database is full\n");
        return;
    }

    // Get new record details from user
    int id;
    char name[20];
    char email[50];
    printf("Enter id: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);

    // Add the new record to the database
    database[num_records].id = id;
    strcpy(database[num_records].name, name);
    strcpy(database[num_records].email, email);
    num_records++;

    // Show success message
    printf("Record added successfully\n");
}

// Function to display all records in the database
void display_records() {
    // Check if there are any records in the database
    if (num_records == 0) {
        printf("Database is empty\n");
        return;
    }

    // Display header row
    printf("%-10s%-20s%-50s\n", "ID", "Name", "Email");

    // Display each record in the database
    int i;
    for (i = 0; i < num_records; i++) {
        printf("%-10d%-20s%-50s\n", database[i].id, database[i].name, database[i].email);
    }
}

// Function to search for a record by name
void search_by_name() {
    // Get name to search for from user
    char name[20];
    printf("Enter name to search for: ");
    scanf("%s", name);

    // Search for the record in the database
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // Display the matching record
            printf("%-10s%-20s%-50s\n", "ID", "Name", "Email");
            printf("%-10d%-20s%-50s\n", database[i].id, database[i].name, database[i].email);
            return;
        }
    }

    // Show message if record is not found
    printf("No record found with name %s\n", name);
}

// Main function to run the program
int main() {
    // Display welcome message
    printf("Welcome to the database simulation program!\n");

    // Loop to display menu and handle user input
    while (1) {
        // Display menu options
        printf("\nPlease select an option:\n");
        printf("1. Add record\n");
        printf("2. Display all records\n");
        printf("3. Search by name\n");
        printf("4. Exit\n");

        // Get user input
        int option;
        printf("Your selection: ");
        scanf("%d", &option);

        // Handle user input
        switch (option) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                // Show exit message and terminate program
                printf("Thank you for using the database simulation program!\n");
                return 0;
            default:
                // Show error message for invalid input
                printf("Error: invalid option\n");
                break;
        }
    }
}