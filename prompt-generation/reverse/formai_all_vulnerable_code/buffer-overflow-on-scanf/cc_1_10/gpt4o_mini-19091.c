//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int age;
    float salary;
} Employee;

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}

void addEmployee(Employee** employees, int* totalEmployees) {
    if (*totalEmployees >= MAX_RECORDS) {
        printf("Maximum limit of employees reached.\n");
        return;
    }
    
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if (!newEmployee) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter employee name: ");
    fgets(newEmployee->name, NAME_LEN, stdin);
    newEmployee->name[strcspn(newEmployee->name, "\n")] = 0; // Remove newline

    printf("Enter employee age: ");
    scanf("%d", &newEmployee->age);
    clearBuffer(); // Clear input buffer

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee->salary);
    clearBuffer(); // Clear input buffer

    employees[*totalEmployees] = newEmployee;
    (*totalEmployees)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(Employee** employees, int totalEmployees) {
    if (totalEmployees == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\nEmployee Records:\n");
    for (int i = 0; i < totalEmployees; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i]->name, employees[i]->age, employees[i]->salary);
    }
}

void freeMemory(Employee** employees, int totalEmployees) {
    for (int i = 0; i < totalEmployees; i++) {
        free(employees[i]); // Free each allocated employee
    }
    free(employees); // Free the array of employees
}

int main() {
    Employee** employees = (Employee**) malloc(MAX_RECORDS * sizeof(Employee*));
    if (!employees) {
        printf("Memory allocation for employees array failed.\n");
        return EXIT_FAILURE;
    }
    
    int totalEmployees = 0;
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer after reading choice
        
        switch (choice) {
            case 1:
                addEmployee(employees, &totalEmployees);
                break;
            case 2:
                displayEmployees(employees, totalEmployees);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    freeMemory(employees, totalEmployees);
    return EXIT_SUCCESS;
}