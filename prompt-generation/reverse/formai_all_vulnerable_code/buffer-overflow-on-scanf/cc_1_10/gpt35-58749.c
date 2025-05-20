//FormAI DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct
typedef struct 
{
    int id;
    char name[50];
    int age;
    int salary;
} Employee;

// Function to print employee details
void printEmployeeDetails(Employee *employee)
{
    printf("ID: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Age: %d\n", employee->age);
    printf("Salary: %d\n", employee->salary);
}

int main()
{
    int choice; 
    int i, j; 
    char search[50];
    Employee employees[5] = {
        { 1, "John", 25, 5000 },
        { 2, "Mary", 32, 8000 },
        { 3, "Bob", 28, 6000 },
        { 4, "Alice", 35, 9000 },
        { 5, "Tom", 30, 7000 }
    };

    printf("Enter 1 to search employee by name or 2 to search employee by ID: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter employee name: ");
        scanf("%s", search);
        for (i = 0; i < 5; i++)
        {
            if (strcmp(search, employees[i].name) == 0)
            {
                printf("Employee found!\n");
                printEmployeeDetails(&employees[i]);
                break;
            }
        }
        if (i == 5)
        {
            printf("Employee not found!\n");
        }
    }
    else if (choice == 2)
    {
        printf("Enter employee ID: ");
        scanf("%d", &j);
        for (i = 0; i < 5; i++)
        {
            if (j == employees[i].id)
            {
                printf("Employee found!\n");
                printEmployeeDetails(&employees[i]);
                break;
            }
        }
        if (i == 5)
        {
            printf("Employee not found!\n");
        }
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}