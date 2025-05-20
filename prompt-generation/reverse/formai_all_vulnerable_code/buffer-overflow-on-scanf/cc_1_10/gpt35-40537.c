//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    int age;
    float salary;
};

// function to add a new employee record to file
void add_employee_to_file(FILE *fptr) {
    struct employee emp;
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("\nEnter employee name: ");
    scanf("%s", emp.name);
    printf("\nEnter employee age: ");
    scanf("%d", &emp.age);
    printf("\nEnter employee salary: ");
    scanf("%f", &emp.salary);
    fwrite(&emp, sizeof(struct employee), 1, fptr);
    printf("\nEmployee added successfully!\n");
}

// function to display all employee records
void display_all_employees_from_file(FILE *fptr) {
    struct employee emp;
    printf("\nEmployee records in file:\n");
    while(fread(&emp, sizeof(struct employee), 1, fptr)) {
        printf("\nID: %d | Name: %s | Age: %d | Salary: %.2f", emp.id, emp.name, emp.age, emp.salary);
    }
    printf("\n\n");
}

// function to search for an employee record by ID
void search_employee_by_id(FILE *fptr) {
    int emp_id;
    struct employee emp;
    printf("\nEnter employee ID to search: ");
    scanf("%d", &emp_id);
    while(fread(&emp, sizeof(struct employee), 1, fptr)) {
        if(emp.id == emp_id) {
            printf("\nID: %d | Name: %s | Age: %d | Salary: %.2f\n", emp.id, emp.name, emp.age, emp.salary);
            return;
        }
    }
    printf("\nEmployee with ID %d not found!\n", emp_id);
}

// function to display a menu and handle user input
void display_menu_and_handle_input(FILE *fptr) {
    int choice = 0;
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Add employee record to file\n");
        printf("2. Display all employee records\n");
        printf("3. Search employee record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_employee_to_file(fptr);
                break;
            case 2:
                display_all_employees_from_file(fptr);
                break;
            case 3:
                search_employee_by_id(fptr);
                break;
            case 4:
                fclose(fptr);
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, try again!\n");
        }
    }
}

int main() {
    FILE *fptr;
    fptr = fopen("employees.dat", "ab+");
    if(fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    display_menu_and_handle_input(fptr);
    return 0;
}