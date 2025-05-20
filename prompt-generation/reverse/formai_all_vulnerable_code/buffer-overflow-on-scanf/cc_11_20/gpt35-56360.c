//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold records in the database
struct record {
    int id;
    char name[50];
    int age;
};

// Define the main function
int main() {

    // Set up the database
    int MAX_RECORDS = 100;
    struct record database[MAX_RECORDS];
    int num_records = 0;

    // Print welcome message
    printf("Welcome to the C Database Simulation Program!\n\n");

    // Loop until the user wants to quit
    int input = 0;
    while (input != 5) {

        // Print menu options
        printf("Please choose an option:\n");
        printf("1. Add a record\n");
        printf("2. Edit a record\n");
        printf("3. Print all records\n");
        printf("4. Search for a record\n");
        printf("5. Quit\n");

        // Get user input
        printf("Input: ");
        scanf("%d", &input);

        // Handle user input
        switch (input) {

            case 1:
                // Add a record
                if (num_records >= MAX_RECORDS) {
                    printf("Error: database is full\n");
                } else {
                    struct record new_record;
                    printf("Enter record id: ");
                    scanf("%d", &new_record.id);
                    printf("Enter record name: ");
                    scanf("%s", new_record.name);
                    printf("Enter record age: ");
                    scanf("%d", &new_record.age);
                    database[num_records] = new_record;
                    num_records++;
                    printf("Record added!\n");
                }
                break;

            case 2:
                // Edit a record
                printf("Enter record id to edit: ");
                int edit_id;
                scanf("%d", &edit_id);
                int found = 0;
                for (int i=0; i<num_records; i++) {
                    if (database[i].id == edit_id) {
                        printf("Enter new name: ");
                        scanf("%s", database[i].name);
                        printf("Enter new age: ");
                        scanf("%d", &database[i].age);
                        found = 1;
                        printf("Record updated!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Record not found\n");
                }
                break;

            case 3:
                // Print all records
                printf("Id\tName\t\tAge\n");
                for (int i=0; i<num_records; i++) {
                    printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
                }
                break;

            case 4:
                // Search for a record
                printf("Enter record id to search: ");
                int search_id;
                scanf("%d", &search_id);
                found = 0;
                for (int i=0; i<num_records; i++) {
                    if (database[i].id == search_id) {
                        printf("Id\tName\t\tAge\n");
                        printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Record not found\n");
                }
                break;

            case 5:
                // Quit
                printf("Goodbye!\n");
                break;

            default:
                // Invalid input
                printf("Invalid input\n");
                break;
        }
    }

    // Exit the program
    return 0;
}