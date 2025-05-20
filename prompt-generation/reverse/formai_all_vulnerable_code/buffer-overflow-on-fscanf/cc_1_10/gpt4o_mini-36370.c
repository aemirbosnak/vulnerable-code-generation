//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 255

// Data structure to hold a single entry of data
typedef struct {
    char name[MAX_LENGTH];
    int age;
    float salary;
} Employee;

// Function declarations
void addEmployee(Employee *employees, int *count);
void displayEmployees(const Employee *employees, int count);
void averageSalary(const Employee *employees, int count);
void saveToFile(const Employee *employees, int count);
void loadFromFile(Employee *employees, int *count);

int main() {
    Employee employees[MAX_RECORDS];
    int count = 0;
    int choice;

    // Load existing employees from file
    loadFromFile(employees, &count);
    
    do {
        printf("\n*** Employee Data Management ***\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Calculate Average Salary\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                averageSalary(employees, count);
                break;
            case 4:
                saveToFile(employees, count);
                break;
            case 5:
                loadFromFile(employees, &count);
                break;
            case 6:
                printf("Exiting the program... Bye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 6);

    return 0;
}

// Function to add a new employee
void addEmployee(Employee *employees, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Employee limit reached! Cannot add more.\n");
        return;
    }
    
    printf("Enter employee name: ");
    scanf("%s", employees[*count].name);
    printf("Enter employee age: ");
    scanf("%d", &employees[*count].age);
    printf("Enter employee salary: ");
    scanf("%f", &employees[*count].salary);
    
    (*count)++;
    printf("Employee added successfully!\n");
}

// Function to display all employees
void displayEmployees(const Employee *employees, int count) {
    if (count == 0) {
        printf("No employees to display!\n");
        return;
    }
    
    printf("\n=== Employee List ===\n");
    for (int i = 0; i < count; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
    }
}

// Function to calculate the average salary
void averageSalary(const Employee *employees, int count) {
    if (count == 0) {
        printf("No employees to calculate average salary!\n");
        return;
    }
    
    float totalSalary = 0;
    for (int i = 0; i < count; i++) {
        totalSalary += employees[i].salary;
    }
    
    printf("Average Salary: %.2f\n", totalSalary / count);
}

// Function to save employee data to a file
void saveToFile(const Employee *employees, int count) {
    FILE *file = fopen("employees.dat", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    
    fclose(file);
    printf("Data saved successfully to employees.dat!\n");
}

// Function to load employee data from a file
void loadFromFile(Employee *employees, int *count) {
    FILE *file = fopen("employees.dat", "r");
    if (file == NULL) {
        printf("No existing data found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f", employees[*count].name, &employees[*count].age, &employees[*count].salary) == 3) {
        (*count)++;
    }
    
    fclose(file);
    printf("Data loaded successfully! %d records found.\n", *count);
}