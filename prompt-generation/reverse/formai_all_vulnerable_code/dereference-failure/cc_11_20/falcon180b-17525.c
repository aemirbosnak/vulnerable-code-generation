//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char delimiter = ',';
    Employee *employees = NULL;
    int num_employees = 0;

    fp = fopen("employees.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, &delimiter);
        if (token == NULL) {
            continue;
        }
        num_employees++;
        rewind(fp);
        employees = realloc(employees, sizeof(Employee) * num_employees);
        if (employees == NULL) {
            printf("Error allocating memory.\n");
            exit(1);
        }
        int i = 0;
        while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
            char *token = strtok(line, &delimiter);
            if (token == NULL) {
                continue;
            }
            switch (i) {
                case 0:
                    employees[num_employees - 1].name = strdup(token);
                    break;
                case 1:
                    employees[num_employees - 1].age = atoi(token);
                    break;
                case 2:
                    employees[num_employees - 1].salary = atof(token);
                    break;
                default:
                    break;
            }
            i++;
        }
    }

    fclose(fp);

    printf("Number of employees: %d\n", num_employees);
    for (int i = 0; i < num_employees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: $%.2f\n", employees[i].salary);
        printf("\n");
    }

    free(employees);
    return 0;
}