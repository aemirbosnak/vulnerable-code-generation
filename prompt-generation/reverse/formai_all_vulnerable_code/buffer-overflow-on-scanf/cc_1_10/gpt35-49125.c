//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    int salary;
} Employee;

void addEmployee(Employee *employees, int *count) {
    Employee newEmployee;
    printf("Enter ID: ");
    scanf("%d", &newEmployee.id);
    printf("Enter name: ");
    scanf("%s", newEmployee.name);
    printf("Enter age: ");
    scanf("%d", &newEmployee.age);
    printf("Enter salary: ");
    scanf("%d", &newEmployee.salary);
    
    employees[*count] = newEmployee;
    (*count)++;
}

void displayEmployees(Employee *employees, int count) {
    printf("\nTotal Employees: %d", count);
    printf("\n------------------");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nAge: %d\nSalary: %d\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        printf("------------------");
    }
}

void searchEmployeeById(Employee *employees, int count) {
    int id, found = 0;
    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee found!\n");
            printf("------------------");
            printf("\nID: %d\nName: %s\nAge: %d\nSalary: %d\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
            printf("------------------");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee not found!\n");
    }
}

void updateEmployeeById(Employee *employees, int count) {
    int id, found = 0;
    printf("\nEnter employee ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee found!\n");
            printf("------------------");
            printf("\nEnter new name: ");
            scanf("%s", employees[i].name);
            printf("Enter new age: ");
            scanf("%d", &employees[i].age);
            printf("Enter new salary: ");
            scanf("%d", &employees[i].salary);
            printf("------------------");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee not found!\n");
    }
}

void deleteEmployeeById(Employee *employees, int *count) {
    int id, found = 0;
    printf("\nEnter employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j+1];
            }
            printf("\nEmployee deleted!\n");
            printf("------------------");
            (*count)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee not found!\n");
    }
}

int main()
{
    int choice, count = 0;
    Employee employees[10];
    
    while(1) {
        printf("\n\nEmployee Database\n\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee by ID\n");
        printf("5. Delete Employee by ID\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                searchEmployeeById(employees, count);
                break;
            case 4:
                updateEmployeeById(employees, count);
                break;
            case 5:
                deleteEmployeeById(employees, &count);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}