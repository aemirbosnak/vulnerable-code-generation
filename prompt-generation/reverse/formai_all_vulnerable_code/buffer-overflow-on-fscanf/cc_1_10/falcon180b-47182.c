//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void read_file(Employee* employees, int count) {
    FILE* file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %d %f\n", employees[i].name, &employees[i].age, &employees[i].salary)!= EOF) {
        i++;
    }

    fclose(file);
}

void write_file(Employee* employees, int count) {
    FILE* file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    fclose(file);
}

void display_employees(Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main() {
    Employee employees[100];
    int count = 0;

    read_file(employees, count);

    display_employees(employees, count);

    return 0;
}