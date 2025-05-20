//FormAI DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

int main() {

    // Create an array of Employee structures
    Employee employees[10];

    // Initialize the array with dummy data
    strcpy(employees[0].name, "John");
    employees[0].age = 22;
    employees[0].salary = 30000.00;
    strcpy(employees[1].name, "Emily");
    employees[1].age = 27;
    employees[1].salary = 40000.00;
    strcpy(employees[2].name, "David");
    employees[2].age = 30;
    employees[2].salary = 50000.00;
    strcpy(employees[3].name, "Sarah");
    employees[3].age = 35;
    employees[3].salary = 60000.00;
    strcpy(employees[4].name, "Alice");
    employees[4].age = 40;
    employees[4].salary = 70000.00;
    strcpy(employees[5].name, "Bob");
    employees[5].age = 45;
    employees[5].salary = 80000.00;
    strcpy(employees[6].name, "Karen");
    employees[6].age = 50;
    employees[6].salary = 90000.00;
    strcpy(employees[7].name, "Jack");
    employees[7].age = 55;
    employees[7].salary = 100000.00;
    strcpy(employees[8].name, "Olivia");
    employees[8].age = 60;
    employees[8].salary = 110000.00;
    strcpy(employees[9].name, "Lucas");
    employees[9].age = 65;
    employees[9].salary = 120000.00;

    // Ask the user for a query condition
    printf("Enter an age threshold: ");
    int age_threshold;
    scanf("%d", &age_threshold);

    // Print out all employees that match the query
    printf("Employees that are %d years old or older:\n", age_threshold);
    for (int i = 0; i < 10; i++) {
        if (employees[i].age >= age_threshold) {
            printf("Name: %s, Age: %d, Salary: $%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
        }
    }

    return 0;
}