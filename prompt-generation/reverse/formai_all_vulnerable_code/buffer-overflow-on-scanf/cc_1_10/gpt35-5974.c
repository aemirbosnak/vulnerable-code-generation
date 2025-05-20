//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include<stdio.h>
#include<stdlib.h>

#define MAX_RECORDS 100

struct employee {
    int id;
    char name[50];
    int age;
};

void addEmployee(struct employee emp[], int* count) {
    if (*count < MAX_RECORDS) {
        printf("\nEnter details of Employee #%d:\n", (*count)+1);
        printf("ID: ");
        scanf("%d", &emp[*count].id);
        printf("Name: ");
        scanf("%s", emp[*count].name);
        printf("Age: ");
        scanf("%d", &emp[*count].age);
        *count += 1;
        printf("\nEmployee added successfully!\n\n");
    }
    else {
        printf("\nDatabase is full! Cannot add more employees.\n\n");
    }
}

void displayEmployees(struct employee emp[], int count) {
    if (count > 0) {
        printf("\nEmployee List:\n");
        printf("ID\tName\t\tAge\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t%s\t\t%d\n", emp[i].id, emp[i].name, emp[i].age);
        }
        printf("\n");
    }
    else {
        printf("\nNo employees found in the database.\n\n");
    }
}

void searchEmployee(struct employee emp[], int count) {
    if (count > 0) {
        int empId;
        printf("\nEnter ID of the employee to search: ");
        scanf("%d", &empId);
        for (int i = 0; i < count; i++) {
            if (empId == emp[i].id) {
                printf("\nEmployee Found!\n");
                printf("ID\tName\t\tAge\n");
                printf("%d\t%s\t\t%d\n\n", emp[i].id, emp[i].name, emp[i].age);
                return;
            }
        }
        printf("\nEmployee not found in the database.\n\n");
    }
    else {
        printf("\nNo employees found in the database.\n\n");
    }
}

void deleteEmployee(struct employee emp[], int* count) {
    if (*count > 0) {
        int empId, found = 0;
        printf("\nEnter ID of the employee to delete: ");
        scanf("%d", &empId);
        for (int i = 0; i < *count; i++) {
            if (empId == emp[i].id) {
                found = 1;
                for (int j = i; j < *count-1; j++) {
                    emp[j] = emp[j+1];
                }
                *count -= 1;
                break;
            }
        }
        if (found) {
            printf("\nEmployee deleted successfully!\n\n");
        }
        else {
            printf("\nEmployee not found in the database.\n\n");
        }
    }
    else {
        printf("\nNo employees found in the database.\n\n");
    }
}

int main() {
    struct employee emp[MAX_RECORDS];
    int count = 0, choice;
    do {
        printf("Employee Database Simulation\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Quit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEmployee(emp, &count);
                break;
            case 2:
                displayEmployees(emp, count);
                break;
            case 3:
                searchEmployee(emp, count);
                break;
            case 4:
                deleteEmployee(emp, &count);
                break;
            case 5:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}