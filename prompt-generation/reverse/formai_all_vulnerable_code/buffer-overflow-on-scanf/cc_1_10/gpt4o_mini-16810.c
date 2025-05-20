//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_JOB_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char job[MAX_JOB_LENGTH];
    float salary;
} Employee;

typedef struct {
    Employee employees[MAX_ENTRIES];
    int count;
} EmployeeDatabase;

// Function prototypes
void addEmployee(EmployeeDatabase *db);
void displayEmployees(const EmployeeDatabase *db);
void findHighestPaidEmployee(const EmployeeDatabase *db);
void findLowestPaidEmployee(const EmployeeDatabase *db);
void findAverageSalary(const EmployeeDatabase *db);

// Main function
int main() {
    EmployeeDatabase db;
    db.count = 0;
    int choice;
    
    while (1) {
        printf("\n");
        printf("=== Employee Database Menu ===\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Find Highest Paid Employee\n");
        printf("4. Find Lowest Paid Employee\n");
        printf("5. Calculate Average Salary\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(&db);
                break;
            case 2:
                displayEmployees(&db);
                break;
            case 3:
                findHighestPaidEmployee(&db);
                break;
            case 4:
                findLowestPaidEmployee(&db);
                break;
            case 5:
                findAverageSalary(&db);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add an employee to the database
void addEmployee(EmployeeDatabase *db) {
    if (db->count >= MAX_ENTRIES) {
        printf("Database is full. Cannot add more employees.\n");
        return;
    }

    Employee newEmployee;
    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Enter Employee Name: ");
    getchar(); // To consume the newline character left by scanf
    fgets(newEmployee.name, MAX_NAME_LENGTH, stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = 0; // Remove the newline character
    printf("Enter Employee Job: ");
    fgets(newEmployee.job, MAX_JOB_LENGTH, stdin);
    newEmployee.job[strcspn(newEmployee.job, "\n")] = 0; // Remove the newline character
    printf("Enter Employee Salary: ");
    scanf("%f", &newEmployee.salary);

    db->employees[db->count++] = newEmployee;
    printf("Employee added successfully!\n");
}

// Function to display all employees in the database
void displayEmployees(const EmployeeDatabase *db) {
    if (db->count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n=== Employee List ===\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Job: %s, Salary: %.2f\n", 
                db->employees[i].id, 
                db->employees[i].name, 
                db->employees[i].job, 
                db->employees[i].salary);
    }
}

// Function to find and display the highest paid employee
void findHighestPaidEmployee(const EmployeeDatabase *db) {
    if (db->count == 0) {
        printf("No employees to evaluate.\n");
        return;
    }

    Employee highestPaid = db->employees[0];
    for (int i = 1; i < db->count; i++) {
        if (db->employees[i].salary > highestPaid.salary) {
            highestPaid = db->employees[i];
        }
    }

    printf("Highest Paid Employee: ID: %d, Name: %s, Job: %s, Salary: %.2f\n", 
            highestPaid.id, 
            highestPaid.name, 
            highestPaid.job, 
            highestPaid.salary);
}

// Function to find and display the lowest paid employee
void findLowestPaidEmployee(const EmployeeDatabase *db) {
    if (db->count == 0) {
        printf("No employees to evaluate.\n");
        return;
    }

    Employee lowestPaid = db->employees[0];
    for (int i = 1; i < db->count; i++) {
        if (db->employees[i].salary < lowestPaid.salary) {
            lowestPaid = db->employees[i];
        }
    }

    printf("Lowest Paid Employee: ID: %d, Name: %s, Job: %s, Salary: %.2f\n", 
            lowestPaid.id, 
            lowestPaid.name, 
            lowestPaid.job, 
            lowestPaid.salary);
}

// Function to calculate and display the average salary of employees
void findAverageSalary(const EmployeeDatabase *db) {
    if (db->count == 0) {
        printf("No employees to evaluate.\n");
        return;
    }

    float totalSalary = 0;
    for (int i = 0; i < db->count; i++) {
        totalSalary += db->employees[i].salary;
    }

    float averageSalary = totalSalary / db->count;
    printf("Average Salary: %.2f\n", averageSalary);
}