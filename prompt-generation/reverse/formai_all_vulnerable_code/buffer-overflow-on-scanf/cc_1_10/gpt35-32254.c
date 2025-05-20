//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char name[20];
    int age;
    float salary;
} Employee;

void addEmployee(Employee** arr, int size)
{
    Employee newEmp;
    printf("Enter Employee Name: ");
    scanf("%s", newEmp.name);
    printf("Enter Employee Age: ");
    scanf("%d", &newEmp.age);
    printf("Enter Employee Salary: ");
    scanf("%f", &newEmp.salary);
    arr[size] = (Employee*)malloc(sizeof(Employee));
    *arr[size] = newEmp;
}

void printEmployee(Employee emp)
{
    printf("\nName: %s\nAge: %d\nSalary: %f\n", emp.name, emp.age, emp.salary);
}

void displayAllEmployees(Employee** arr, int size)
{
    for(int i=0;i<size;i++)
        printEmployee(*arr[i]);
}

int menu()
{
    int choice;
    printf("\n1. Add Employee\n2. Display All Employees\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int size = 0;
    Employee* arr[100];
    int choice;

    while(1)
    {
        choice = menu();
        switch(choice)
        {
            case 1:
                addEmployee(arr, size);
                size++;
                break;
            case 2:
                displayAllEmployees(arr, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}