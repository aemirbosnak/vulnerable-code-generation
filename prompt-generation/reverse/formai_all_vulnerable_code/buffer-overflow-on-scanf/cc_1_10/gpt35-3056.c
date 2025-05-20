//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
    float salary;
} Employee;

int numEmployees = 0;

void addEmployee(Employee* employees) {
    printf("Enter name: ");
    scanf("%s", &employees[numEmployees].name);
    printf("Enter age: ");
    scanf("%d", &employees[numEmployees].age);
    printf("Enter gender: ");
    scanf("%s", &employees[numEmployees].gender);
    printf("Enter salary: ");
    scanf("%f", &employees[numEmployees].salary);
    numEmployees++;
}

void printDatabase(Employee* employees) {
    printf("Employees in database:\n\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Gender: %s\n", employees[i].gender);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
}

float getAverageSalary(Employee* employees) {
    float total = 0;
    for (int i = 0; i < numEmployees; i++) {
        total += employees[i].salary;
    }
    return total / numEmployees;
}

int main() {
    Employee employees[100];

    printf("Welcome to the employee database!\n");
    printf("How many employees would you like to add? ");
    int numToAdd;
    scanf("%d", &numToAdd);

    for (int i = 0; i < numToAdd; i++) {
        addEmployee(employees);
    }

    printf("\n");
    printDatabase(employees);

    float avgSalary = getAverageSalary(employees);
    printf("The average salary of employees in the database is: %.2f\n", avgSalary);

    return 0;
}