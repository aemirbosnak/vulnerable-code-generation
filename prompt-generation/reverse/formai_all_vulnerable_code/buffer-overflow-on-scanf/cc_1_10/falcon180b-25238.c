//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float salary;
} Employee;

void addEmployee(Employee* employees, int size, char* name, int age, float salary) {
    if (size == MAX_SIZE) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(employees[size].name, name);
    employees[size].age = age;
    employees[size].salary = salary;

    printf("Employee added successfully.\n");
}

void searchEmployee(Employee* employees, int size, char* name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Employee found:\n");
            printf("Name: %s\n", employees[i].name);
            printf("Age: %d\n", employees[i].age);
            printf("Salary: $%.2f\n", employees[i].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

void main() {
    Employee employees[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("1. Add employee\n");
        printf("2. Search employee\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter employee name: ");
            char name[MAX_SIZE];
            scanf("%s", name);

            printf("Enter employee age: ");
            int age;
            scanf("%d", &age);

            printf("Enter employee salary: ");
            float salary;
            scanf("%f", &salary);

            addEmployee(employees, size, name, age, salary);
            break;

        case 2:
            printf("Enter employee name to search: ");
            char searchName[MAX_SIZE];
            scanf("%s", searchName);

            searchEmployee(employees, size, searchName);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}