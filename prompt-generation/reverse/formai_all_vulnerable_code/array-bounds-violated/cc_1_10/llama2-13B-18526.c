//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MAX_SALARY 100000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    double salary;
} employee_t;

void print_employee(employee_t *emp) {
    printf("Name: %s, Age: %d, Salary: %f\n", emp->name, emp->age, emp->salary);
}

int main() {
    employee_t emp1 = {
        .name = "John Doe",
        .age = 30,
        .salary = 50000.0
    };

    employee_t emp2 = {
        .name = "Jane Doe",
        .age = 25,
        .salary = 80000.0
    };

    employee_t *emp_array[2] = {&emp1, &emp2};

    // Calculate the average salary of the employees
    double avg_salary = 0;
    for (int i = 0; i < 2; i++) {
        avg_salary += emp_array[i]->salary;
    }
    avg_salary /= 2;
    printf("Average salary: %f\n", avg_salary);

    // Calculate the difference between the salaries of the employees
    double diff = 0;
    for (int i = 0; i < 2; i++) {
        diff += fabs(emp_array[i]->salary - emp_array[i + 1]->salary);
    }
    diff /= 2;
    printf("Difference between salaries: %f\n", diff);

    // Calculate the percentage increase of the salary of the first employee
    double percent_inc = 0;
    if (emp1.salary < emp2.salary) {
        percent_inc = (emp2.salary - emp1.salary) / emp1.salary * 100;
    }
    printf("Percentage increase of salary for first employee: %f\n", percent_inc);

    // Calculate the number of years until the salary of the first employee reaches the salary of the second employee
    int years = 0;
    while (emp1.salary < emp2.salary) {
        emp1.salary += 5000;
        years++;
    }
    printf("Number of years until salary of first employee reaches salary of second employee: %d\n", years);

    return 0;
}