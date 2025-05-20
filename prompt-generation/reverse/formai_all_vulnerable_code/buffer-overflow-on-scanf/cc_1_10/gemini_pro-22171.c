//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

int main() {
    // Create a database of employees
    Employee employees[] = {
        {"John Doe", 30, 50000},
        {"Jane Doe", 25, 40000},
        {"Peter Parker", 22, 30000},
        {"Mary Jane Watson", 20, 25000},
        {"Bruce Wayne", 40, 100000},
    };

    // Get the number of employees
    int num_employees = sizeof(employees) / sizeof(employees[0]);

    // Print the database of employees
    printf("Database of Employees:\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%s, %d, %f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    // Get the name of the employee to search for
    char name[20];
    printf("Enter the name of the employee to search for: ");
    scanf("%s", name);

    // Search for the employee
    int found = 0;
    for (int i = 0; i < num_employees; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            found = 1;
            printf("Employee found:\n");
            printf("%s, %d, %f\n", employees[i].name, employees[i].age, employees[i].salary);
            break;
        }
    }

    // If the employee was not found, print an error message
    if (!found) {
        printf("Employee not found.\n");
    }

    return 0;
}