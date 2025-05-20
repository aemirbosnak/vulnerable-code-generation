//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee();
void display_employees();
void update_employee();
void delete_employee();
void save_to_file();
void load_from_file();

int main() {
    int choice;

    load_from_file();

    while (1) {
        printf("\n--- Employee Database ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                update_employee();
                break;
            case 4:
                delete_employee();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                load_from_file();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Employee database is full!\n");
        return;
    }
    Employee emp;
    emp.id = employee_count + 1; // Simple ID assignment based on count
    printf("Enter name: ");
    scanf("%s", emp.name);
    printf("Enter salary: ");
    scanf("%f", &emp.salary);
    
    employees[employee_count] = emp;
    employee_count++;
    printf("Employee added successfully!\n");
}

void display_employees() {
    if (employee_count == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employee_count; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void update_employee() {
    int id;
    printf("Enter the employee ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > employee_count) {
        printf("Invalid employee ID.\n");
        return;
    }

    Employee *emp = &employees[id - 1];
    printf("Current Name: %s, Current Salary: %.2f\n", emp->name, emp->salary);
    printf("Enter new name: ");
    scanf("%s", emp->name);
    printf("Enter new salary: ");
    scanf("%f", &emp->salary);
    
    printf("Employee updated successfully!\n");
}

void delete_employee() {
    int id;
    printf("Enter the employee ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > employee_count) {
        printf("Invalid employee ID.\n");
        return;
    }

    for (int i = id - 1; i < employee_count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employee_count--;
    printf("Employee deleted successfully!\n");
}

void save_to_file() {
    FILE *file = fopen("employees.dat", "wb");
    if (file) {
        fwrite(employees, sizeof(Employee), employee_count, file);
        fclose(file);
        printf("Employees saved to file.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

void load_from_file() {
    FILE *file = fopen("employees.dat", "rb");
    if (file) {
        employee_count = fread(employees, sizeof(Employee), MAX_EMPLOYEES, file);
        fclose(file);
        printf("Employees loaded from file.\n");
    } else {
        printf("Error opening file for reading. Starting with an empty database.\n");
    }
}