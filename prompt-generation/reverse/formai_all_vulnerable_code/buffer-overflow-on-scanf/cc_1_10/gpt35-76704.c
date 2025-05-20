//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee
{
    char name[30];
    int employeeID;
    int age;
    float salary;
}employee[100];
int numEmployee=0;

void addEmployee()
{
    printf("\nAdding an Employee \n");

    printf("Enter the Employee ID: ");
    scanf("%d", &employee[numEmployee].employeeID);
    getchar();

    printf("Enter the Employee name: ");
    fgets(employee[numEmployee].name, 30, stdin);
    employee[numEmployee].name[strcspn(employee[numEmployee].name,"\n")]='\0';

    printf("Enter the Employee age: ");
    scanf("%d", &employee[numEmployee].age);

    printf("Enter the Employee salary: ");
    scanf("%f", &employee[numEmployee].salary);

    printf("\nEmployee Added Successfully!\n");

    numEmployee++;
}

void deleteEmployee()
{
    int employeeID, i, j;

    printf("\nDeleting an Employee\n");
    printf("Enter the Employee ID: ");
    scanf("%d", &employeeID);

    for (i = 0; i < numEmployee; i++)
    {
        if (employee[i].employeeID == employeeID)
        {
            for (j = i; j < numEmployee-1; j++)
            {
                employee[j] = employee[j+1];
            }
            numEmployee--;
            printf("\nEmployee Deleted Successfully!\n");
            return;
        }
    }
    printf("\nEmployee not found!\n");
}

void displayEmployee()
{
    int i;

    if(numEmployee==0)
    {
        printf("\nNo Employees are in the database!\n");
        return;
    }

    printf("\nDisplaying Employees\n");
    for(i=0; i<numEmployee; i++)
    {
        printf("\nEmployee ID: %d\n", employee[i].employeeID);
        printf("Employee Name: %s\n", employee[i].name);
        printf("Employee Age: %d\n", employee[i].age);
        printf("Employee Salary: %.2f\n\n", employee[i].salary);
    }
}

int main()
{
    int choice;

    //Display the menu
    do
    {
        printf("\nMenu\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Display Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                deleteEmployee();
                break;

            case 3:
                displayEmployee();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
                break;
        }
    } while(1);
    return 0;
}