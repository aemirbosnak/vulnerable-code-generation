//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    int emp_id;
    char name[30];
    int age;
    float salary;
} employee;

void save_employee_database(employee *emp, int num_emp) {
    FILE *fp;
    fp = fopen("employee_database.txt", "w");
    for (int i = 0; i < num_emp; i++) {
        fprintf(fp, "%d %s %d %.2f\n", emp[i].emp_id, emp[i].name, emp[i].age, emp[i].salary);
    }
    fclose(fp);
}

void retrieve_employee_database() {
    FILE *fp;
    int emp_id, age;
    char name[30];
    float salary;

    fp = fopen("employee_database.txt", "r");
    if (fp == NULL) {
        printf("No employee found!");
        return;
    }

    printf("%-10s%-20s%-10s%-10s\n", "Emp ID", "Name", "Age", "Salary");
    printf("-------------------------------------------\n");
    while (fscanf(fp, "%d %s %d %f", &emp_id, name, &age, &salary) != EOF) {
        printf("%-10d%-20s%-10d%-10.2f\n", emp_id, name, age, salary);
    }

    fclose(fp);
}

int main() {
    int num_emp;
    printf("Enter the number of employees: ");
    scanf("%d", &num_emp);

    employee *emp_list = malloc(sizeof(employee) * num_emp);

    for (int i = 0; i < num_emp; i++) {
        printf("\nEmployee %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp_list[i].emp_id);
        printf("Name: ");
        scanf("%s", &emp_list[i].name);
        printf("Age: ");
        scanf("%d", &emp_list[i].age);
        printf("Salary: ");
        scanf("%f", &emp_list[i].salary);
    }

    save_employee_database(emp_list, num_emp);

    printf("\nAll employees saved successfully!\n");

    retrieve_employee_database();

    free(emp_list);
    return 0;
}