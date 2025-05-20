//FormAI DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    float salary;
} Employee;

int main() {
    Employee employeeDB[10];
    int numEmployees = 0;
    int choice, i;

    while (1) {
        printf("\n\nEmployee Database Simulation\n");
        printf("----------------------------\n");
        printf("1. Add Employee\n");
        printf("2. View Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdd Employee\n");
                printf("-------------\n");
                printf("Enter Name: ");
                scanf("%s", employeeDB[numEmployees].name);
                printf("Enter Age: ");
                scanf("%d", &employeeDB[numEmployees].age);
                printf("Enter Salary: ");
                scanf("%f", &employeeDB[numEmployees].salary);
                numEmployees++;
                break;
            
            case 2:
                printf("\nView Employee\n");
                printf("--------------\n");
                if (numEmployees == 0) {
                    printf("No Employee Found!\n");
                    break;
                }
                printf("Employee List:\n");
                for (i = 0; i < numEmployees; i++) {
                    printf("%d. %s\t%d\t%.2f\n", i + 1, employeeDB[i].name,
                        employeeDB[i].age, employeeDB[i].salary);
                }
                break;
            
            case 3:
                printf("\nDelete Employee\n");
                printf("-----------------\n");
                if (numEmployees == 0) {
                    printf("No Employee Found!\n");
                    break;
                }
                printf("Employee List:\n");
                for (i = 0; i < numEmployees; i++) {
                    printf("%d. %s\t%d\t%.2f\n", i + 1, employeeDB[i].name,
                        employeeDB[i].age, employeeDB[i].salary);
                }
                printf("Enter the index of the employee to delete: ");
                scanf("%d", &i);
                if (i < 1 || i > numEmployees) {
                    printf("Invalid Index!\n");
                    break;
                }
                for (; i < numEmployees; i++) {
                    employeeDB[i - 1] = employeeDB[i];
                }
                numEmployees--;
                printf("Employee Deleted Successfully!\n");
                break;

            case 4:
                printf("\nExiting Employee Database Simulation. . .\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }
    return 0;
}