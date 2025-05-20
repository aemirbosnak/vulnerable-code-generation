//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_INDEX_SIZE 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

typedef struct {
    int id;
    int index_position;
} IndexEntry;

Employee employee_records[MAX_RECORDS];
IndexEntry index_records[MAX_INDEX_SIZE];
int record_count = 0;
int index_count = 0;

// Function to add an employee
void add_employee(int id, const char* name, float salary) {
    if (record_count >= MAX_RECORDS) {
        printf("Employee record limit reached!\n");
        return;
    }
    employee_records[record_count].id = id;
    strcpy(employee_records[record_count].name, name);
    employee_records[record_count].salary = salary;

    // Update index
    index_records[index_count].id = id;
    index_records[index_count].index_position = record_count;
    index_count++;

    record_count++;
}

// Function to display an employee by ID
void display_employee(int id) {
    for (int i = 0; i < index_count; i++) {
        if (index_records[i].id == id) {
            Employee emp = employee_records[index_records[i].index_position];
            printf("Employee ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n", emp.salary);
            return;
        }
    }
    printf("Employee with ID %d not found!\n", id);
}

// Function to display all employees
void display_all_employees() {
    printf("=== All Employees ===\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employee_records[i].id, employee_records[i].name, employee_records[i].salary);
    }
}

// Function to create index based on ID (Sort-based indexing)
void create_index() {
    // Simple insertion sort for index
    for (int i = 1; i < record_count; i++) {
        Employee key = employee_records[i];
        int j = i - 1;
        while (j >= 0 && employee_records[j].id > key.id) {
            employee_records[j + 1] = employee_records[j];
            j--;
        }
        employee_records[j + 1] = key;
    }

    // Create index after sorting
    for (int i = 0; i < record_count; i++) {
        index_records[i].id = employee_records[i].id;
        index_records[i].index_position = i;
    }
    index_count = record_count;
}

// Function to delete an employee
void delete_employee(int id) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (employee_records[i].id == id) {
            found = 1;
            for (int j = i; j < record_count - 1; j++) {
                employee_records[j] = employee_records[j + 1];
            }
            record_count--;
            break;
        }
    }

    // Update index
    if (found) {
        create_index();
        printf("Employee with ID %d deleted successfully.\n", id);
    } else {
        printf("Employee with ID %d not found!\n", id);
    }
}

// Function to search for an employee
void search_employee(int id) {
    int low = 0;
    int high = index_count - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (index_records[mid].id == id) {
            // Display employee found
            display_employee(index_records[mid].id);
            return;
        } else if (index_records[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Employee with ID %d not found!\n", id);
}

// Main function
int main() {
    int choice, id;
    char name[50];
    float salary;

    do {
        printf("\n=== Employee Database ===\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee by ID\n");
        printf("3. Display All Employees\n");
        printf("4. Delete Employee\n");
        printf("5. Search Employee\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                add_employee(id, name, salary);
                break;

            case 2:
                printf("Enter Employee ID to display: ");
                scanf("%d", &id);
                display_employee(id);
                break;

            case 3:
                display_all_employees();
                break;

            case 4:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(id);
                break;

            case 5:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                search_employee(id);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}