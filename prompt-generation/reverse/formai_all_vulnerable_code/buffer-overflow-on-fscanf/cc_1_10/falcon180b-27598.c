//Falcon-180B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float salary;
} Employee;

void read_file(Employee *employee, FILE *file) {
    fscanf(file, "%s %d %f", employee->name, &employee->age, &employee->salary);
}

void write_file(Employee employee, FILE *file) {
    fprintf(file, "%s %d %f\n", employee.name, employee.age, employee.salary);
}

void sort_file(Employee *employees, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (employees[j].age < employees[i].age) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    Employee employees[MAX_SIZE];
    int size = 0;

    file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (!feof(file)) {
        if (size >= MAX_SIZE) {
            printf("Maximum size reached.\n");
            break;
        }

        Employee new_employee;
        read_file(&new_employee, file);

        strcpy(employees[size].name, new_employee.name);
        employees[size].age = new_employee.age;
        employees[size].salary = new_employee.salary;

        size++;
    }

    fclose(file);

    sort_file(employees, size);

    file = fopen("sorted_employees.txt", "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        write_file(employees[i], file);
    }

    fclose(file);

    return 0;
}