//Falcon-180B DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp;
    Employee emp[MAX_ROWS];
    int num_rows = 0;
    char query[1000];

    fp = fopen("employees.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read header line
    fgets(query, sizeof(query), fp);

    // Read data lines
    while (fgets(query, sizeof(query), fp)!= NULL) {
        if (num_rows >= MAX_ROWS) {
            printf("Max rows exceeded\n");
            break;
        }

        char *token = strtok(query, ",");
        emp[num_rows].name = strdup(token);

        token = strtok(NULL, ",");
        emp[num_rows].age = atoi(token);

        token = strtok(NULL, ",");
        emp[num_rows].salary = atof(token);

        num_rows++;
    }

    fclose(fp);

    // Query 1: Find employees with salary greater than 50000
    int count1 = 0;
    for (int i = 0; i < num_rows; i++) {
        if (emp[i].salary > 50000) {
            printf("Employee %d: %s, %d years old, salary $%.2f\n", i+1, emp[i].name, emp[i].age, emp[i].salary);
            count1++;
        }
    }
    printf("Total employees with salary > 50000: %d\n\n", count1);

    // Query 2: Find employees with age between 25 and 30
    int count2 = 0;
    for (int i = 0; i < num_rows; i++) {
        if (emp[i].age >= 25 && emp[i].age <= 30) {
            printf("Employee %d: %s, %d years old, salary $%.2f\n", i+1, emp[i].name, emp[i].age, emp[i].salary);
            count2++;
        }
    }
    printf("Total employees with age between 25 and 30: %d\n", count2);

    return 0;
}