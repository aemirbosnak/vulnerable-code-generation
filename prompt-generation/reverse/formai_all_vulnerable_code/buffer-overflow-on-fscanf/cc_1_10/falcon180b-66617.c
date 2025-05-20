//Falcon-180B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
    float salary;
} Employee;

void main() {
    int numEmployees = 0;
    Employee *employees = NULL;

    // Allocate memory for employees
    employees = (Employee *) malloc(numEmployees * sizeof(Employee));

    // Read in employee data
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %f", employees[numEmployees].name, &employees[numEmployees].age, &employees[numEmployees].salary)!= EOF) {
        numEmployees++;
        employees = (Employee *) realloc(employees, numEmployees * sizeof(Employee));
    }

    fclose(fp);

    // Sort employees by age
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = i + 1; j < numEmployees; j++) {
            if (employees[j].age < employees[i].age) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    // Print out employee data
    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s\nAge: %d\nSalary: $%.2f\n\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    // Free memory
    for (int i = 0; i < numEmployees; i++) {
        free(employees[i].name);
    }
    free(employees);
}