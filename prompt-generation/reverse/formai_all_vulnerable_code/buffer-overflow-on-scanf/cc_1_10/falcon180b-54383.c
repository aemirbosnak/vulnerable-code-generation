//Falcon-180B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

void createEmployees(Employee* emp, int count) {
    for (int i = 0; i < count; i++) {
        sprintf(emp[i].name, "Employee %d", i + 1);
        emp[i].age = i + 20;
        emp[i].salary = i * 1000;
    }
}

void printEmployees(Employee* emp, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", emp[i].name, emp[i].age, emp[i].salary);
    }
}

int main() {
    Employee* emp = (Employee*) malloc(SIZE * sizeof(Employee));
    if (emp == NULL) {
        printf("Memory error!\n");
        return 1;
    }

    int count = 0;
    while (1) {
        printf("Enter the number of employees (0 to quit): ");
        scanf("%d", &count);

        if (count == 0) {
            break;
        }

        if (count > SIZE) {
            printf("Not enough memory!\n");
            break;
        }

        createEmployees(emp, count);
        printEmployees(emp, count);
    }

    free(emp);
    return 0;
}