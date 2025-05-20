//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
} Employee;

Employee* head = NULL;

// Function to create a new Employee node
Employee* createEmployee(int id, const char* name, float salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->id = id;
    strncpy(newEmployee->name, name, sizeof(newEmployee->name) - 1);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to add employee
void addEmployee(int id, const char* name, float salary) {
    Employee* newEmployee = createEmployee(id, name, salary);
    newEmployee->next = head;
    head = newEmployee;
    printf("Employee %s added successfully.\n", name);
}

// Function to display all employees
void displayEmployees() {
    if (head == NULL) {
        printf("No employees in the database.\n");
        return;
    }
    
    Employee* current = head;
    printf("Employee List:\n");
    printf("%-5s %-30s %-10s\n", "ID", "Name", "Salary");
    while (current != NULL) {
        printf("%-5d %-30s %-10.2f\n", current->id, current->name, current->salary);
        current = current->next;
    }
}

// Function to delete an employee by ID
void deleteEmployee(int id) {
    Employee* current = head;
    Employee* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the first employee
    } else {
        previous->next = current->next; // Bypass the current employee
    }

    free(current);
    printf("Employee with ID %d deleted successfully.\n", id);
}

// Function to clean up the memory on exit
void cleanUp() {
    Employee* current = head;
    while (current != NULL) {
        Employee* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Main function
int main() {
    int choice, id;
    char name[50];
    float salary;

    while (1) {
        printf("\n*** Employee Database Simulation ***\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf(" %[^\n]", name); // read string with spaces
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                addEmployee(id, name, salary);
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(id);
                break;
            case 4:
                cleanUp();
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again!\n");
        }
    }

    return 0;
}