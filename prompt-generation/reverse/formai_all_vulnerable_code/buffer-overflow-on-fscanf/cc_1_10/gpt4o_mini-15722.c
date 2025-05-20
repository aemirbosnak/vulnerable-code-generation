//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define FILE_NAME "employees.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    float salary;
} Employee;

int employeeCount = 0;

// Function Declarations
void addEmployee();
void viewEmployees();
void deleteEmployee();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile();
    
    do {
        printf("\n=== Employee Database ===\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                saveToFile();
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to add a new employee
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return;
    }

    Employee newEmployee;
    newEmployee.id = employeeCount + 1; // Assign ID based on count
    printf("Enter Employee Name: ");
    scanf("%s", newEmployee.name);
    printf("Enter Employee Age: ");
    scanf("%d", &newEmployee.age);
    printf("Enter Employee Salary: ");
    scanf("%f", &newEmployee.salary);

    // Add employee to the list
    employeeCount++;
    FILE *file = fopen(FILE_NAME, "a");
    if (file != NULL) {
        fprintf(file, "%d %s %d %.2f\n", newEmployee.id, newEmployee.name, newEmployee.age, newEmployee.salary);
        fclose(file);
        printf("Employee added successfully!\n");
    } else {
        printf("Error opening file for writing!\n");
    }
}

// Function to view all employees
void viewEmployees() {
    printf("\n=== Employee List ===\n");
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    Employee emp;
    while (fscanf(file, "%d %s %d %f", &emp.id, emp.name, &emp.age, &emp.salary) != EOF) {
        printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", emp.id, emp.name, emp.age, emp.salary);
    }
    fclose(file);
}

// Function to delete an employee
void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    Employee emp;
    int found = 0;
    while (fscanf(file, "%d %s %d %f", &emp.id, emp.name, &emp.age, &emp.salary) != EOF) {
        if (emp.id != id) {
            fprintf(tempFile, "%d %s %d %.2f\n", emp.id, emp.name, emp.age, emp.salary);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        employeeCount--;
        printf("Employee ID %d deleted successfully!\n", id);
    } else {
        remove("temp.txt");
        printf("Employee ID %d not found.\n", id);
    }
}

// Function to save employees to a file
void saveToFile() {
    // This is handled when adding employees, so nothing to do here currently
}

// Function to load employees from a file
void loadFromFile() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // If file doesn't exist, assume no employees
    }

    Employee emp;
    while (fscanf(file, "%d %s %d %f", &emp.id, emp.name, &emp.age, &emp.salary) != EOF) {
        employeeCount++;
    }
    fclose(file);
}