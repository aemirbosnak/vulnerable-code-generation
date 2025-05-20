//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define FILENAME "records.txt"

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee();
void listEmployees();
void searchEmployee();
void deleteEmployee();
void updateEmployee();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\nEmployee Management System:\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 6);
}

void addEmployee() {
    Employee emp;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);
    printf("Employee added successfully!\n");
}

void listEmployees() {
    Employee emp;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("\nList of Employees:\n");
    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(file);
}

void searchEmployee() {
    int id;
    Employee emp;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id == id) {
            printf("Found Employee: ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
    fclose(file);
}

void updateEmployee() {
    int id;
    Employee emp;
    FILE *file = fopen(FILENAME, "r+b"); 
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id == id) {
            printf("Current details - ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
            printf("Enter new Name: ");
            scanf("%s", emp.name);
            printf("Enter new Salary: ");
            scanf("%f", &emp.salary);
            
            fseek(file, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, file);
            found = 1;
            printf("Employee updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
    fclose(file);
}

void deleteEmployee() {
    int id;
    Employee emp;
    FILE *file = fopen(FILENAME, "rb");
    FILE *tempFile = fopen("temp.txt", "wb");
    if (file == NULL || tempFile == NULL) {
        perror("Could not open file");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id != id) {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Employee deleted successfully!\n");
    } else {
        printf("Employee with ID %d not found!\n", id);
    }
}