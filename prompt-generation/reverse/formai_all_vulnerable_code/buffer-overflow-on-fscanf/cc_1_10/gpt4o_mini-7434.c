//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

// Structure for storing the record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

// Function prototypes
void loadData(Employee employees[], int *count);
void displayData(const Employee employees[], int count);
void findHighestSalary(const Employee employees[], int count);
void findAverageAge(const Employee employees[], int count);

int main() {
    Employee employees[MAX_RECORDS];
    int count = 0;

    // Load data from file
    loadData(employees, &count);
    
    // Display all records
    printf("All Employee Records:\n");
    displayData(employees, count);
    
    // Find employee with the highest salary
    findHighestSalary(employees, count);
    
    // Find average age of employees
    findAverageAge(employees, count);
    
    return 0;
}

// Function to load data from the file "employees.txt"
void loadData(Employee employees[], int *count) {
    FILE *file = fopen("employees.txt", "r");
    if (!file) {
        printf("Error: Cannot open file!\n");
        exit(1);
    }

    while (fscanf(file, "%s %d %f", employees[*count].name, &employees[*count].age, &employees[*count].salary) != EOF && *count < MAX_RECORDS) {
        (*count)++;
    }
    fclose(file);
}

// Function to display all employee records
void displayData(const Employee employees[], int count) {
    printf("%-20s %-5s %-10s\n", "Name", "Age", "Salary");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-10.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
}

// Function to find and display the employee with the highest salary
void findHighestSalary(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employee data available.\n");
        return;
    }

    float highestSalary = employees[0].salary;
    int index = 0;

    for (int i = 1; i < count; i++) {
        if (employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            index = i;
        }
    }

    printf("\nEmployee with the highest salary:\n");
    printf("Name: %s, Age: %d, Salary: %.2f\n", employees[index].name, employees[index].age, employees[index].salary);
}

// Function to find and display the average age of employees
void findAverageAge(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employee data available to calculate average age.\n");
        return;
    }

    int totalAge = 0;

    for (int i = 0; i < count; i++) {
        totalAge += employees[i].age;
    }

    float averageAge = (float)totalAge / count;
    printf("\nAverage age of employees: %.2f\n", averageAge);
}