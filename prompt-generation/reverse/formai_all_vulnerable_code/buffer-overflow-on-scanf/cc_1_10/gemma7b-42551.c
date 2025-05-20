//Gemma-7B DATASET v1.0 Category: Database querying ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store employee information
struct employee
{
    char name[50];
    int employee_id;
    double salary;
    char department[50];
};

// Define a function to search for employees by department
void search_by_department(struct employee *employees, int num_employees, char *department)
{
    for (int i = 0; i < num_employees; i++)
    {
        if (strcmp(employees[i].department, department) == 0)
        {
            printf("Employee name: %s\n", employees[i].name);
            printf("Employee ID: %d\n", employees[i].employee_id);
            printf("Salary: %.2lf\n", employees[i].salary);
            printf("Department: %s\n", employees[i].department);
            printf("\n");
        }
    }
}

int main()
{
    // Create an array of employees
    struct employee employees[] =
    {
        {"John Doe", 1, 50000, "Sales"},
        {"Jane Doe", 2, 60000, "Marketing"},
        {"Peter Pan", 3, 70000, "Finance"},
        {"Mary Poppins", 4, 80000, "HR"}
    };

    // Get the department to search for
    char department[50];
    printf("Enter department name: ");
    scanf("%s", department);

    // Search for employees by department
    search_by_department(employees, 4, department);

    return 0;
}