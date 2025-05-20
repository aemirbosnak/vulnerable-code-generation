//FormAI DATASET v1.0 Category: Database querying ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for our database model
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int main() {
    int choice = 0;
    int numEmployees = 0;

    printf("Welcome to the Employee Database\n\n");

    printf("How many employees do you want to enter? ");
    scanf("%d", &numEmployees);

    // Allocate space for our employee database
    Employee *employees = (Employee*) malloc(numEmployees * sizeof(Employee));

    // Loop to get employee details
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for employee %d:\n", i+1);

        employees[i].id = i+1;

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Age: ");
        scanf("%d", &employees[i].age);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);

        printf("Employee details added successfully!\n");
    }

    printf("\n\n---DATABASE QUERIES---\n\n");

    do {
        // Display menu to the user
        printf("1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch(choice) {
            case 1: {
                int searchID;
                printf("\nEnter ID to search: ");
                scanf("%d", &searchID);

                // Search for the employee
                for (int i = 0; i < numEmployees; i++) {
                    if (employees[i].id == searchID) {
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", employees[i].id);
                        printf("Name: %s\n", employees[i].name);
                        printf("Age: %d\n", employees[i].age);
                        printf("Salary: %.2f\n\n", employees[i].salary);
                        break;
                    }
                }
                break;
            }
            case 2: {
                char searchName[50];
                printf("\nEnter Name to search: ");
                scanf("%s", searchName);

                int resultsFound = 0;
                // Search for the employee
                for (int i = 0; i < numEmployees; i++) {
                    if (strcmp(employees[i].name, searchName) == 0) {
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", employees[i].id);
                        printf("Name: %s\n", employees[i].name);
                        printf("Age: %d\n", employees[i].age);
                        printf("Salary: %.2f\n\n", employees[i].salary);
                        resultsFound++;
                    }
                }
                if (resultsFound == 0) {
                    printf("\nNo employees found with name %s\n\n", searchName);
                }
                break;
            }
            case 3: {
                if (numEmployees == 0) {
                    printf("\nNo employees in the database.\n\n");
                    break;
                }
                printf("\n\n---ALL EMPLOYEES---\n\n");
                for (int i = 0; i < numEmployees; i++) {
                    printf("ID: %d\n", employees[i].id);
                    printf("Name: %s\n", employees[i].name);
                    printf("Age: %d\n", employees[i].age);
                    printf("Salary: %.2f\n\n", employees[i].salary);
                }
                break;
            }
            case 4: {
                printf("\nQuitting the program. Goodbye.\n\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n\n");
                break;
            }
        }
    } while(choice != 4);

    // Free up allocated memory
    free(employees);

    return 0;
}