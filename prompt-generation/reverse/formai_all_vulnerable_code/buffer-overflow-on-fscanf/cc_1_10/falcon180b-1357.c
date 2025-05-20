//Falcon-180B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

void read_file(Employee *employees, int *num_employees) {
    FILE *fp;
    fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    Employee temp_employee;
    while (fscanf(fp, "%s %d %f", temp_employee.name, &temp_employee.age, &temp_employee.salary)!= EOF) {
        if (*num_employees >= 200) {
            printf("Maximum number of employees reached.\n");
            exit(1);
        }
        strcpy(employees[*num_employees].name, temp_employee.name);
        employees[*num_employees].age = temp_employee.age;
        employees[*num_employees].salary = temp_employee.salary;
        (*num_employees)++;
    }

    fclose(fp);
}

void write_file(Employee *employees, int num_employees) {
    FILE *fp;
    fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < num_employees; i++) {
        fprintf(fp, "%s %d %f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    fclose(fp);
}

void search_employee(Employee *employees, int num_employees, char *name) {
    bool found = false;
    for (int i = 0; i < num_employees; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Employee found:\n");
            printf("Name: %s\n", employees[i].name);
            printf("Age: %d\n", employees[i].age);
            printf("Salary: $%.2f\n", employees[i].salary);
            found = true;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

int main() {
    Employee employees[200];
    int num_employees = 0;

    read_file(employees, &num_employees);
    write_file(employees, num_employees);

    char name[20];
    printf("Enter name to search: ");
    scanf("%s", name);
    search_employee(employees, num_employees, name);

    return 0;
}