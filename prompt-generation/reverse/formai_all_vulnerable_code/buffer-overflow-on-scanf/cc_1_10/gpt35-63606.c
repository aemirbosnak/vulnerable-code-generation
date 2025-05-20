//FormAI DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[20];
    int id;
    float salary;
} Employee;

void addEmployee(Employee *database, int *size);
void printDatabase(Employee *database, int size);
void updateEmployee(Employee *database, int size);
void removeEmployee(Employee *database, int *size);

int main() {
    int choice, size = 0;
    Employee database[MAX_SIZE];

    do {
        printf("----------------------------\n");
        printf("| Employee Database System |\n");
        printf("----------------------------\n");
        printf("1. Add an employee\n");
        printf("2. Print the database\n");
        printf("3. Update an employee\n");
        printf("4. Remove an employee\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(database, &size);
                break;
            case 2:
                printDatabase(database, size);
                break;
            case 3:
                updateEmployee(database, size);
                break;
            case 4:
                removeEmployee(database, &size);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addEmployee(Employee *database, int *size) {
    if (*size == MAX_SIZE) {
        printf("Database is full. Cannot add more employees.\n");
        return;
    }

    Employee employee;

    printf("Please enter the employee name: ");
    scanf("%s", employee.name);
    printf("Please enter the employee ID: ");
    scanf("%d", &employee.id);
    printf("Please enter the employee salary: ");
    scanf("%f", &employee.salary);

    database[*size] = employee;

    printf("Employee added successfully.\n");

    (*size)++;
}

void printDatabase(Employee *database, int size) {
    if (size == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("Employee Database:\n");
    printf("Name\t\tID\tSalary\n");
    printf("--------------------------------\n");
    for (int i = 0; i < size; i++) {
        Employee employee = database[i];
        printf("%s\t\t%d\t%.2f\n", employee.name, employee.id, employee.salary);
    }
    printf("\n");
}

void updateEmployee(Employee *database, int size) {
    if (size == 0) {
        printf("Database is empty. Cannot update an employee.\n");
        return;
    }

    int id, found = 0;
    printf("Please enter the ID of the employee you want to update: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        Employee *employee = &database[i];
        if (employee->id == id) {
            found = 1;
            printf("Current employee details:\n");
            printf("Name: %s, ID: %d, Salary: %.2f\n", employee->name, employee->id, employee->salary);

            printf("Please enter the new employee name: ");
            scanf("%s", employee->name);
            printf("Please enter the new employee salary: ");
            scanf("%f", &employee->salary);

            printf("\nEmployee details updated successfully.\n");
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void removeEmployee(Employee *database, int *size) {
    if (*size == 0) {
        printf("Database is empty. Cannot remove an employee.\n");
        return;
    }

    int id, found = 0, index;
    printf("Please enter the ID of the employee you want to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < *size; i++) {
        Employee *employee = &database[i];
        if (employee->id == id) {
            found = 1;
            index = i;
            printf("Employee details:\n");
            printf("Name: %s, ID: %d, Salary: %.2f\n", employee->name, employee->id, employee->salary);

            printf("\nAre you sure you want to remove this employee? (Y/N): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                for (int j = index; j < (*size)-1; j++) {
                    database[j] = database[j+1];
                }
                (*size)--;
                printf("\nEmployee removed successfully.\n");
            }
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}