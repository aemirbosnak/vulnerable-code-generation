//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

// Function Prototypes
void add_employee();
void list_employees();
void search_employee();
int binary_search(int id);
void save_data();
void load_data();

int main() {
    load_data();

    int choice;
    do {
        printf("\n--- Employee Database Indexing System ---\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                list_employees();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                save_data();
                printf("Exiting! Your data is saved.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Employee limit reached, cannot add more employees!\n");
        return;
    }

    Employee emp;
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf(" %[^\n]", emp.name); // Read a string with spaces

    employees[employee_count] = emp;
    employee_count++;
    printf("Employee added successfully!\n");
}

void list_employees() {
    printf("\n--- List of Employees ---\n");
    for (int i = 0; i < employee_count; i++) {
        printf("ID: %d, Name: %s\n", employees[i].id, employees[i].name);
    }
}

void search_employee() {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    int index = binary_search(id);
    if (index != -1) {
        printf("Employee Found -> ID: %d, Name: %s\n", employees[index].id, employees[index].name);
    } else {
        printf("Employee with ID %d not found!\n", id);
    }
}

int binary_search(int id) {
    int left = 0;
    int right = employee_count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (employees[mid].id == id) {
            return mid;
        } else if (employees[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void save_data() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Unable to save data!\n");
        return;
    }
    fwrite(&employee_count, sizeof(int), 1, file);
    fwrite(employees, sizeof(Employee), employee_count, file);
    fclose(file);
    printf("Data saved to %s successfully!\n", FILE_NAME);
}

void load_data() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No previous data found, starting fresh!\n");
        return;
    }
    fread(&employee_count, sizeof(int), 1, file);
    fread(employees, sizeof(Employee), employee_count, file);
    fclose(file);
    printf("Data loaded successfully! %d employees found.\n", employee_count);
}