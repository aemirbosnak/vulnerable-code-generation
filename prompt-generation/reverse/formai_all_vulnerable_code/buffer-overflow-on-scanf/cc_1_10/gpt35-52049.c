//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Employee {
    int empId;
    char empName[50];
    char empDepartment[50];
    float empSalary;
};

struct Index {
    int empId;
    int index;
};
struct Employee employees[MAX];
struct Index indexArr[MAX];

void displayAllEmployees() {
    int i;
    printf("\n%-10s %-20s %-20s %s\n", "Emp ID", "Emp Name", "Emp Department", "Emp Salary");
    printf("-----------------------------------------------------------\n");
    for(i = 0; i < MAX; i++) {
        if(employees[i].empId != 0) {
            printf("%-10d %-20s %-20s %.2f\n", employees[i].empId, employees[i].empName, employees[i].empDepartment, employees[i].empSalary);
        }
    }
}

void displayEmployeeById(int empId) {
    int i;
    char flag = 'n';
    for(i = 0; i < MAX; i++) {
        if(employees[i].empId == empId) {
            flag = 'y';
            printf("\n%-10s %-20s %-20s %s\n", "Emp ID", "Emp Name", "Emp Department", "Emp Salary");
            printf("-----------------------------------------------------------\n");
            printf("%-10d %-20s %-20s %.2f\n", employees[i].empId, employees[i].empName, employees[i].empDepartment, employees[i].empSalary);
            break;
        }
    }
    if(flag == 'n') {
        printf("\nEmployee with ID %d was not found.", empId);
    }
}

void addEmployee() {
    int i, empId, index = -1;
    char empName[50], empDepartment[50];
    float empSalary;
    for(i = 0; i < MAX; i++) {
        if(employees[i].empId == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nCannot add more Employees. Employee database is full.\n");
        return;
    }
    printf("\nEnter the Employee ID: ");
    scanf("%d", &empId);
    for(i = 0; i < MAX; i++) {
        if(indexArr[i].empId == empId) {
            printf("\nEmployee with ID %d already exists.\n", empId);
            return;
        }
    }
    indexArr[index].empId = empId;
    indexArr[index].index = index;
    printf("\nEnter the Employee Name: ");
    scanf(" %[^\n]s", empName);
    printf("\nEnter the Employee Department: ");
    scanf(" %[^\n]s", empDepartment);
    printf("\nEnter the Employee Salary: ");
    scanf("%f", &empSalary);
    employees[index].empId = empId;
    strcpy(employees[index].empName, empName);
    strcpy(employees[index].empDepartment, empDepartment);
    employees[index].empSalary = empSalary;
    printf("\nEmployee with ID %d added successfully.\n", empId);
}

void deleteEmployeeById(int empId) {
    int i, index = -1;
    char flag = 'n';
    for(i = 0; i < MAX; i++) {
        if(indexArr[i].empId == empId) {
            index = indexArr[i].index;
            indexArr[i].empId = 0;
            indexArr[i].index = 0;
            flag = 'y';
            break;
        }
    }
    if(flag == 'n') {
        printf("\nEmployee with ID %d was not found.\n", empId);
        return;
    }
    employees[index].empId = 0;
    memset(employees[index].empName, 0, sizeof(employees[index].empName));
    memset(employees[index].empDepartment, 0, sizeof(employees[index].empDepartment));
    employees[index].empSalary = 0;
    printf("\nEmployee with ID %d deleted successfully.\n", empId);
}

void displayMenu() {
    printf("\nMenu:\n-----\n");
    printf("1. View all Employees.\n");
    printf("2. View Employee by ID.\n");
    printf("3. Add Employee.\n");
    printf("4. Delete Employee by ID.\n");
    printf("0. Exit.\n");
}

int main() {
    int choice, empId;
    while(1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                displayAllEmployees();
                break;
            }
            case 2: {
                printf("\nEnter the Employee ID: ");
                scanf("%d", &empId);
                displayEmployeeById(empId);
                break;
            }
            case 3: {
                addEmployee();
                break;
            }
            case 4: {
                printf("\nEnter the Employee ID: ");
                scanf("%d", &empId);
                deleteEmployeeById(empId);
                break;
            }
            case 0: {
                printf("\nExiting the program.\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please select a valid choice (1-4 or 0 to exit).\n");
            }
        }
    }
    return 0;
}