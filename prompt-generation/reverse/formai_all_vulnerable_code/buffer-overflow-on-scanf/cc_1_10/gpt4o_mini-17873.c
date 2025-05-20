//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 30

typedef struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    struct Employee* next;
} Employee;

Employee* head = NULL;

// Function prototypes
void add_employee(int id, const char* name, const char* department);
void remove_employee(int id);
Employee* search_employee(int id);
void display_employees();
void free_memory();

int main() {
    int choice;
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];

    while (true) {
        printf("\nEmployee Database Indexing System\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Department: ");
                scanf("%s", department);
                add_employee(id, name, department);
                break;
            case 2:
                printf("Enter Employee ID to remove: ");
                scanf("%d", &id);
                remove_employee(id);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                Employee* employee = search_employee(id);
                if (employee) {
                    printf("Employee Found: ID=%d, Name=%s, Department=%s\n", employee->id, employee->name, employee->department);
                } else {
                    printf("Employee not found!\n");
                }
                break;
            case 4:
                display_employees();
                break;
            case 5:
                free_memory();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void add_employee(int id, const char* name, const char* department) {
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    if (!new_employee) {
        fprintf(stderr, "Memory allocation error!\n");
        return;
    }
    new_employee->id = id;
    strncpy(new_employee->name, name, MAX_NAME_LENGTH);
    strncpy(new_employee->department, department, MAX_DEPARTMENT_LENGTH);
    new_employee->next = head;
    head = new_employee;
    printf("Employee added successfully.\n");
}

void remove_employee(int id) {
    Employee* current = head;
    Employee* previous = NULL;

    while (current && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        printf("Employee ID %d not found!\n", id);
    } else {
        if (previous) {
            previous->next = current->next;
        } else {
            head = current->next;
        }
        free(current);
        printf("Employee removed successfully.\n");
    }
}

Employee* search_employee(int id) {
    Employee* current = head;
    while (current) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void display_employees() {
    Employee* current = head;
    if (!current) {
        printf("No employees in the database.\n");
        return;
    }
    printf("Employee List:\n");
    while (current) {
        printf("ID: %d, Name: %s, Department: %s\n", current->id, current->name, current->department);
        current = current->next;
    }
}

void free_memory() {
    Employee* current = head;
    Employee* next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}