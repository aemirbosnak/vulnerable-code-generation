//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void read_employees(Employee *employees, int size) {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d %f\n", employees[count].name, &employees[count].age, &employees[count].salary)!= EOF) {
        count++;
    }

    fclose(fp);
}

void write_employees(Employee *employees, int size) {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %d %f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    fclose(fp);
}

void display_employees(Employee *employees, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %d $%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main() {
    Employee employees[100];
    int size = 0;

    read_employees(employees, size);
    display_employees(employees, size);

    printf("Enter the number of employees to add:\n");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter the name of employee %d:\n", i+1);
        scanf("%s", employees[i].name);
        printf("Enter the age of employee %s:\n", employees[i].name);
        scanf("%d", &employees[i].age);
        printf("Enter the salary of employee %s:\n", employees[i].name);
        scanf("%f", &employees[i].salary);
    }

    write_employees(employees, size);
    printf("Data saved to file!\n");

    return 0;
}