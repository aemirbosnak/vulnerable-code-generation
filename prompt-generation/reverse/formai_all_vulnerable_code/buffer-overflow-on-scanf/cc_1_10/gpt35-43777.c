//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    char department[50];
    double salary;
};

void display_menu()
{
    printf("Please select your option:\n");
    printf("1. Add Employee\n");
    printf("2. Search for Employee\n");
    printf("3. View all Employees\n");
    printf("4. Delete Employee\n");
    printf("5. Exit\n");
}

void add_employee(struct Employee *e, int *num_employees)
{
    printf("Enter Employee ID: ");
    scanf("%d", &(e+*num_employees)->id);
    printf("Enter Employee Name: ");
    scanf("%s", &(e+*num_employees)->name);
    printf("Enter Employee Department: ");
    scanf("%s", &(e+*num_employees)->department);
    printf("Enter Employee Salary: ");
    scanf("%lf", &(e+*num_employees)->salary);
    *num_employees += 1;
}

void search_employee(struct Employee *e, int num_employees)
{
    int id;
    printf("Enter Employee ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_employees; i++)
    {
        if ((e+i)->id == id)
        {
            printf("Employee Name: %s\n", (e+i)->name);
            printf("Employee Department: %s\n", (e+i)->department);
            printf("Employee Salary: %.2lf\n", (e+i)->salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

void view_employees(struct Employee *e, int num_employees)
{
    for (int i = 0; i < num_employees; i++)
    {
        printf("Employee ID: %d\n", (e+i)->id);
        printf("Employee Name: %s\n", (e+i)->name);
        printf("Employee Department: %s\n", (e+i)->department);
        printf("Employee Salary: %.2lf\n", (e+i)->salary);
        printf("\n");
    }
}

void delete_employee(struct Employee *e, int *num_employees)
{
    int id;
    printf("Enter Employee ID: ");
    scanf("%d", &id);
    for (int i = 0; i < *num_employees; i++)
    {
        if ((e+i)->id == id)
        {
            for (int j = i; j < *num_employees - 1; j++)
            {
                *(e+j) = *(e+j+1);
            }
            *num_employees -= 1;
            printf("Employee deleted.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

int main()
{
    int option, num_employees = 0;
    struct Employee *employees = (struct Employee*) malloc(10 * sizeof(struct Employee));
    
    do
    {
        display_menu();
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                if (num_employees == 10)
                {
                    printf("Database is full.\n");
                }
                else
                {
                    add_employee(employees, &num_employees);
                }
                break;
            case 2:
                search_employee(employees, num_employees);
                break;
            case 3:
                if (num_employees == 0)
                {
                    printf("No employees in database.\n");
                }
                else
                {
                    view_employees(employees, num_employees);
                }
                break;
            case 4:
                if (num_employees == 0)
                {
                    printf("No employees in database.\n");
                }
                else
                {
                    delete_employee(employees, &num_employees);
                }
                break;
            case 5:
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 5);
    
    free(employees);
    
    return 0;
}