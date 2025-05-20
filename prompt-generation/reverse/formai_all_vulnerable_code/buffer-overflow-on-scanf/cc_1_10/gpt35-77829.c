//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    double salary;
} Employee;

int main() {
    FILE *fp;
    int num_employees;
    Employee *employees;

    // Get number of employees from user
    printf("Enter number of employees: ");
    scanf("%d", &num_employees);

    // Allocate memory for employees
    employees = (Employee*)malloc(num_employees * sizeof(Employee));

    // Get employee details from user and store in employees array
    for (int i = 0; i < num_employees; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }

    // Write employee details to file
    fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }
    fwrite(employees, sizeof(Employee), num_employees, fp);
    fclose(fp);

    // Free employees memory
    free(employees);

    // Read employee details from file and print to console
    Employee e;
    fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }
    printf("\nEmployee Details:\n\n");
    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("Name: %s\n", e.name);
        printf("Age: %d\n", e.age);
        printf("Salary: %.2lf\n", e.salary);
        printf("\n");
    }
    fclose(fp);

    return 0;
}