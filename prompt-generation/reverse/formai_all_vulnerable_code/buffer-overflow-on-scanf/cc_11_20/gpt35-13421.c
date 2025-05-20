//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

typedef struct employee Employee;

int main() {
    int choice;
    Employee database[5] = {{1, "John Doe", "Sales", 50000}, {2, "Jane Smith", "Marketing", 60000}, {3, "Bob Johnson", "IT", 75000}, {4, "Samantha White", "HR", 55000}, {5, "Tom Davis", "Operations", 80000}};

    while(1) {
        printf("\nWelcome to the Employee Database Query Program!\n");
        printf("Please select one of the following options:\n");
        printf("1. Print all employees in the database\n");
        printf("2. Search for an employee by their ID\n");
        printf("3. Search for an employee by their name\n");
        printf("4. Search for an employee by their department\n");
        printf("5. Exit the program\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEmployee Database:\n");
            printf("ID\tName\tDepartment\tSalary\n");
            for(int i = 0; i < 5; i++) {
                printf("%d\t%s\t%s\t%.2f\n", database[i].id, database[i].name, database[i].department, database[i].salary);
            }
        }
        else if(choice == 2) {
            int employee_id;
            printf("\nPlease enter the employee's ID: ");
            scanf("%d", &employee_id);

            for(int i = 0; i < 5; i++) {
                if(database[i].id == employee_id) {
                    printf("\nEmployee found:\n");
                    printf("ID\tName\tDepartment\tSalary\n");
                    printf("%d\t%s\t%s\t%.2f\n", database[i].id, database[i].name, database[i].department, database[i].salary);
                    break;
                }
                if(i == 4) {
                    printf("\nEmployee with ID %d not found\n", employee_id);
                }
            }
        }
        else if(choice == 3) {
            char employee_name[50];
            printf("\nPlease enter the employee's name: ");
            scanf("%s", employee_name);

            for(int i = 0; i < 5; i++) {
                if(strcmp(database[i].name, employee_name) == 0) {
                    printf("\nEmployee found:\n");
                    printf("ID\tName\tDepartment\tSalary\n");
                    printf("%d\t%s\t%s\t%.2f\n", database[i].id, database[i].name, database[i].department, database[i].salary);
                    break;
                }
                if(i == 4) {
                    printf("\nEmployee with name %s not found\n", employee_name);
                }
            }
        }
        else if(choice == 4) {
            char employee_department[50];
            printf("\nPlease enter the employee's department: ");
            scanf("%s", employee_department);

            for(int i = 0; i < 5; i++) {
                if(strcmp(database[i].department, employee_department) == 0) {
                    printf("\nEmployee found:\n");
                    printf("ID\tName\tDepartment\tSalary\n");
                    printf("%d\t%s\t%s\t%.2f\n", database[i].id, database[i].name, database[i].department, database[i].salary);
                }
                if(i == 4) {
                    printf("\nNo employees found in the %s department\n", employee_department);
                }
            }
        }
        else if(choice == 5) {
            printf("\nThank you for using the Employee Database Query Program!\n");
            break;
        }
        else {
            printf("\nInvalid option selected, please try again\n");
        }
    }
    return 0;
}