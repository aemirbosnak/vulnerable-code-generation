//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records that can be stored in the database
#define MAX_RECORDS 100

// Declare a structure to hold the record information
struct Record {
    int id;
    char name[50];
    int age;
};

// Declare the database array to store the records
struct Record database[MAX_RECORDS];

// Declare the current count of records in the database
int count = 0;

int main() {
    // Variable to store the user's menu choice
    int choice = 0;
    
    // Loop until the user chooses to exit
    while (choice != 5) {
        // Display the main menu options to the user
        printf("\n--- Main Menu ---\n");
        printf("1. Add Record\n");
        printf("2. View All Records\n");
        printf("3. Search Records\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        
        // Prompt the user for their menu choice
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        
        // Switch based on the user's choice
        switch (choice) {
            case 1:
                // Add a new record to the database
                
                // Check if there is space in the database to add the record
                if (count < MAX_RECORDS) {
                    // Prompt the user for the record information
                    printf("\nEnter the record information:\n");
                    printf("ID: ");
                    scanf("%d", &database[count].id);
                    printf("Name: ");
                    scanf("%s", database[count].name);
                    printf("Age: ");
                    scanf("%d", &database[count].age);
                    
                    // Increment the count of records in the database
                    count++;
                    
                    // Print a success message
                    printf("\nRecord added successfully.\n");
                }
                else {
                    // Print an error message
                    printf("\nError: Maximum number of records reached.\n");
                }
                
                break;
                
            case 2:
                // View all records in the database
                
                // Check if there are any records to display
                if (count > 0) {
                    // Print the table header
                    printf("\nID\tName\t\tAge\n");
                    printf("--\t----\t\t---\n");
                    
                    // Loop through each record in the database and print its information
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
                    }
                }
                else {
                    // Print an error message
                    printf("\nError: No records found.\n");
                }
                
                break;
                
            case 3:
                // Search for a record in the database
                
                // Check if there are any records to search in
                if (count > 0) {
                    // Prompt the user for the search criteria
                    printf("\nEnter the search criteria:\n");
                    printf("ID: ");
                    int search_id;
                    scanf("%d", &search_id);
                    
                    // Loop through each record in the database and check if it matches the search criteria
                    int found = 0;
                    for (int i = 0; i < count; i++) {
                        if (database[i].id == search_id) {
                            // Print the matching record information
                            printf("\nID\tName\t\tAge\n");
                            printf("--\t----\t\t---\n");
                            printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
                            found = 1;
                            break;
                        }
                    }
                    
                    // Check if a matching record was not found
                    if (!found) {
                        // Print an error message
                        printf("\nError: Record not found.\n");
                    }
                }
                else {
                    // Print an error message
                    printf("\nError: No records found.\n");
                }
                
                break;
                
            case 4:
                // Delete a record from the database
                
                // Check if there are any records to delete
                if (count > 0) {
                    // Prompt the user for the ID of the record to delete
                    printf("\nEnter the ID of the record to delete: ");
                    int delete_id;
                    scanf("%d", &delete_id);
                    
                    // Loop through each record in the database and check if it matches the delete criteria
                    int found = 0;
                    for (int i = 0; i < count; i++) {
                        if (database[i].id == delete_id) {
                            // Move all the records after the deleted record up one index to fill in the gap
                            for (int j = i; j < count - 1; j++) {
                                database[j] = database[j + 1];
                            }
                            
                            // Decrement the count of records in the database
                            count--;
                            
                            // Print a success message
                            printf("\nRecord deleted successfully.\n");
                            found = 1;
                            break;
                        }
                    }
                    
                    // Check if a matching record was not found
                    if (!found) {
                        // Print an error message
                        printf("\nError: Record not found.\n");
                    }
                }
                else {
                    // Print an error message
                    printf("\nError: No records found.\n");
                }
                
                break;
                
            case 5:
                // Exit the program
                
                printf("\nGoodbye!\n");
                break;
                
            default:
                // Invalid choice
                
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    
    // Return success
    return 0;
}