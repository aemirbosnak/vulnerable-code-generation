//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Employee;

int main() {
    Employee employees[50];
    int numEmployees = 0;
    char input[100];
    int inputLength;
    int id;
    char name[20];
    char ageString[3];
    int age;
    char salaryString[10];
    float salary;

    while (1) {
        printf("1: Add an employee\n");
        printf("2: Search for an employee\n");
        printf("3: Display all employees\n");
        printf("4: Quit\n");
        printf("Enter your choice: ");

        fgets(input, 100, stdin);
        inputLength = strlen(input);
        if (input[inputLength-1] == '\n') {
            input[inputLength-1] = '\0';
        }

        switch (atoi(input)) {
            case 1:
                printf("Enter employee id: ");
                fgets(input, 100, stdin);
                id = atoi(input);

                printf("Enter employee name: ");
                fgets(name, 20, stdin);
                name[strlen(name)-1] = '\0';

                printf("Enter employee age: ");
                fgets(ageString, 3, stdin);
                age = atoi(ageString);

                printf("Enter employee salary: ");
                fgets(salaryString, 10, stdin);
                salaryString[strlen(salaryString)-1] = '\0';
                salary = atof(salaryString);

                Employee newEmployee = {.id=id, .age=age, .salary=salary};
                strcpy(newEmployee.name, name);

                employees[numEmployees] = newEmployee;
                numEmployees++;

                printf("Employee added successfully.\n");
                break;
            case 2:
                printf("Enter employee id: ");
                fgets(input, 100, stdin);
                id = atoi(input);

                for (int i = 0; i < numEmployees; i++) {
                    if (employees[i].id == id) {
                        printf("ID: %d\n", employees[i].id);
                        printf("Name: %s\n", employees[i].name);
                        printf("Age: %d\n", employees[i].age);
                        printf("Salary: %.2f\n", employees[i].salary);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < numEmployees; i++) {
                    printf("ID: %d\n", employees[i].id);
                    printf("Name: %s\n", employees[i].name);
                    printf("Age: %d\n", employees[i].age);
                    printf("Salary: %.2f\n", employees[i].salary);
                    printf("\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}