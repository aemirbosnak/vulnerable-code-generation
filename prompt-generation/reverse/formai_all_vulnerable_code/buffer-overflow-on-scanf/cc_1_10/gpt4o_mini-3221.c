//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 30
#define POSITION_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char position[POSITION_LENGTH];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Employee database is full!\n");
        return;
    }
    
    Employee emp;
    emp.id = employee_count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", emp.name);
    printf("Enter position: ");
    scanf(" %[^\n]", emp.position);
    printf("Enter salary: ");
    scanf("%f", &emp.salary);

    employees[employee_count] = emp;
    employee_count++;
    printf("Employee added successfully!\n");
}

void display_employees() {
    if (employee_count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee List:\n");
    printf("ID\tName\t\tPosition\tSalary\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary);
    }
}

void search_employee() {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    if (id <= 0 || id > employee_count) {
        printf("No employee found with ID: %d\n", id);
        return;
    }

    Employee emp = employees[id - 1];
    printf("Employee Details:\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Position: %s\n", emp.position);
    printf("Salary: %.2f\n", emp.salary);
}

void display_menu() {
    printf("\nEmployee Database Menu:\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}