//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a variable to store the number of employees
    int numEmployees = 0;

    // Create a loop to add employees until the number is greater than 0
    while (numEmployees <= 0)
    {
        printf("Enter the number of employees: ");
        scanf("%d", &numEmployees);

        // Check if the number of employees is greater than 0
        if (numEmployees > 0)
        {
            printf("The number of employees is greater than 0.\n");
        }
    }

    // Create an array of employee information
    struct Employee
    {
        char name[20];
        int salary;
        int yearsOfService;
    } employees[numEmployees];

    // Get employee information from the user
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Enter the name of the employee: ");
        scanf("%s", employees[i].name);

        printf("Enter the salary of the employee: ");
        scanf("%d", &employees[i].salary);

        printf("Enter the years of service of the employee: ");
        scanf("%d", &employees[i].yearsOfService);
    }

    // Calculate the total salary of all employees
    int totalSalary = 0;
    for (int i = 0; i < numEmployees; i++)
    {
        totalSalary += employees[i].salary;
    }

    // Print the total salary of all employees
    printf("The total salary of all employees is: $%d\n", totalSalary);

    // Free the memory allocated for the employees array
    free(employees);

    return 0;
}