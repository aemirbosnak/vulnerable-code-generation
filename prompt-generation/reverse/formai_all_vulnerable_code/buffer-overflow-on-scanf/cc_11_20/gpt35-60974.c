//FormAI DATASET v1.0 Category: Database querying ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold employee information
typedef struct {
    int id;
    char name[50];
    char department[50];
    float salary;
} Employee;

int main() {
    // Declare necessary variables
    int option, search_id, i;
    char search_name[50];
    float search_salary;
    Employee employee;
    FILE *fp;

    // Open the employee database file
    fp = fopen("employees.dat", "rb");

    // If the file could not be opened, exit the program
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Ask the user for a query option
    printf("Choose a query option:\n");
    printf("1. Search by employee ID\n");
    printf("2. Search by employee name\n");
    printf("3. Search by employee salary\n");
    scanf("%d", &option);

    // Handle the selected query option
    switch(option) {
        case 1:
            printf("Enter the employee ID to search: ");
            scanf("%d", &search_id);
            // Search for the employee with the matching ID
            while(fread(&employee, sizeof(Employee), 1, fp)) {
                if(employee.id == search_id) {
                    printf("Employee found:\nID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", employee.id, employee.name, employee.department, employee.salary);
                    break;
                }
            }
            break;
        case 2:
            printf("Enter the employee name to search: ");
            scanf("%s", search_name);
            // Search for the employee with the matching name
            while(fread(&employee, sizeof(Employee), 1, fp)) {
                if(strcmp(employee.name, search_name) == 0) {
                    printf("Employee found:\nID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", employee.id, employee.name, employee.department, employee.salary);
                    break;
                }
            }
            break;
        case 3:
            printf("Enter the employee salary to search: ");
            scanf("%f", &search_salary);
            // Search for the employee(s) with the matching salary
            while(fread(&employee, sizeof(Employee), 1, fp)) {
                if(employee.salary == search_salary) {
                    printf("Employee found:\nID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", employee.id, employee.name, employee.department, employee.salary);
                }
            }
            break;
        default:
            printf("Invalid option selected.\n");
    }

    // Close the employee database file
    fclose(fp);

    return 0;
}