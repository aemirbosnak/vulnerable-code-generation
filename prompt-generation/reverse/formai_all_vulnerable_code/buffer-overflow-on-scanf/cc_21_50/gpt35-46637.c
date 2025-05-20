//FormAI DATASET v1.0 Category: Database simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50

typedef struct {
    int id;
    char name[MAX_SIZE];
    char department[MAX_SIZE];
    int salary;
} Employee;

int main() {
    Employee employees[MAX_SIZE];
    int employeeCount = 0;
    int id, salary, choice;
    char name[MAX_SIZE], department[MAX_SIZE];

    while (1) {
        printf("\n\nDatabase Options\n");
        printf("1. Add employee data\n");
        printf("2. Show all employees data\n");
        printf("3. Find employee by ID\n");
        printf("4. Update employee data\n");
        printf("5. Delete employee data\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &id);

                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].id == id) {
                        printf("Employee with ID already exists!");
                        goto case1_exit;
                    }
                }

                employees[employeeCount].id = id;

                printf("Enter employee name: ");
                scanf("%s", name);
                strcpy(employees[employeeCount].name, name);

                printf("Enter employee department: ");
                scanf("%s", department);
                strcpy(employees[employeeCount].department, department);

                printf("Enter employee salary: ");
                scanf("%d", &salary);
                employees[employeeCount].salary = salary;

                employeeCount++;
                printf("Employee added successfully!");
                break;

            case 2:
                if (employeeCount == 0) {
                    printf("\nNo employee records found in the database");
                    break;
                }

                printf("\nEmployee ID\tEmployee Name\tEmployee Department\tEmployee Salary\n");
                for (int i = 0; i < employeeCount; i++) {
                    printf("%d\t%s\t%s\t%d\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
                }
                break;

            case 3:
                if (employeeCount == 0) {
                    printf("\nNo employee records found in the database");
                    break;
                }

                printf("Enter employee ID: ");
                scanf("%d", &id);

                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].id == id) {
                        printf("\nEmployee Found!\n");
                        printf("\nEmployee ID\tEmployee Name\tEmployee Department\tEmployee Salary\n");
                        printf("%d\t%s\t%s\t%d\n", employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
                        goto case1_exit;
                    }
                }

                printf("\nEmployee with ID not found!");
                break;

            case 4:
                if (employeeCount == 0) {
                    printf("\nNo employee records found in the database");
                    break;
                }

                printf("Enter employee ID: ");
                scanf("%d", &id);

                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].id == id) {
                        printf("\nEmployee Found!\n");

                        printf("\nEnter employee name: ");
                        scanf("%s", name);
                        strcpy(employees[i].name, name);

                        printf("Enter employee department: ");
                        scanf("%s", department);
                        strcpy(employees[i].department, department);

                        printf("Enter employee salary: ");
                        scanf("%d", &salary);
                        employees[i].salary = salary;

                        printf("\nEmployee data updated successfully!");
                        goto case1_exit;
                    }
                }

                printf("\nEmployee with ID not found!");
                break;

            case 5:
                if (employeeCount == 0) {
                    printf("\nNo employee records found in the database");
                    break;
                }

                printf("Enter employee ID: ");
                scanf("%d", &id);

                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].id == id) {
                        employeeCount--;

                        for (int j = i; j < employeeCount; j++) {
                            employees[j] = employees[j+1];
                        }

                        printf("\nEmployee data deleted successfully!");
                        goto case1_exit;
                    }
                }

                printf("\nEmployee with ID not found!");
                break;

            case 6:
                printf("\nThank you for using the database\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please choose options from 1 to 6\n");
                break;
        }

        case1_exit:
        printf("\nPress enter to continue...");
        getchar();
        getchar();
        system("cls");
    }

    return 0;
}