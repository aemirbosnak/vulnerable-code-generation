//Falcon-180B DATASET v1.0 Category: File handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} EMPLOYEE;

void read_employees(EMPLOYEE *employees, int n) {
    FILE *fp;
    char filename[50] = "employees.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %d %f\n", employees[i].name, &employees[i].age, &employees[i].salary);
    }
    fclose(fp);
}

void write_employees(EMPLOYEE *employees, int n) {
    FILE *fp;
    char filename[50] = "employees.txt";
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    fclose(fp);
}

void sort_employees(EMPLOYEE *employees, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (employees[i].age > employees[j].age) {
                EMPLOYEE temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

int main() {
    EMPLOYEE employees[10];
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    read_employees(employees, n);
    sort_employees(employees, n);
    write_employees(employees, n);
    printf("Sorted employees:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    return 0;
}