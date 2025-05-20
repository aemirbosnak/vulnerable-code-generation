//Falcon-180B DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

Employee* readEmployees(int* count) {
    FILE* file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    Employee* employees = (Employee*)malloc(*count * sizeof(Employee));
    int i = 0;

    while (fscanf(file, "%s %d %f", employees[i].name, &employees[i].age, &employees[i].salary)!= EOF) {
        i++;
        (*count)++;
    }

    fclose(file);
    return employees;
}

void writeEmployees(Employee* employees, int count) {
    FILE* file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    fclose(file);
}

void sortEmployees(Employee* employees, int count, int (*compare)(const void*, const void*)) {
    qsort(employees, count, sizeof(Employee), compare);
}

int compareByAge(const void* a, const void* b) {
    const Employee* employeeA = (const Employee*)a;
    const Employee* employeeB = (const Employee*)b;

    return employeeA->age - employeeB->age;
}

int main() {
    int count = 0;
    Employee* employees = readEmployees(&count);

    sortEmployees(employees, count, compareByAge);

    writeEmployees(employees, count);

    free(employees);
    return 0;
}