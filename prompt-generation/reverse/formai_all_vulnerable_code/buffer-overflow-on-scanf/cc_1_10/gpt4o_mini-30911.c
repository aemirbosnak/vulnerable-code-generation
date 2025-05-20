//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100
#define POSITION_LENGTH 50

typedef struct Employee {
    int id;
    char name[NAME_LENGTH];
    char position[POSITION_LENGTH];
    struct Employee* next;
} Employee;

Employee* head = NULL;
int employeeCount = 0;

void addEmployee() {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    if (!newEmployee) {
        printf("Memory allocation failed!\n");
        return;
    }

    newEmployee->id = ++employeeCount;
    printf("Enter employee name: ");
    scanf(" %[^\n]", newEmployee->name);
    printf("Enter employee position: ");
    scanf(" %[^\n]", newEmployee->position);
    
    newEmployee->next = head;
    head = newEmployee;
    printf("Employee added with ID: %d\n", newEmployee->id);
}

void viewEmployees() {
    if (head == NULL) {
        printf("No employees found.\n");
        return;
    }
    
    Employee* current = head;
    printf("\nEmployee Records:\n");
    printf("ID\tName\tPosition\n");
    while (current != NULL) {
        printf("%d\t%s\t%s\n", current->id, current->name, current->position);
        current = current->next;
    }
}

void searchEmployee() {
    int searchId;
    printf("Enter employee ID to search: ");
    scanf("%d", &searchId);
    
    Employee* current = head;
    while (current != NULL) {
        if (current->id == searchId) {
            printf("Employee Found:\n");
            printf("ID: %d\n", current->id);
            printf("Name: %s\n", current->name);
            printf("Position: %s\n", current->position);
            return;
        }
        current = current->next;
    }
    
    printf("Employee with ID %d not found.\n", searchId);
}

void deleteEmployee() {
    int deleteId;
    printf("Enter employee ID to delete: ");
    scanf("%d", &deleteId);
    
    Employee* current = head;
    Employee* previous = NULL;
    
    while (current != NULL && current->id != deleteId) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Employee with ID %d not found.\n", deleteId);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Employee with ID %d deleted.\n", deleteId);
}

void cleanUp() {
    Employee* current = head;
    Employee* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice;

    do {
        printf("\n=== Employee Database Menu ===\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    cleanUp();
    return 0;
}