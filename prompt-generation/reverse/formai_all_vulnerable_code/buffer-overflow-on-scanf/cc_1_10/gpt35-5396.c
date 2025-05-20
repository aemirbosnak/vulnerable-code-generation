//FormAI DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[50];
    double salary;
};

void addEmployee(struct Employee employees[], int *employeeCount) {
    if (*employeeCount == MAX_EMPLOYEES) {
        printf("Cannot add more employees\n");
        return;
    }
    printf("\nAdding Employee Details:\n");
    struct Employee employee;
    printf("Employee ID: ");
    scanf("%d", &employee.id);
    printf("Employee Name: ");
    scanf("%s", employee.name);
    printf("Employee Department: ");
    scanf("%s", employee.department);
    printf("Employee Salary: ");
    scanf("%lf", &employee.salary);
    employees[*employeeCount] = employee;
    *employeeCount += 1;
}

void displayEmployees(struct Employee employees[], int employeeCount) {
    printf("\nDisplaying Employees:\n");
    for (int i = 0; i < employeeCount; i++) {
        struct Employee employee = employees[i];
        printf("ID: %d, Name: %s, Department: %s, Salary: $%.2f\n", 
            employee.id, employee.name, employee.department, employee.salary);
    }
}

void searchEmployee(struct Employee employees[], int employeeCount) {
    printf("\nSearching Employee:\n");
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        struct Employee employee = employees[i];
        if (employee.id == id) {
            printf("Employee Found:\n");
            printf("ID: %d, Name: %s, Department: %s, Salary: $%.2f\n", 
                employee.id, employee.name, employee.department, employee.salary);
            return;
        }
    }
    printf("Employee not found\n");
}

void updateEmployee(struct Employee employees[], int employeeCount) {
    printf("\nUpdating Employee:\n");
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        struct Employee *employee = &employees[i];
        if (employee->id == id) {
            printf("Enter new details:\n");
            printf("Employee Name: ");
            scanf("%s", employee->name);
            printf("Employee Department: ");
            scanf("%s", employee->department);
            printf("Employee Salary: ");
            scanf("%lf", &employee->salary);
            printf("Employee Updated:\n");
            printf("ID: %d, Name: %s, Department: %s, Salary: $%.2f\n", 
                employee->id, employee->name, employee->department, employee->salary);
            return;
        }
    }
    printf("Employee not found\n");
}

void deleteEmployee(struct Employee employees[], int *employeeCount) {
    printf("\nDeleting Employee:\n");
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < *employeeCount; i++) {
        struct Employee *employee = &employees[i];
        if (employee->id == id) {
            found = 1;
        }
        if (found == 1 && i+1 < *employeeCount) {
            employees[i] = employees[i+1];
        }
    }
    if (found == 1) {
        printf("Employee deleted\n");
        *employeeCount -= 1;
    } else {
        printf("Employee not found\n");
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1: addEmployee(employees, &employeeCount); break;
            case 2: displayEmployees(employees, employeeCount); break;
            case 3: searchEmployee(employees, employeeCount); break;
            case 4: updateEmployee(employees, employeeCount); break;
            case 5: deleteEmployee(employees, &employeeCount); break;
            case 6: printf("Exiting\n"); exit(0);
            default: printf("Invalid option\n");
        }
    }
}