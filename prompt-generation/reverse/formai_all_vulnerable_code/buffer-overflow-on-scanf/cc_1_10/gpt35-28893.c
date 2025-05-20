//FormAI DATASET v1.0 Category: Database querying ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct employee {
    int id;
    char name[50];
    char department[50];
    float salary;
} Employee;

Employee employees[5] = {
    {1, "John Smith", "Sales", 50000.0},
    {2, "Jane Doe", "Marketing", 60000.0},
    {3, "Bob Johnson", "Finance", 70000.0},
    {4, "Alice Jones", "HR", 80000.0},
    {5, "Mike Brown", "IT", 90000.0}
};

int num_employees = 5;

void display_menu() {
    printf("Welcome to Employee Database Querying System\n");
    printf("=============================================\n\n");
    printf("1. Display all Employees\n");
    printf("2. Search Employee by ID\n");
    printf("3. Search Employee by Name\n");
    printf("4. Search Employee by Department\n");
    printf("5. Search Employee by Salary\n");
    printf("6. Exit\n");
}

void display_employee(Employee emp) {
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: $%.2f\n", emp.salary);
}

void display_employees() {
    for (int i = 0; i < num_employees; i++) {
        display_employee(employees[i]);
    }
}

void search_employee_id(int id) {
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            display_employee(employees[i]);
            return;
        }
    }
    printf("\nEmployee with ID %d not found.\n", id);
}

void search_employee_name(char* name) {
    for (int i = 0; i < num_employees; i++) {
        if (strcasecmp(employees[i].name, name) == 0) {
            display_employee(employees[i]);
            return;
        }
    }
    printf("\nEmployee with name %s not found.\n", name);
}

void search_employee_dept(char* dept) {
    for (int i = 0; i < num_employees; i++) {
        if (strcasecmp(employees[i].department, dept) == 0) {
            display_employee(employees[i]);
            return;
        }
    }
    printf("\nEmployee in department %s not found.\n", dept);
}

void search_employee_salary(float salary) {
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].salary == salary) {
            display_employee(employees[i]);
            return;
        }
    }
    printf("\nEmployee with salary of $%.2f not found.\n", salary);
}

int main() {
    int choice, id;
    char name[50], dept[50];
    float salary;

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_employees();
                break;
            case 2:
                printf("\nEnter employee ID: ");
                scanf("%d", &id);
                search_employee_id(id);
                break;
            case 3:
                printf("\nEnter employee name: ");
                scanf("%s", name);
                search_employee_name(name);
                break;
            case 4:
                printf("\nEnter department: ");
                scanf("%s", dept);
                search_employee_dept(dept);
                break;
            case 5:
                printf("\nEnter salary: ");
                scanf("%f", &salary);
                search_employee_salary(salary);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}