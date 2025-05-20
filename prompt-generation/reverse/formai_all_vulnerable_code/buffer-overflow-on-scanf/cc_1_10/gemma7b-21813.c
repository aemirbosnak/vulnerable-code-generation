//Gemma-7B DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define database structure
typedef struct Employee
{
    char name[50];
    int age;
    double salary;
    struct Employee* next;
} Employee;

// Function to insert a new employee at the end
void insertEmployee(Employee** head)
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("Enter name: ");
    scanf("%s", newEmployee->name);
    printf("Enter age: ");
    scanf("%d", &newEmployee->age);
    printf("Enter salary: ");
    scanf("%lf", &newEmployee->salary);

    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        (*head)->next = newEmployee;
    }
    *head = newEmployee;
}

// Function to search for an employee by name
Employee* searchEmployeeByName(Employee* head, char* name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update an employee's salary
void updateEmployeeSalary(Employee* head, char* name, double newSalary)
{
    Employee* employee = searchEmployeeByName(head, name);
    if (employee)
    {
        employee->salary = newSalary;
    }
}

// Function to delete an employee
void deleteEmployee(Employee* head, char* name)
{
    Employee* employee = searchEmployeeByName(head, name);
    if (employee)
    {
        Employee* previousEmployee = NULL;
        while (employee->next)
        {
            previousEmployee = employee;
            employee = employee->next;
        }
        if (previousEmployee)
        {
            previousEmployee->next = employee->next;
        }
        else
        {
            head = NULL;
        }
        free(employee);
    }
}

int main()
{
    Employee* head = NULL;

    // Insert some employees
    insertEmployee(&head);
    insertEmployee(&head);
    insertEmployee(&head);

    // Search for an employee by name
    Employee* employee = searchEmployeeByName(head, "John Doe");
    if (employee)
    {
        printf("Name: %s\n", employee->name);
        printf("Age: %d\n", employee->age);
        printf("Salary: %.2lf\n", employee->salary);
    }

    // Update an employee's salary
    updateEmployeeSalary(head, "Jane Doe", 50000);
    employee = searchEmployeeByName(head, "Jane Doe");
    if (employee)
    {
        printf("Updated salary: %.2lf\n", employee->salary);
    }

    // Delete an employee
    deleteEmployee(head, "Peter Pan");
    employee = searchEmployeeByName(head, "Peter Pan");
    if (employee)
    {
        printf("Employee not found.\n");
    }

    return 0;
}