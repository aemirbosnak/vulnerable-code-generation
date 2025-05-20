//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 10

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

int main() {
    Employee employees[MAX_ROWS];
    int num_rows = 0;
    int num_columns = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_columns);

    if (num_rows > MAX_ROWS || num_columns > MAX_COLUMNS) {
        printf("Number of rows or columns exceeds the maximum limit.\n");
        return 1;
    }

    printf("Enter employee names: ");
    for (int i = 0; i < num_rows; i++) {
        scanf("%s", employees[i].name);
    }

    printf("Enter employee ages: ");
    for (int i = 0; i < num_rows; i++) {
        scanf("%d", &employees[i].age);
    }

    printf("Enter employee salaries: ");
    for (int i = 0; i < num_rows; i++) {
        scanf("%f", &employees[i].salary);
    }

    for (int i = 0; i < num_rows; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }

    return 0;
}