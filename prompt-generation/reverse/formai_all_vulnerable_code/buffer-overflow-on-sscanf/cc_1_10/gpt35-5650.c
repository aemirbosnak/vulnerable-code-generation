//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing employee data
struct employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main() {
    // Declare and initialize variables
    struct employee employees[100];
    int num_employees = 0, choice = 0;
    char input[50];

    // Main menu loop
    do {
        printf("\nEmployee Database Simulation\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Employee ID: ");
                fgets(input, 50, stdin);
                sscanf(input, "%d", &employees[num_employees].id);

                printf("Enter Employee Name: ");
                fgets(employees[num_employees].name, 50, stdin);

                printf("Enter Employee Department: ");
                fgets(employees[num_employees].department, 50, stdin);

                printf("Enter Employee Salary: ");
                fgets(input, 50, stdin);
                sscanf(input, "%f", &employees[num_employees].salary);

                num_employees++;
                printf("\nEmployee Added Successfully!\n");
                break;
            
            case 2:
                printf("\nEmployee Database:\n");
                printf("ID\tName\t\tDepartment\tSalary\n");
                for (int i = 0; i < num_employees; i++) {
                    printf("%d\t%s\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
                }
                break;
            
            case 3:
                printf("\nEnter Employee ID to Search: ");
                fgets(input, 50, stdin);
                int search_id;
                sscanf(input, "%d", &search_id);
                
                for (int i = 0; i < num_employees; i++) {
                    if (employees[i].id == search_id) {
                        printf("\nEmployee Found:\n");
                        printf("ID\tName\t\tDepartment\tSalary\n");
                        printf("%d\t%s\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
                        break;
                    }
                    if (i == num_employees - 1) {
                        printf("\nEmployee Not Found!\n");
                    }
                }
                break;
            
            case 4:
                printf("\nThank you for using Employee Database Simulation!\n");
                break;

            default:
                printf("\nInvalid Input!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}