//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store employee information
typedef struct Employee {
    char name[50];
    int age;
    double salary;
    struct Employee* next;
} Employee;

// Function to insert a new employee at the end
void insertEmployee(Employee** head) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("Enter employee name: ");
    scanf("%s", newEmployee->name);
    printf("Enter employee age: ");
    scanf("%d", &newEmployee->age);
    printf("Enter employee salary: ");
    scanf("%lf", &newEmployee->salary);

    if (*head == NULL) {
        *head = newEmployee;
    } else {
        (*head)->next = newEmployee;
    }
    *head = newEmployee;
}

// Function to print all employees
void printEmployees(Employee* head) {
    while (head) {
        printf("%s, %d, %.2lf\n", head->name, head->age, head->salary);
        head = head->next;
    }
}

int main() {
    Employee* head = NULL;
    char choice;

    // Main loop to insert and print employees
    while (1) {
        printf("Enter 'i' to insert, 'p' to print, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'i':
                insertEmployee(&head);
                break;
            case 'p':
                printEmployees(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}