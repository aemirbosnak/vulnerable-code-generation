//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold database records
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

int main() {
    // Define a dynamic array to hold database records
    Record *database = malloc(sizeof(Record) * 10);
    int numRecords = 0;

    printf("Welcome to the Happy Database Simulation Program!\n\n");

    while (1) {
        // Display options menu
        printf("Please select an option:\n");
        printf("1. Add a record\n");
        printf("2. View all records\n");
        printf("3. Edit a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit program\n");
        printf("Option: ");

        // Get user input
        char input[10];
        fgets(input, 10, stdin);

        // Process user input
        switch (atoi(input)) {
            case 1:
                // Add a record
                printf("\nAdding a record...\n");

                // Get ID
                printf("Enter ID: ");
                fgets(input, 10, stdin);
                database[numRecords].id = atoi(input);

                // Get Name
                printf("Enter Name: ");
                fgets(database[numRecords].name, 50, stdin);
                database[numRecords].name[strcspn(database[numRecords].name, "\n")] = '\0';

                // Get Age
                printf("Enter Age: ");
                fgets(input, 10, stdin);
                database[numRecords].age = atoi(input);

                printf("\nRecord added successfully!\n\n");
                numRecords++;
                break;
            case 2:
                // View all records
                printf("\nViewing all records...\n");
                if (numRecords == 0) {
                    printf("No records found.\n\n");
                } else {
                    for (int i = 0; i < numRecords; i++) {
                        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
                    }
                    printf("\n");
                }
                break;
            case 3:
                // Edit a record
                printf("\nEditing a record...\n");
                if (numRecords == 0) {
                    printf("No records found.\n\n");
                } else {
                    // Get ID of record to edit
                    printf("Enter ID of record to edit: ");
                    fgets(input, 10, stdin);
                    int idToEdit = atoi(input);
                    int found = 0;
                    for (int i = 0; i < numRecords; i++) {
                        if (database[i].id == idToEdit) {
                            // Found the record to edit
                            found = 1;

                            // Display current values
                            printf("Current Values:\n");
                            printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);

                            // Get new values
                            printf("Enter new Name (Leave blank to keep existing value): ");
                            fgets(input, 50, stdin);
                            if (strlen(input) > 1) {
                                input[strcspn(input, "\n")] = '\0';
                                strcpy(database[i].name, input);
                            }

                            printf("Enter new Age (Leave blank to keep existing value): ");
                            fgets(input, 10, stdin);
                            if (strlen(input) > 1) {
                                database[i].age = atoi(input);
                            }

                            printf("\nRecord edited successfully!\n\n");
                            break;
                        }
                    }
                    if (!found) {
                        printf("Record not found.\n\n");
                    }
                }
                break;
            case 4:
                // Delete a record
                printf("\nDeleting a record...\n");
                if (numRecords == 0) {
                    printf("No records found.\n\n");
                } else {
                    // Get ID of record to delete
                    printf("Enter ID of record to delete: ");
                    fgets(input, 10, stdin);
                    int idToDelete = atoi(input);
                    int found = 0;
                    for (int i = 0; i < numRecords; i++) {
                        if (database[i].id == idToDelete) {
                            // Found the record to delete
                            found = 1;

                            // Shift remaining records down by one
                            for (int j = i; j < numRecords-1; j++) {
                                database[j] = database[j+1];
                            }

                            printf("\nRecord deleted successfully!\n\n");
                            numRecords--;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Record not found.\n\n");
                    }
                }
                break;
            case 5:
                // Exit program
                printf("\nThank you for using our Happy Database Simulation Program!\n\n");
                free(database);
                return 0;
            default:
                // Invalid option
                printf("\nInvalid option. Please try again.\n\n");
        }
    }
}