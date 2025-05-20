//Falcon-180B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

void read_csv(char* filename, Employee* employees) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int row_count = 0;
    while (row_count < MAX_ROWS && fscanf(fp, "%d,%s,%d,%f\n", &employees[row_count].id, employees[row_count].name, &employees[row_count].age, &employees[row_count].salary)!= EOF) {
        row_count++;
    }

    fclose(fp);
}

void print_employees(Employee* employees, int start_row, int end_row) {
    for (int i = start_row; i <= end_row; i++) {
        printf("%d - %s (%d years old) - Salary: $%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

void sort_by_age(Employee* employees) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = i + 1; j < MAX_ROWS; j++) {
            if (employees[i].age > employees[j].age) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

int main() {
    Employee employees[MAX_ROWS];

    read_csv("employees.csv", employees);

    int num_employees = 0;
    while (num_employees < MAX_ROWS && employees[num_employees].id!= 0) {
        num_employees++;
    }

    printf("Total number of employees: %d\n", num_employees);

    int choice;
    do {
        printf("1. Sort by age\n");
        printf("2. Print employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sort_by_age(employees);
                printf("Employees sorted by age:\n");
                print_employees(employees, 0, num_employees - 1);
                break;
            case 2:
                printf("Employees:\n");
                print_employees(employees, 0, num_employees - 1);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}