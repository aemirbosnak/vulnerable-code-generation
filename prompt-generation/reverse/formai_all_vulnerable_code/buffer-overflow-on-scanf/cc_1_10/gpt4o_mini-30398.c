//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float salary;
} Employee;

void displayMenu() {
    printf("\n======= Employee Management System =======\n");
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Search Employee\n");
    printf("4. Delete Employee\n");
    printf("5. Exit\n");
    printf("===========================================\n");
    printf("Choose an option: ");
}

void addEmployee(FILE *file) {
    Employee emp;
    printf("Enter employee name: ");
    scanf(" %[^\n]", emp.name);
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    
    fseek(file, 0, SEEK_END);
    fwrite(&emp, sizeof(Employee), 1, file);
    printf("Employee added successfully!\n");
}

void viewEmployees(FILE *file) {
    Employee emp;
    rewind(file);
    printf("\n======= Employee List =======\n");
    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", emp.name, emp.age, emp.salary);
    }
    printf("==============================\n");
}

void searchEmployee(FILE *file) {
    char name[MAX_NAME_LEN];
    Employee emp;
    int found = 0;
    printf("Enter employee name to search: ");
    scanf(" %[^\n]", name);
    
    rewind(file);
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (strcmp(emp.name, name) == 0) {
            printf("Employee found! Name: %s, Age: %d, Salary: %.2f\n",
                   emp.name, emp.age, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee not found.\n");
    }
}

void deleteEmployee(FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Could not open temporary file.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    Employee emp;
    int found = 0;
    printf("Enter employee name to delete: ");
    scanf(" %[^\n]", name);

    rewind(file);
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (strcmp(emp.name, name) != 0) {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        } else {
            found = 1;
            printf("Employee deleted: %s\n", emp.name);
        }
    }
    fclose(tempFile);
    fclose(file);
    remove("employees.dat"); // remove original file
    rename("temp.dat", "employees.dat"); // rename temp file
    if (found == 0) {
        printf("Employee not found for deletion.\n");
    }
}

int main() {
    FILE *file = fopen("employees.dat", "ab+");
    if (!file) {
        printf("Could not open file.\n");
        return 1;
    }

    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                viewEmployees(file);
                break;
            case 3:
                searchEmployee(file);
                break;
            case 4:
                deleteEmployee(file);
                file = fopen("employees.dat", "ab+"); // reopen the file
                break;
            case 5:
                fclose(file);
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    }
    
    return 0;
}