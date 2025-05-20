//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for employee data
typedef struct Employee {
    int id;
    char name[50];
    int age;
    int salary;
} Employee;

// Function to add employee data
void add_employee(FILE* fp) {
    Employee emp;
    printf("\nEnter employee id: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    printf("Enter employee salary: ");
    scanf("%d", &emp.salary);

    // Write employee data to file
    fwrite(&emp, sizeof(Employee), 1, fp);
    printf("\nEmployee added successfully!");
}

// Function to display all employee data
void display_employees(FILE* fp) {
    Employee emp;

    printf("\nID\tName\tAge\tSalary\n");
    printf("----------------------------------------\n");

    // Read employee data from file and display it
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%d\t%s\t%d\t%d\n", emp.id, emp.name, emp.age, emp.salary);
    }
}

// Function to search for employee data by id
void search_employee(FILE* fp) {
    int id;
    Employee emp;
    bool found = false;

    printf("\nEnter employee id to search: ");
    scanf("%d", &id);

    // Search employee data by id
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if(emp.id == id) {
            printf("\nEmployee found!\n\nID\tName\tAge\tSalary\n");
            printf("----------------------------------------\n");
            printf("%d\t%s\t%d\t%d\n", emp.id, emp.name, emp.age, emp.salary);
            found = true;
            break;
        }
    }
    if(!found) {
        printf("\nEmployee not found!");
    }
}

// Function to update employee data by id
void update_employee(FILE* fp) {
    int id, choice, salary;
    Employee emp;
    bool found = false;

    printf("\nEnter employee id to update: ");
    scanf("%d", &id);

    // Search for employee data by id
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if(emp.id == id) {
            printf("\nEmployee found!\n\nID\tName\tAge\tSalary\n");
            printf("----------------------------------------\n");
            printf("%d\t%s\t%d\t%d\n", emp.id, emp.name, emp.age, emp.salary);
            found = true;

            printf("\nSelect the field to update:\n");
            printf("1. Name\n2. Age\n3. Salary\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", emp.name);
                    break;
                case 2:
                    printf("Enter new age: ");
                    scanf("%d", &emp.age);
                    break;
                case 3:
                    printf("Enter new salary: ");
                    scanf("%d", &salary);
                    emp.salary = salary;
                    break;
                default:
                    printf("\nInvalid choice!");
            }

            // Move file pointer to the beginning of employee data
            fseek(fp, -sizeof(Employee), SEEK_CUR);

            // Write updated employee data to file
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("\nEmployee data updated successfully!");
            break;
        }
    }
    if(!found) {
        printf("\nEmployee not found!");
    }
}

// Function to delete employee data by id
void delete_employee(FILE* fp) {
    int id;
    Employee emp;
    FILE* tmpfp;

    printf("\nEnter employee id to delete: ");
    scanf("%d", &id);

    // Create a temporary file for writing employee data
    tmpfp = fopen("tmp.txt", "wb");
    rewind(fp);

    // Move employee data to temporary file except for the deleted one
    while(fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if(emp.id != id) {
            fwrite(&emp, sizeof(Employee), 1, tmpfp);
        }
    }
    fclose(fp);

    // Delete original file and rename temporary file to original file name
    remove("employees.txt");
    rename("tmp.txt", "employees.txt");
    printf("\nEmployee data deleted successfully!");
}

int main() {
    int choice;
    FILE* fp;

    fp = fopen("employees.txt", "ab+");
    if(fp == NULL) {
        printf("File does not exist!");
        exit(1);
    }

    do {
        printf("\nEMPLOYEE DATABASE\n");
        printf("1. Add employee\n2. Display employees\n");
        printf("3. Search employee\n4. Update employee data\n");
        printf("5. Delete employee data\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_employee(fp);
                break;
            case 2:
                display_employees(fp);
                break;
            case 3:
                search_employee(fp);
                break;
            case 4:
                update_employee(fp);
                break;
            case 5:
                delete_employee(fp);
                break;
            case 6:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 6);

    fclose(fp);
    return 0;
}