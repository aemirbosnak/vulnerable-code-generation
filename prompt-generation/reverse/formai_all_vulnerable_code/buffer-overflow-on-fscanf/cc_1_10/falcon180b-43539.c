//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    Employee employees[MAX_SIZE];
    int num_employees = 0;

    FILE* fp = fopen("employees.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %f\n", &employees[num_employees].id, employees[num_employees].name, &employees[num_employees].salary)!= EOF) {
        num_employees++;
    }

    fclose(fp);

    int choice;
    char name_to_search[50];

    do {
        printf("Enter the ID of the employee you want to search for: ");
        scanf("%d", &choice);

        for (int i = 0; i < num_employees; i++) {
            if (employees[i].id == choice) {
                printf("Name: %s\nSalary: $%.2f\n", employees[i].name, employees[i].salary);
            }
        }

        printf("Do you want to search for another employee? (y/n): ");
        scanf(" %c", &name_to_search);

    } while (name_to_search == 'y' || name_to_search == 'Y');

    return 0;
}