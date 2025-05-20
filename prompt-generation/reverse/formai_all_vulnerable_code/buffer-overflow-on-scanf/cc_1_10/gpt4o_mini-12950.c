//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char department[NAME_LENGTH];
} Employee;

typedef struct {
    int id;
    int index;
} Index;

Employee employees[MAX_EMPLOYEES];
Index index_table[MAX_EMPLOYEES];
int employee_count = 0;

void add_employee(int id, const char* name, const char* department) {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Database is full, cannot add more employees.\n");
        return;
    }
    employees[employee_count].id = id;
    strncpy(employees[employee_count].name, name, NAME_LENGTH - 1);
    strncpy(employees[employee_count].department, department, NAME_LENGTH - 1);
    
    index_table[employee_count].id = id;
    index_table[employee_count].index = employee_count; // Store the index in the array
    
    employee_count++;
}

void sort_index() {
    for (int i = 0; i < employee_count - 1; i++) {
        for (int j = 0; j < employee_count - i - 1; j++) {
            if (index_table[j].id > index_table[j + 1].id) {
                // Swap index entries
                Index temp = index_table[j];
                index_table[j] = index_table[j + 1];
                index_table[j + 1] = temp;
            }
        }
    }
}

int binary_search_index(int id) {
    int left = 0;
    int right = employee_count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (index_table[mid].id == id) {
            return index_table[mid].index; // Found, return record index
        }
        if (index_table[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

void view_employee(int index) {
    if (index >= 0 && index < employee_count) {
        printf("ID: %d, Name: %s, Department: %s\n", employees[index].id, employees[index].name, employees[index].department);
    } else {
        printf("Employee not found.\n");
    }
}

void search_employee(int id) {
    int index = binary_search_index(id);
    view_employee(index);
}

void display_all_employees() {
    printf("\nAll Employees:\n");
    for (int i = 0; i < employee_count; i++) {
        printf("ID: %d, Name: %s, Department: %s\n", employees[i].id, employees[i].name, employees[i].department);
    }
}

int main() {
    int choice, id;
    char name[NAME_LENGTH], department[NAME_LENGTH];

    while (1) {
        printf("\nSimple Employee Database\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee By ID\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf(" %[^\n]s", name);
                printf("Enter Department: ");
                scanf(" %[^\n]s", department);
                add_employee(id, name, department);
                sort_index(); // Sort the index table after every addition
                break;
            case 2:
                display_all_employees();
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                search_employee(id);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}