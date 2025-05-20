//Gemma-7B DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store employee information
typedef struct Employee
{
    char name[50];
    int age;
    float salary;
    struct Employee* next;
} Employee;

// Function to insert a new employee at the end
void insertEmployee(Employee* head)
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("Enter employee name: ");
    scanf("%s", newEmployee->name);
    printf("Enter employee age: ");
    scanf("%d", &newEmployee->age);
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee->salary);

    if (head == NULL)
    {
        head = newEmployee;
    }
    else
    {
        Employee* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

// Function to print all employees
void printEmployees(Employee* head)
{
    Employee* currentEmployee = head;
    while (currentEmployee)
    {
        printf("Name: %s, Age: %d, Salary: %.2f\n", currentEmployee->name, currentEmployee->age, currentEmployee->salary);
        currentEmployee = currentEmployee->next;
    }
}

int main()
{
    Employee* head = NULL;
    int choice = 0;

    // Loop until the user chooses to exit
    while (choice != 3)
    {
        printf("Enter 1 to insert a new employee, 2 to print all employees, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertEmployee(head);
                break;
            case 2:
                printEmployees(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}