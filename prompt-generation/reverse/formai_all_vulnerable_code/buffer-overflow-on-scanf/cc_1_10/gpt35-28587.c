//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    char name[50];
    int age;
    char department[30];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void addEmployee() {
    Employee newEmployee;
    printf("Enter employee name: ");
    fgets(newEmployee.name, 50, stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0'; // remove trailing newline
    printf("Enter employee age: ");
    scanf("%d", &newEmployee.age);
    getchar(); // remove trailing newline from input buffer
    printf("Enter employee department: ");
    fgets(newEmployee.department, 30, stdin);
    newEmployee.department[strcspn(newEmployee.department, "\n")] = '\0'; // remove trailing newline
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);
    getchar(); // remove trailing newline from input buffer
    
    employees[numEmployees++] = newEmployee;
    printf("Employee added!\n");
}

void printEmployee(Employee e) {
    printf("Name: %s\n", e.name);
    printf("Age: %d\n", e.age);
    printf("Department: %s\n", e.department);
    printf("Salary: $%.2f\n", e.salary);
}

void listEmployees() {
    if (numEmployees == 0) {
        printf("No employees in the database.\n");
        return;
    }
    
    printf("Employee list:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d:\n", i+1);
        printEmployee(employees[i]);
    }
}

void searchByDepartment() {
    char query[30];
    printf("Enter department to search for: ");
    fgets(query, 30, stdin);
    query[strcspn(query, "\n")] = '\0'; // remove trailing newline
    
    int numMatches = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(employees[i].department, query) == 0) {
            printEmployee(employees[i]);
            numMatches++;
        }
    }
    
    if (numMatches == 0) {
        printf("No employees found in department %s\n", query);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("1. Add employee\n");
        printf("2. List employees\n");
        printf("3. Search by department\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // remove trailing newline from input buffer
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                searchByDepartment();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
        
        printf("\n"); // add a blank line for readability
    }
    
    return 0;
}