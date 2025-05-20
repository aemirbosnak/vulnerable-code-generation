//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

void addEmployee(FILE *file);
void displayEmployees(FILE *file);
void findEmployee(FILE *file, const char *name);
void deleteEmployee(FILE *file, const char *name);
void updateEmployee(FILE *file, const char *name);

int main() {
    FILE *file;
    int choice;
    char name[MAX_NAME_LENGTH];

    // Open file in read and write mode (create if not exists)
    file = fopen("employees.dat", "a+");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Find Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Update Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployees(file);
                break;
            case 3:
                printf("Enter name to find: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                findEmployee(file, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deleteEmployee(file, name);
                break;
            case 5:
                printf("Enter name to update: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                updateEmployee(file, name);
                break;
            case 6:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    fclose(file);
    return 0;
}

void addEmployee(FILE *file) {
    Employee emp;
    printf("Enter name: ");
    fgets(emp.name, MAX_NAME_LENGTH, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline

    printf("Enter age: ");
    scanf("%d", &emp.age);
    printf("Enter salary: ");
    scanf("%f", &emp.salary);
    getchar(); // Clear newline character

    fseek(file, 0, SEEK_END); // Move to end of file
    fwrite(&emp, sizeof(Employee), 1, file); // Write employee to file
    printf("Employee added successfully.\n");
}

void displayEmployees(FILE *file) {
    Employee emp;
    rewind(file); // Go to beginning of file

    printf("\nEmployee Records:\n");
    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", emp.name, emp.age, emp.salary);
    }
}

void findEmployee(FILE *file, const char *name) {
    Employee emp;
    rewind(file); // Go to beginning of file

    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (strcmp(emp.name, name) == 0) {
            printf("Found Employee - Name: %s, Age: %d, Salary: %.2f\n", emp.name, emp.age, emp.salary);
            return;
        }
    }
    printf("Employee with name %s not found.\n", name);
}

void deleteEmployee(FILE *file, const char *name) {
    FILE *tempFile;
    Employee emp;
    int found = 0;

    tempFile = fopen("temp.dat", "w+");
    if (tempFile == NULL) {
        perror("Unable to create temporary file");
        return;
    }

    rewind(file); // Go to beginning of the original file

    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (strcmp(emp.name, name) == 0) {
            found = 1; // Employee found, don't write to temp file
            printf("Deleted Employee - Name: %s, Age: %d, Salary: %.2f\n", emp.name, emp.age, emp.salary);
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFile); // Write other employees to temp file
        }
    }

    fclose(tempFile);
    fclose(file);
    remove("employees.dat");
    rename("temp.dat", "employees.dat"); // Replace old file with new file

    if (!found) {
        printf("No employee with name %s found to delete.\n", name);
    }
}

void updateEmployee(FILE *file, const char *name) {
    Employee emp;
    int found = 0;

    FILE *tempFile = fopen("temp.dat", "w+");
    if (tempFile == NULL) {
        perror("Unable to create temporary file");
        return;
    }

    rewind(file); // Go to beginning of original file

    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (strcmp(emp.name, name) == 0) {
            found = 1; // Employee found, now update
            printf("Updating Employee - Current Name: %s, Age: %d, Salary: %.2f\n", emp.name, emp.age, emp.salary);
            printf("Enter new name: ");
            fgets(emp.name, MAX_NAME_LENGTH, stdin);
            emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline

            printf("Enter new age: ");
            scanf("%d", &emp.age);
            printf("Enter new salary: ");
            scanf("%f", &emp.salary);
            getchar(); // Clear newline character
        }
        fwrite(&emp, sizeof(Employee), 1, tempFile); // Write record to temp file
    }

    fclose(tempFile);
    fclose(file);
    remove("employees.dat");
    rename("temp.dat", "employees.dat"); // Replace old file with new file

    if (!found) {
        printf("No employee with name %s found to update.\n", name);
    } else {
        printf("Employee details updated successfully.\n");
    }
}