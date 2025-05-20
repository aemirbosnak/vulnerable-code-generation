//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the details of an employee
struct Employee {
    int emp_id;
    char emp_name[50];
    char emp_dept[50];
    float emp_salary;
};

// Function to print the details of an employee from the database
void printEmployee(struct Employee emp) {
    printf("Employee ID: %d\n", emp.emp_id);
    printf("Employee Name: %s\n", emp.emp_name);
    printf("Employee Department: %s\n", emp.emp_dept);
    printf("Employee Salary: %.2f\n", emp.emp_salary);
}

// Main function
int main() {
    // Initializing the database with 3 employee details
    struct Employee emp_db[3] = {
        {101, "John Doe", "Marketing", 5000.50},
        {102, "Jane Smith", "Sales", 7000.75},
        {103, "David Clark", "IT", 8000.00}
    };

    printf("------------------- Employee Database Simulation -------------------\n\n");

    // Loop for showing the menu of operations for the user
    while (1) {
        printf("Enter your choice:\n");
        printf("1 => View all employees\n");
        printf("2 => Add a new employee\n");
        printf("3 => Search an employee by ID\n");
        printf("4 => Exit\n");

        int choice;
        scanf("%d", &choice);

        // Switch case for performing the chosen operation
        switch (choice) {
            case 1: 
                // Printing all the employees' details from the database
                printf("\n--- Employee Details ---\n");
                for (int i = 0; i < 3; i++) {
                    printEmployee(emp_db[i]);
                }
                printf("\n");
                break;

            case 2:
                // Getting new employee details from the user
                printf("\nEnter the details of the new employee:\n");
                struct Employee new_emp;
                printf("Employee ID: ");
                scanf("%d", &new_emp.emp_id);
                printf("Employee Name: ");
                scanf("%s", new_emp.emp_name);
                printf("Employee Department: ");
                scanf("%s", new_emp.emp_dept);
                printf("Employee Salary: ");
                scanf("%f", &new_emp.emp_salary);

                // Adding the new employee to the database
                emp_db[3] = new_emp;
                printf("\nNew Employee Added Successfully!\n\n");
                break;

            case 3:
                // Searching an employee by ID from the database
                printf("\nEnter the ID of the employee to search: ");
                int search_id;
                scanf("%d", &search_id);
                int found = 0;
                for (int i = 0; i < 3; i++) {
                    if (emp_db[i].emp_id == search_id) {
                        printEmployee(emp_db[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nEmployee with ID #%d not found!\n\n", search_id);
                }
                break;

            case 4:
                // Exiting the program
                printf("\nThank you for using Employee Database Simulation!\n");
                exit(0);

            default:
                // Handling invalid input by the user
                printf("\nInvalid choice! Please enter a valid choice.\n\n");
                break;
        }
    }

    return 0;
}