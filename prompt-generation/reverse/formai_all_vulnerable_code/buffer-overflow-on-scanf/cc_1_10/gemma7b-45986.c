//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
typedef struct Employee {
    char name[50];
    int id;
    float salary;
} Employee;

// Function to insert an employee into the database
void insertEmployee(Employee *emp) {
    // Allocate memory for the employee
    emp = (Employee *)malloc(sizeof(Employee));

    // Get the employee's name, id, and salary
    printf("Enter employee name: ");
    scanf("%s", emp->name);

    printf("Enter employee id: ");
    scanf("%d", &emp->id);

    printf("Enter employee salary: ");
    scanf("%f", &emp->salary);

    // Add the employee to the database
    // (In a real-world application, this would be done by inserting the employee into a database)
}

// Function to display all employees in the database
void displayEmployees(Employee *emp) {
    // Iterate over the database and print each employee's information
    for (emp = emp; emp->name[0] != '\0'; emp++) {
        printf("Name: %s\n", emp->name);
        printf("ID: %d\n", emp->id);
        printf("Salary: %.2f\n", emp->salary);
        printf("\n");
    }
}

int main() {
    // Create an employee database
    Employee *emp = NULL;

    // Insert an employee into the database
    insertEmployee(emp);

    // Display all employees in the database
    displayEmployees(emp);

    return 0;
}