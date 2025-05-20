//FormAI DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float salary;
    int age;
} Employee;

void printEmployee(Employee emp) {
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Age: %d\n\n", emp.age);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee* employees = malloc(n * sizeof(Employee));

    for (int i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &(employees+i)->id);
        printf("Name: ");
        scanf("%s", (employees+i)->name);
        printf("Salary: ");
        scanf("%f", &(employees+i)->salary);
        printf("Age: ");
        scanf("%d", &(employees+i)->age);
    }

    printf("\nAll Employees:\n\n");
    for (int i = 0; i < n; i++) {
        printEmployee(*(employees+i));
    }

    float averageSalary = 0;
    for (int i = 0; i < n; i++) {
        averageSalary += (employees+i)->salary;
    }
    averageSalary /= n;
    printf("Average Salary: %.2f\n", averageSalary);

    int oldestEmployeeIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((employees+i)->age > (employees+oldestEmployeeIndex)->age) {
            oldestEmployeeIndex = i;
        }
    }
    printf("Oldest Employee: %s\n", (employees+oldestEmployeeIndex)->name);

    free(employees);
    return 0;
}