//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

int main() {
    int num_of_employees;
    printf("Enter number of employees: ");
    scanf("%d", &num_of_employees);

    Employee *employees = (Employee*) malloc(num_of_employees * sizeof(Employee));

    if (!employees) {
        fprintf(stderr, "Memory allocation error!");
        exit(1);
    }

    FILE *file = fopen("employees.dat", "wb");
    if (!file) {
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    for (int i = 0; i < num_of_employees; i++) {
        printf("Enter name, age and salary for employee %d: ", i+1);
        scanf("%s %d %f", employees[i].name, &employees[i].age, &employees[i].salary);
    }

    fwrite(employees, sizeof(Employee), num_of_employees, file);

    fclose(file);
    free(employees);

    file = fopen("employees.dat", "rb");
    if (!file) {
        fprintf(stderr, "Error opening file!");
        exit(1);
    }

    Employee *read_employees = (Employee*) malloc(num_of_employees * sizeof(Employee));

    if (!read_employees) {
        fprintf(stderr, "Memory allocation error!");
        exit(1);
    }

    fread(read_employees, sizeof(Employee), num_of_employees, file);

    for (int i = 0; i < num_of_employees; i++) {
        printf("Name: %s\n", read_employees[i].name);
        printf("Age: %d\n", read_employees[i].age);
        printf("Salary: %.2f\n", read_employees[i].salary);
    }

    fclose(file);
    free(read_employees);

    return 0;
}