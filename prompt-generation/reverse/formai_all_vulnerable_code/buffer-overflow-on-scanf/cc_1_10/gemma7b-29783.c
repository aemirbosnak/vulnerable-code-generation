//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
typedef struct Employee
{
    char name[50];
    int age;
    float salary;
} Employee;

// Function to add an employee to the database
void addEmployee(Employee *employee)
{
    printf("Enter employee name: ");
    scanf("%s", employee->name);

    printf("Enter employee age: ");
    scanf("%d", &employee->age);

    printf("Enter employee salary: ");
    scanf("%f", &employee->salary);
}

// Function to display all employees
void displayEmployees(Employee *employees, int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }
}

int main()
{
    // Create an array of employees
    Employee *employees = NULL;

    // Initialize the number of employees to 0
    int numEmployees = 0;

    // Add an employee to the database
    addEmployee(&employees);
    numEmployees++;

    // Add another employee to the database
    addEmployee(&employees);
    numEmployees++;

    // Display all employees
    displayEmployees(employees, numEmployees);

    return 0;
}