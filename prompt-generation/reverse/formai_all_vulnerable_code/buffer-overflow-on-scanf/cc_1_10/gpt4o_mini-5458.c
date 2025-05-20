//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    double salary;
} Employee;

Employee database[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("📦 Database is full! Can't add more employees!\n");
        return;
    }

    printf("🚨 Enter Employee ID: ");
    int id;
    scanf("%d", &id);
    while (getchar() != '\n'); // Clear the input buffer to avoid issues

    printf("📄 Enter Employee Name: ");
    char name[NAME_LENGTH];
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("💰 Enter Employee Salary: ");
    double salary;
    scanf("%lf", &salary);
    
    database[employee_count].id = id;
    strncpy(database[employee_count].name, name, NAME_LENGTH);
    database[employee_count].salary = salary;
    employee_count++;
    printf("🎉 Employee added successfully!\n");
}

void display_employees() {
    if (employee_count == 0) {
        printf("⚠️ No employees to display! Database is empty!\n");
        return;
    }

    printf("📋 Employee List:\n");
    printf("ID\tName\t\tSalary\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%d\t%s\t%.2f\n", database[i].id, database[i].name, database[i].salary);
    }
}

void delete_employee() {
    if (employee_count == 0) {
        printf("⚠️ No employees to delete! Database is empty!\n");
        return;
    }

    printf("❗ Enter Employee ID to delete: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (database[i].id == id) {
            // Shift left the rest of the employees
            for (int j = i; j < employee_count - 1; j++) {
                database[j] = database[j + 1];
            }
            employee_count--;
            printf("🚫 Employee with ID %d has been deleted!\n", id);
            return;
        }
    }
    printf("🚨 Employee ID not found!\n");
}

void show_menu() {
    printf("\n========================\n");
    printf("💼 Employee Database 💼\n");
    printf("========================\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Delete Employee\n");
    printf("4. Exit\n");
    printf("========================\n");
}

int main() {
    int choice;

    do {
        show_menu();
        printf("🌟 Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                delete_employee();
                break;
            case 4:
                printf("👋 Exiting the database... Goodbye!\n");
                break;
            default:
                printf("🚨 Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}