//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMPLOYEES 100
#define MAX_SALARY 999999.99

typedef struct Employee {
    char name[MAX_NAME_LEN];
    float salary;
} Employee;

int main() {
    Employee employees[MAX_EMPLOYEES];
    float salaries[MAX_EMPLOYEES];
    int num_employees;
    float avg_salary = 0;
    float max_salary = 0;
    int max_salary_employee_index = -1;
    
    printf("Enter number of employees (up to %d): ", MAX_EMPLOYEES);
    scanf("%d", &num_employees);
    if (num_employees > MAX_EMPLOYEES) {
        printf("Too many employees, max is %d\n", MAX_EMPLOYEES);
        return 1;
    }
    printf("Enter employee names and salaries:\n");
    for (int i = 0; i < num_employees; i++) {
        scanf("%s %f", employees[i].name, &employees[i].salary);
        if (employees[i].salary > MAX_SALARY) {
            printf("Salary entered for %s is too high, max is %.2f\n", employees[i].name, MAX_SALARY);
            return 1;
        }
        salaries[i] = employees[i].salary;
        avg_salary += salaries[i];
        if (salaries[i] > max_salary) {
            max_salary = salaries[i];
            max_salary_employee_index = i;
        }
    }
    avg_salary /= num_employees;
    
    printf("\nEmployee\t\tSalary\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%-16s\t%.2lf\n", employees[i].name, employees[i].salary);
    }
    printf("Average Salary: $%.2f\n", avg_salary);
    printf("Highest Salary: $%.2f (held by %s)\n", max_salary, employees[max_salary_employee_index].name);
    
    return 0;
}