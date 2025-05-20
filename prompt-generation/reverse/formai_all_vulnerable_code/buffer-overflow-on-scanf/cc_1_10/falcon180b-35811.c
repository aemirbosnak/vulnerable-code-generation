//Falcon-180B DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the data
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    float salary;
} employee;

// Function to compare two employees based on their salary
int compare(const void *a, const void *b) {
    employee *emp1 = (employee *)a;
    employee *emp2 = (employee *)b;
    if (emp1->salary > emp2->salary)
        return 1;
    else if (emp1->salary < emp2->salary)
        return -1;
    else
        return 0;
}

// Function to perform data mining
void dataMining(employee *emp, int n) {
    // Sort the employees based on their salary
    qsort(emp, n, sizeof(employee), compare);

    // Print the highest paid employee
    printf("The highest paid employee is:\n");
    printf("ID: %d\n", emp[0].id);
    printf("Name: %s\n", emp[0].name);
    printf("Age: %d\n", emp[0].age);
    printf("Gender: %s\n", emp[0].gender);
    printf("Salary: $%.2f\n\n", emp[0].salary);

    // Print the average salary of all employees
    float avgSalary = 0;
    for (int i = 0; i < n; i++) {
        avgSalary += emp[i].salary;
    }
    avgSalary /= n;
    printf("The average salary of all employees is: $%.2f\n", avgSalary);
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Allocate memory for the employees
    employee *emp = (employee *)malloc(n * sizeof(employee));

    // Read the employee data
    for (int i = 0; i < n; i++) {
        printf("Enter the data for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Age: ");
        scanf("%d", &emp[i].age);
        printf("Gender: ");
        scanf("%s", emp[i].gender);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Perform data mining
    dataMining(emp, n);

    return 0;
}