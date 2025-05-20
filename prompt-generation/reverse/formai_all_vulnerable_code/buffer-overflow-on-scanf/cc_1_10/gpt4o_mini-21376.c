//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_NAME_LENGTH 50

// Structure to hold employee details
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char position[MAX_NAME_LENGTH];
} Employee;

// Function prototypes
void addEmployee(Employee *employees, int *count);
void displayEmployees(const Employee *employees, int count);
void searchEmployee(const Employee *employees, int count);
void deleteEmployee(Employee *employees, int *count);
void editEmployee(Employee *employees, int count);
void sortEmployees(Employee *employees, int count);
void displayMenu();

int main() {
    Employee employees[MAX_LENGTH];
    int employeeCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character left in the buffer

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;
            case 2:
                displayEmployees(employees, employeeCount);
                break;
            case 3:
                searchEmployee(employees, employeeCount);
                break;
            case 4:
                editEmployee(employees, employeeCount);
                break;
            case 5:
                deleteEmployee(employees, &employeeCount);
                break;
            case 6:
                sortEmployees(employees, employeeCount);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Edit Employee\n");
    printf("5. Delete Employee\n");
    printf("6. Sort Employees\n");
    printf("7. Exit\n");
}

void addEmployee(Employee *employees, int *count) {
    if (*count >= MAX_LENGTH) {
        printf("Employee list is full!\n");
        return;
    }
    printf("Enter name: ");
    fgets(employees[*count].name, MAX_NAME_LENGTH, stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = 0; // Remove trailing newline
    printf("Enter age: ");
    scanf("%d", &employees[*count].age);
    getchar(); // Consume newline
    printf("Enter position: ");
    fgets(employees[*count].position, MAX_NAME_LENGTH, stdin);
    employees[*count].position[strcspn(employees[*count].position, "\n")] = 0; // Remove trailing newline

    (*count)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(const Employee *employees, int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("Employees:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Position: %s\n",
                employees[i].name, employees[i].age, employees[i].position);
    }
}

void searchEmployee(const Employee *employees, int count) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, searchName) == 0) {
            printf("Employee found: Name: %s, Age: %d, Position: %s\n",
                    employees[i].name, employees[i].age, employees[i].position);
            return;
        }
    }
    printf("Employee not found.\n");
}

void editEmployee(Employee *employees, int count) {
    char editName[MAX_NAME_LENGTH];
    printf("Enter name of employee to edit: ");
    fgets(editName, MAX_NAME_LENGTH, stdin);
    editName[strcspn(editName, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, editName) == 0) {
            printf("Editing employee: %s\n", employees[i].name);
            printf("Enter new age: ");
            scanf("%d", &employees[i].age);
            getchar(); // Consume newline
            printf("Enter new position: ");
            fgets(employees[i].position, MAX_NAME_LENGTH, stdin);
            employees[i].position[strcspn(employees[i].position, "\n")] = 0; // Remove trailing newline
            printf("Employee details updated.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void deleteEmployee(Employee *employees, int *count) {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name of employee to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(employees[i].name, deleteName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1]; // Shift employees up
            }
            (*count)--; // Decrease employee count
            printf("Employee deleted successfully.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void sortEmployees(Employee *employees, int count) {
    if (count < 2) {
        printf("Not enough employees to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp; // Swap employees
            }
        }
    }
    printf("Employees sorted by name.\n");
}