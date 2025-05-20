//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    float salary;
    int age;
} Employee;

Employee employees[5] = {{101, "John", 50000.0, 28},
                         {102, "Jane", 55000.0, 35},
                         {103, "Kevin", 70000.0, 42},
                         {104, "Marie", 45000.0, 24},
                         {105, "Peter", 60000.0, 30}};

int main() {
    bool valid_query = false;
    int choice;
    printf("Welcome to the employee database query program!\n");

    // loop until the user inputs a valid query
    while (!valid_query) {
        printf("\nWhat would you like to do?");
        printf("\n1. Display all employees");
        printf("\n2. Search employees by name");
        printf("\n3. Search employees by salary range");
        printf("\n4. Search employees by age range");
        printf("\n\nPlease choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // display all employees
                printf("\n=== All Employees ===\n");
                printf("ID\tName\tSalary\tAge\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d\t%s\t%.2f\t%d\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].age);
                }
                valid_query = true;
                break;

            case 2: // search employees by name
                printf("\nEnter the employee name: ");
                char name[30];
                scanf("%s", name);
                printf("\n=== Employees with name \"%s\" ===\n", name);
                printf("ID\tName\tSalary\tAge\n");
                for (int i = 0; i < 5; i++) {
                    if (strcmp(employees[i].name, name) == 0) {
                        printf("%d\t%s\t%.2f\t%d\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].age);
                    }
                }
                valid_query = true;
                break;

            case 3: // search employees by salary range
                printf("\nEnter the minimum salary: ");
                float min_salary;
                scanf("%f", &min_salary);
                printf("\nEnter the maximum salary: ");
                float max_salary;
                scanf("%f", &max_salary);
                printf("\n=== Employees with salary between %.2f and %.2f ===\n", min_salary, max_salary);
                printf("ID\tName\tSalary\tAge\n");
                for (int i = 0; i < 5; i++) {
                    if (employees[i].salary >= min_salary && employees[i].salary <= max_salary) {
                        printf("%d\t%s\t%.2f\t%d\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].age);
                    }
                }
                valid_query = true;
                break;

            case 4: // search employees by age range
                printf("\nEnter the minimum age: ");
                int min_age;
                scanf("%d", &min_age);
                printf("\nEnter the maximum age: ");
                int max_age;
                scanf("%d", &max_age);
                printf("\n=== Employees with age between %d and %d ===\n", min_age, max_age);
                printf("ID\tName\tSalary\tAge\n");
                for (int i = 0; i < 5; i++) {
                    if (employees[i].age >= min_age && employees[i].age <= max_age) {
                        printf("%d\t%s\t%.2f\t%d\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].age);
                    }
                }
                valid_query = true;
                break;

            default: // invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}