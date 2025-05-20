//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define POSITION_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char position[POSITION_LENGTH];
    float salary;
} Employee;

Employee employee_db[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Database is full! Cannot add more employees.\n");
        return;
    }
    
    Employee new_employee;
    new_employee.id = employee_count + 1; // Simple ID generation
    printf("Enter employee name: ");
    getchar(); // Clear buffer
    fgets(new_employee.name, NAME_LENGTH, stdin);
    new_employee.name[strcspn(new_employee.name, "\n")] = '\0'; // Remove newline

    printf("Enter employee position: ");
    fgets(new_employee.position, POSITION_LENGTH, stdin);
    new_employee.position[strcspn(new_employee.position, "\n")] = '\0'; // Remove newline

    printf("Enter employee salary: ");
    scanf("%f", &new_employee.salary);

    employee_db[employee_count++] = new_employee;
    printf("Employee added successfully!\n");
}

void delete_employee() {
    int id, found = 0;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employee_count; i++) {
        if (employee_db[i].id == id) {
            found = 1;
            printf("Deleting Employee: %s\n", employee_db[i].name);
            for (int j = i; j < employee_count - 1; j++) {
                employee_db[j] = employee_db[j + 1];
            }
            employee_count--;
            printf("Employee deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}

void view_employees() {
    if (employee_count == 0) {
        printf("No employees in the database.\n");
        return;
    }
    
    printf("Employee Database:\n");
    printf("ID\tName\t\tPosition\t\tSalary\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%d\t%-16s\t%-16s\t%.2f\n",
               employee_db[i].id,
               employee_db[i].name,
               employee_db[i].position,
               employee_db[i].salary);
    }
}

void search_employee() {
    int id, found = 0;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employee_count; i++) {
        if (employee_db[i].id == id) {
            printf("Employee Found: \n");
            printf("ID: %d\nName: %s\nPosition: %s\nSalary: %.2f\n",
                   employee_db[i].id,
                   employee_db[i].name,
                   employee_db[i].position,
                   employee_db[i].salary);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}

void display_menu() {
    printf("\nEmployee Database Menu:\n");
    printf("1. Add Employee\n");
    printf("2. Delete Employee\n");
    printf("3. View All Employees\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                delete_employee();
                break;
            case 3:
                view_employees();
                break;
            case 4:
                search_employee();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option, please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}