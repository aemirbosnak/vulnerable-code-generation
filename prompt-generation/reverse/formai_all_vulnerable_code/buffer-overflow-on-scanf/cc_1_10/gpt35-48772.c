//FormAI DATASET v1.0 Category: Database querying ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for database entry
typedef struct {
  int id;
  char name[20];
  float salary;
} Employee;

// Function prototypes
void add_employee(Employee *employees, int *num_employees);
void display_all_employees(Employee *employees, int num_employees);
void search_employee_by_name(Employee *employees, int num_employees, char *name);

int main() {
  // Initialize variables
  int num_employees = 0, choice;
  char name[20];
  Employee *employees = NULL;

  // Display menu to user and get their choice
  while (1) {
    printf("\n1. Add employee\n2. Display all employees\n3. Search employee by name\n4. Quit\n\nEnter choice: ");
    scanf("%d", &choice);

    // Call appropriate function based on user's choice
    switch (choice) {
      case 1:
        add_employee(employees, &num_employees);
        break;
      case 2:
        display_all_employees(employees, num_employees);
        break;
      case 3:
        printf("Enter name of employee to search: ");
        scanf("%s", name);
        search_employee_by_name(employees, num_employees, name);
        break;
      case 4:
        // Free memory and exit program
        if (employees)
          free(employees);
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

// Function to add a new employee to the employees array
void add_employee(Employee *employees, int *num_employees) {
  // Increment size of employees array
  (*num_employees)++;
  employees = realloc(employees, sizeof(Employee) * (*num_employees));

  // Get employee information from user
  printf("\nEnter employee ID: ");
  scanf("%d", &employees[*num_employees-1].id);
  printf("Enter employee name: ");
  scanf("%s", employees[*num_employees-1].name);
  printf("Enter employee salary: ");
  scanf("%f", &employees[*num_employees-1].salary);

  // Print success message
  printf("\nEmployee added successfully!\n");
}

// Function to display all employees in the employees array
void display_all_employees(Employee *employees, int num_employees) {
  // Check if there are any employees
  if (num_employees == 0) {
    printf("\nNo employees found.\n");
    return;
  }

  // Print employee information
  printf("\nEmployee ID\tEmployee Name\tEmployee Salary\n");
  for (int i = 0; i < num_employees; i++) {
    printf("%d\t\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
  }
}

// Function to search for an employee by name in the employees array
void search_employee_by_name(Employee *employees, int num_employees, char *name) {
  int found_employee = 0;

  // Search for employee and print their information if found
  for (int i = 0; i < num_employees; i++) {
    if (strcmp(employees[i].name, name) == 0) {
      printf("\nEmployee found!\n\nEmployee ID: %d\nEmployee Name: %s\nEmployee Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
      found_employee = 1;
    }
  }

  // Print error message if employee not found
  if (!found_employee)
    printf("\nEmployee not found.\n");
}