//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: interoperable
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

Employee employee_db[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Employee database is full!\n");
        return;
    }
    
    Employee new_employee;
    new_employee.id = employee_count + 1;
    
    printf("Enter name for employee %d: ", new_employee.id);
    fgets(new_employee.name, NAME_LENGTH, stdin);
    new_employee.name[strcspn(new_employee.name, "\n")] = '\0'; // Remove newline
    
    printf("Enter salary for employee %d: ", new_employee.id);
    scanf("%f", &new_employee.salary);
    getchar(); // Consume the newline left by scanf
    
    employee_db[employee_count++] = new_employee;
    printf("Employee added successfully!\n");
}

void view_employees() {
    if (employee_count == 0) {
        printf("No employees in the database.\n");
        return;
    }
    
    printf("\nID\tName\t\tSalary\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%d\t%-15s\t%.2f\n", employee_db[i].id, employee_db[i].name, employee_db[i].salary);
    }
    printf("------------------------------------------\n");
}

void update_employee() {
    int id;
    printf("Enter the ID of the employee to update: ");
    scanf("%d", &id);
    getchar(); // Consume the newline character

    if (id < 1 || id > employee_count) {
        printf("Employee not found!\n");
        return;
    }
    
    Employee *emp = &employee_db[id - 1];
    printf("Updating employee #%d\n", emp->id);
    printf("Current name: %s\n", emp->name);
    printf("Enter new name (press enter to keep current): ");
    char new_name[NAME_LENGTH];
    fgets(new_name, NAME_LENGTH, stdin);
    new_name[strcspn(new_name, "\n")] = '\0';

    if (strlen(new_name) > 0) {
        strncpy(emp->name, new_name, NAME_LENGTH);
    }

    printf("Current salary: %.2f\n", emp->salary);
    printf("Enter new salary (0 to keep current): ");
    float new_salary;
    scanf("%f", &new_salary);
    getchar(); // Consume the newline

    if (new_salary > 0) {
        emp->salary = new_salary;
    }

    printf("Employee updated successfully!\n");
}

void delete_employee() {
    int id;
    printf("Enter the ID of the employee to delete: ");
    scanf("%d", &id);
    getchar(); // Consume the newline

    if (id < 1 || id > employee_count) {
        printf("Employee not found!\n");
        return;
    }

    for (int i = id - 1; i < employee_count - 1; i++) {
        employee_db[i] = employee_db[i + 1];
    }
    employee_count--;

    printf("Employee deleted successfully!\n");
}

void display_menu() {
    printf("\n--- Employee Database Menu ---\n");
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Update Employee\n");
    printf("4. Delete Employee\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                view_employees();
                break;
            case 3:
                update_employee();
                break;
            case 4:
                delete_employee();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}