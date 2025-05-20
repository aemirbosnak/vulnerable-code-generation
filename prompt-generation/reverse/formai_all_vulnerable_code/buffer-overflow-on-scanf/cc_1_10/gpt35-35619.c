//FormAI DATASET v1.0 Category: Database simulation ; Style: protected
// This program simulates a database of employees with protected access levels

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Employee {
    char name[50];
    char position[50];
    float salary;
} Employee;

void addEmployee(Employee* employees, int* numEmployees) {
    printf("Enter name: ");
    scanf("%s", employees[*numEmployees].name);
    printf("Enter position: ");
    scanf("%s", employees[*numEmployees].position);
    printf("Enter salary: ");
    scanf("%f", &employees[*numEmployees].salary);
    (*numEmployees)++;
}

void printEmployees(Employee* employees, int numEmployees) {
    printf("%-20s %-20s %-20s\n", "Name", "Position", "Salary");
    for (int i = 0; i < numEmployees; i++) {
        printf("%-20s %-20s $%.2f\n", employees[i].name, employees[i].position, employees[i].salary);
    }
}

int main() {
    Employee employees[100];
    int numEmployees = 0;
    int choice;
    do {
        printf("1. Add Employee\n");
        printf("2. Print Employees\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                printEmployees(employees, numEmployees);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);
    return 0;
}