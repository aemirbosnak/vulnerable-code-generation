//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMPLOYEES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

void print_menu();
void read_employees_data(Employee employees[], int size);
void print_employees(Employee employees[], int size);
void sort_employees(Employee employees[], int size);

int main() {
    Employee employees[MAX_EMPLOYEES];
    int size, choice;

    printf("Welcome to the Employee Management System\n");
    print_menu();

    size = 0;
    while (size < 1) {
        printf("Enter the number of employees: ");
        scanf("%d", &size);

        if (size > MAX_EMPLOYEES) {
            printf("Error: Maximum number of employees is %d.\n", MAX_EMPLOYEES);
            printf("Please try again.\n");
        }
    }

    read_employees_data(employees, size);
    sort_employees(employees, size);
    print_employees(employees, size);

    return 0;
}

void print_menu() {
    printf("\nEmployee Management System Menu:\n");
    printf("----------------------------------\n");
    printf("1. Read employee data from the keyboard\n");
    printf("2. Sort employees by salary\n");
    printf("3. Print employee data\n");
    printf("4. Exit\n");
}

void read_employees_data(Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf("%s", employees[i].name);

        printf("Enter age of employee %d: ", i + 1);
        scanf("%d", &employees[i].age);

        printf("Enter salary of employee %d: ", i + 1);
        scanf("%f", &employees[i].salary);
    }
}

void sort_employees(Employee employees[], int size) {
    int i, j, temp;
    Employee temp_employee;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (employees[j].salary < employees[j + 1].salary) {
                temp = employees[j].salary;
                employees[j].salary = employees[j + 1].salary;
                employees[j + 1].salary = temp;

                temp_employee = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp_employee;
            }
        }
    }
}

void print_employees(Employee employees[], int size) {
    printf("\nEmployee Data:\n");
    printf("------------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }
}