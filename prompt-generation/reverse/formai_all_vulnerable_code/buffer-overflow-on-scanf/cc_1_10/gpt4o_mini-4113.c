//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define POSITION_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char position[POSITION_LENGTH];
    float salary;
} Employee;

Employee employeeDB[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: Cannot add more employees. Maximum limit reached.\n");
        return;
    }
    
    Employee newEmployee;
    newEmployee.id = employeeCount + 1; // Simple ID assignment
    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
    printf("Enter employee position: ");
    scanf("%s", newEmployee.position);
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);
    
    employeeDB[employeeCount] = newEmployee;
    employeeCount++;
    printf("Employee added successfully!\n");
}

void removeEmployee() {
    int id;
    printf("Enter employee ID to remove: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > employeeCount) {
        printf("Error: Invalid ID.\n");
        return;
    }

    for (int i = id - 1; i < employeeCount - 1; i++) {
        employeeDB[i] = employeeDB[i + 1];
    }
    employeeCount--;
    printf("Employee removed successfully!\n");
}

void viewEmployees() {
    if (employeeCount == 0) {
        printf("No employees in the database.\n");
        return;
    }

    printf("Employee List:\n");
    printf("ID\tName\t\tPosition\tSalary\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%s\t\t%s\t%.2f\n", employeeDB[i].id, employeeDB[i].name, employeeDB[i].position, employeeDB[i].salary);
    }
}

void searchEmployee() {
    char name[NAME_LENGTH];
    printf("Enter employee name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employeeDB[i].name, name) == 0) {
            printf("Employee Found:\n");
            printf("ID: %d\nName: %s\nPosition: %s\nSalary: %.2f\n", employeeDB[i].id, employeeDB[i].name, employeeDB[i].position, employeeDB[i].salary);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No employee found with the name %s.\n", name);
    }
}

void displayMenu() {
    printf("\nEmployee Database Management System\n");
    printf("1. Add Employee\n");
    printf("2. Remove Employee\n");
    printf("3. View Employees\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                removeEmployee();
                break;
            case 3:
                viewEmployees();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}