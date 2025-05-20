//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

void inputEmployeeData(Employee *emp, int index) {
    printf("Enter name for Employee %d: ", index + 1);
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = 0; // Remove the newline character

    printf("Enter age for Employee %d: ", index + 1);
    scanf("%d", &emp->age);
    
    printf("Enter salary for Employee %d: ", index + 1);
    scanf("%f", &emp->salary);
    getchar(); // Consume the newline character left by scanf
}

void displayEmployeeData(Employee emp, int index) {
    printf("\nEmployee %d Details:\n", index + 1);
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
}

void calculateAverageSalary(Employee *employees, int count) {
    float totalSalary = 0.0f;

    for (int i = 0; i < count; i++) {
        totalSalary += employees[i].salary;
    }

    float averageSalary = totalSalary / count;
    printf("\nAverage Salary of Employees: %.2f\n", averageSalary);
}

void displaySalaryAboveAverage(Employee *employees, int count, float average) {
    printf("\nEmployees with salary above average (%.2f):\n", average);
    for (int i = 0; i < count; i++) {
        if (employees[i].salary > average) {
            displayEmployeeData(employees[i], i);
        }
    }
}

int main() {
    Employee employees[MAX_RECORDS];
    int numEmployees;

    printf("Welcome to Employee Data Mining Program!\n");
    printf("How many employees do you want to enter (max %d): ", MAX_RECORDS);
    scanf("%d", &numEmployees);
    getchar(); // Consume the newline character left by scanf

    if (numEmployees > MAX_RECORDS || numEmployees <= 0) {
        printf("Invalid number of employees!\n");
        return 1;
    }

    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        inputEmployeeData(&employees[i], i);
    }

    printf("\nYou entered the following employee data:\n");
    for (int i = 0; i < numEmployees; i++) {
        displayEmployeeData(employees[i], i);
    }

    calculateAverageSalary(employees, numEmployees);

    float averageSalary = 0.0f;
    for (int i = 0; i < numEmployees; i++) {
        averageSalary += employees[i].salary;
    }
    averageSalary /= numEmployees;

    displaySalaryAboveAverage(employees, numEmployees, averageSalary);

    printf("\nThank you for using the Employee Data Mining Program!\n");
    return 0;
}