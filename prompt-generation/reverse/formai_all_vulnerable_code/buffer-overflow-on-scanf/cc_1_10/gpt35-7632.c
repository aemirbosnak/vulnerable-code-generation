//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee struct
typedef struct {
    int employee_id;
    char name[50];
    int age;
    char department[50];
} Employee;

// Declare the global employees array
Employee employees[MAX_EMPLOYEES];

// Define the function prototypes
void print_menu();
void add_employee();
void remove_employee();
void list_employees();

int main() {
    int choice;

    do {
        // Print the menu
        print_menu();

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                remove_employee();
                break;
            case 3:
                list_employees();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void print_menu() {
    printf("\n");
    printf("Employee Database Simulation\n");
    printf("-----------------------------\n");
    printf("1. Add an employee\n");
    printf("2. Remove an employee\n");
    printf("3. List all employees\n");
    printf("4. Exit\n");
}

void add_employee() {
    int id, age;
    char name[50], department[50];

    // Get the employee information from the user
    printf("Enter the employee's ID: ");
    scanf("%d", &id);

    printf("Enter the employee's name: ");
    scanf("%s", name);

    printf("Enter the employee's age: ");
    scanf("%d", &age);

    printf("Enter the employee's department: ");
    scanf("%s", department);

    // Create the new employee
    Employee new_employee;
    new_employee.employee_id = id;
    strcpy(new_employee.name, name);
    new_employee.age = age;
    strcpy(new_employee.department, department);

    // Add the new employee to the employees array
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (employees[i].employee_id == 0) {
            employees[i] = new_employee;
            printf("Employee added successfully.\n");
            return;
        }
    }

    printf("The database is full. Unable to add employee.\n");
}

void remove_employee() {
    int id;

    // Get the ID of the employee to remove
    printf("Enter the ID of the employee to remove: ");
    scanf("%d", &id);

    // Find the employee in the array and remove them
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (employees[i].employee_id == id) {
            employees[i].employee_id = 0;
            strcpy(employees[i].name, "");
            employees[i].age = 0;
            strcpy(employees[i].department, "");
            printf("Employee removed successfully.\n");
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
}

void list_employees() {
    printf("Employees:\n");

    // Print each employee in the array
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (employees[i].employee_id != 0) {
            printf("ID: %d, Name: %s, Age: %d, Department: %s\n",
                employees[i].employee_id, employees[i].name,
                employees[i].age, employees[i].department);
        }
    }
}