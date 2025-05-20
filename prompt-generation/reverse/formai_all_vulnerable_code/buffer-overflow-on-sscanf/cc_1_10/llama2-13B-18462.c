//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MAX_SALARY 100000

struct employee {
    char name[MAX_NAME_LEN];
    int age;
    double salary;
};

int main() {
    struct employee emp[5];
    int i, j;
    char input[100];

    // Initialize employee data
    for (i = 0; i < 5; i++) {
        emp[i].name[0] = '\0';
        emp[i].age = 0;
        emp[i].salary = 0.0;
    }

    // Ask user for employee data
    printf("Enter employee data (name, age, salary): ");
    for (i = 0; i < 5; i++) {
        fgets(input, 100, stdin);
        sscanf(input, "%s %d %lf", emp[i].name, &emp[i].age, &emp[i].salary);
    }

    // Display employee data
    printf("Employees:\n");
    for (i = 0; i < 5; i++) {
        printf(" %s (%d), salary: %lf\n", emp[i].name, emp[i].age, emp[i].salary);
    }

    // Calculate and display average salary
    double avg_salary = 0;
    for (i = 0; i < 5; i++) {
        avg_salary += emp[i].salary;
    }
    avg_salary /= 5;
    printf("Average salary: %lf\n", avg_salary);

    // Ask user to enter a name and calculate the number of employees with that name
    printf("Enter a name: ");
    fgets(input, 100, stdin);
    int count = 0;
    for (i = 0; i < 5; i++) {
        if (strcmp(emp[i].name, input) == 0) {
            count++;
        }
    }
    printf("Number of employees with %s: %d\n", input, count);

    // Ask user to enter a salary range and display employees with that salary range
    double min_salary, max_salary;
    printf("Enter minimum and maximum salary (separated by space): ");
    fgets(input, 100, stdin);
    sscanf(input, "%lf %lf", &min_salary, &max_salary);
    for (i = 0; i < 5; i++) {
        if (emp[i].salary >= min_salary && emp[i].salary <= max_salary) {
            printf("Employee %s (%d) has salary: %lf\n", emp[i].name, emp[i].age, emp[i].salary);
        }
    }

    return 0;
}