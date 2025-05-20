//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

// Structure representing the database table
typedef struct {
    int id;
    char name[20];
    int age;
    double salary;
} Employee;

int main() {
    // Create an array to hold the employee records
    Employee employees[10];
    // Create variables to hold user inputs
    int choice, id;
    char name[20];
    int age;
    double salary;

    // Initialize all employee records to zero
    memset(employees, 0, sizeof(employees));

    // Display the menu and prompt the user for input
    do {
        printf("\n\nEmployee Database Simulation\n");
        printf("1. Add employee record\n");
        printf("2. View employee record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Add employee record
        if (choice == 1) {
            // Prompt the user for employee details
            printf("\nEnter employee id: ");
            scanf("%d", &id);
            printf("Enter employee name: ");
            scanf("%s", name);
            printf("Enter employee age: ");
            scanf("%d", &age);
            printf("Enter employee salary: ");
            scanf("%lf", &salary);

            // Create a new employee record and add it to the database table
            Employee newEmployee = {id, name, age, salary};
            int i;
            for (i = 0; i < 10; i++) {
                if (employees[i].id == 0) {
                    employees[i] = newEmployee;
                    break;
                }
            }
            if (i == 10) {
                printf("\nDatabase is full, cannot add any more employees.");
            }
            else {
                printf("\nEmployee record added successfully.");
            }
        }
        // View employee record
        else if (choice == 2) {
            // Prompt the user for employee id
            printf("\nEnter employee id to search: ");
            scanf("%d", &id);

            // Search for the employee record with the given id
            int i;
            for (i = 0; i < 10; i++) {
                if (employees[i].id == id) {
                    printf("\nEmployee id: %d", employees[i].id);
                    printf("\nEmployee name: %s", employees[i].name);
                    printf("\nEmployee age: %d", employees[i].age);
                    printf("\nEmployee salary: %.2lf", employees[i].salary);
                    break;
                }
            }
            if (i == 10) {
                printf("\nEmployee with id %d not found.", id);
            }
        }
        // Exit the program
        else if (choice == 3) {
            printf("\nExiting program...");
            break;
        }
        // Invalid choice
        else {
            printf("\nInvalid choice, please try again.");
        }
    } while (1);

    return 0;
}