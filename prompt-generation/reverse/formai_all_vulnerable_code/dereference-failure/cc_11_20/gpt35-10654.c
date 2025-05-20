//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int main() {
    int num_employees = 0;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);

    Employee* employees = (Employee*) malloc(num_employees * sizeof(Employee));

    // Fill the employee array with dummy data for the purpose of this example
    for (int i = 0; i < num_employees; i++) {
        Employee emp;
        emp.id = i + 1;
        sprintf(emp.name, "Employee %d", i + 1);
        emp.age = 25 + i;
        emp.salary = 50000.0 + (i * 1000.0);
        employees[i] = emp;
    }

    // Query for employees with age greater than 30 and salary less than 55000
    printf("\nEmployees with age greater than 30 and salary less than 55000:\n");
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].age > 30 && employees[i].salary < 55000.0) {
            printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        }
    }

    // Query for employees with name starting with 'E' and age less than 30
    printf("\nEmployees with name starting with 'E' and age less than 30:\n");
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].name[0] == 'E' && employees[i].age < 30) {
            printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        }
    }

    // Query for employees with highest salary
    float max_salary = employees[0].salary;
    for (int i = 1; i < num_employees; i++) {
        if (employees[i].salary > max_salary) {
            max_salary = employees[i].salary;
        }
    }
    printf("\nEmployees with highest salary:\n");
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].salary == max_salary) {
            printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        }
    }

    free(employees);
    return 0;
}