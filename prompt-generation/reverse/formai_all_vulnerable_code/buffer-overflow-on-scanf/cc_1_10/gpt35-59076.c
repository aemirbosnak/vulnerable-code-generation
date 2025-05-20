//FormAI DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
  int id;
  char name[20];
  char department[20];
  float salary;
};

int main() {

    // Declare and initialize an array of employee structs
    struct employee employees[5] = {
        {105, "John", "HR", 5000.5},
        {205, "Sarah", "Finance", 7000},
        {305, "Mike", "IT", 6000},
        {405, "Emily", "Marketing", 6500.75},
        {505, "David", "Sales", 5500.25}
    };

    // Print all employee's name and salary
    printf("All Employees' Name and Salary:\n");
    for(int i = 0; i < 5; i++) {
        printf("%s: %.2f\n", employees[i].name, employees[i].salary);
    }

    // Ask user to input department name
    char dept[20];
    printf("\nPlease enter department name to see all employees in that department: ");
    scanf("%s", dept);

    // Loop through employees array and print employees in the entered department
    printf("\nEmployees in %s department:\n", dept);
    int found = 0;
    for(int i = 0; i < 5; i++) {
        if(strcmp(employees[i].department, dept) == 0) {
            printf("%s\n", employees[i].name);
            found = 1;
        }
    }

    // Check if any employees were found in the entered department
    if(found == 0) {
        printf("No employees found in %s department.", dept);
    }

    // Ask user to input the minimum salary
    float minSalary;
    printf("\n\nPlease enter minimum salary to see all employees who earn more than that: ");
    scanf("%f", &minSalary);

    // Loop through employees array and print employees who earn more than the entered salary
    printf("\nEmployees who earn more than %.2f:\n", minSalary);
    found = 0;
    for(int i = 0; i < 5; i++) {
        if(employees[i].salary > minSalary) {
            printf("%s\n", employees[i].name);
            found = 1;
        }
    }

    // Check if any employees were found who earn more than the entered salary
    if(found == 0) {
        printf("No employees found who earn more than %.2f.", minSalary);
    }

    return 0;
}