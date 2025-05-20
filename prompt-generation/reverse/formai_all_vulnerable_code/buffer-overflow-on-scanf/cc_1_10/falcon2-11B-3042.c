//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int age;
    char* address;
    int salary;
} Employee;

void addEmployee(Employee* employees, int size) {
    int index = size;
    printf("Enter employee name: ");
    scanf("%s", employees[index].name);
    printf("Enter employee age: ");
    scanf("%d", &employees[index].age);
    printf("Enter employee address: ");
    scanf("%s", employees[index].address);
    printf("Enter employee salary: ");
    scanf("%d", &employees[index].salary);
    printf("Employee '%s' added successfully!\n", employees[index].name);
    employees[index].name = NULL;
    employees[index].age = 0;
    employees[index].address = NULL;
    employees[index].salary = 0;
}

void searchEmployee(Employee* employees, int size, char* name) {
    int index = 0;
    while (employees[index].name!= NULL) {
        if (strcmp(name, employees[index].name) == 0) {
            printf("Employee '%s' found at index %d\n", name, index);
            return;
        }
        index++;
    }
    printf("Employee not found!\n");
}

void updateEmployee(Employee* employees, int size, char* name, int age, char* address, int salary) {
    int index = 0;
    while (employees[index].name!= NULL) {
        if (strcmp(name, employees[index].name) == 0) {
            employees[index].age = age;
            strncpy(employees[index].address, address, sizeof(employees[index].address));
            employees[index].salary = salary;
            printf("Employee '%s' updated successfully!\n", name);
            return;
        }
        index++;
    }
    printf("Employee not found!\n");
}

void deleteEmployee(Employee* employees, int size, char* name) {
    int index = 0;
    while (employees[index].name!= NULL) {
        if (strcmp(name, employees[index].name) == 0) {
            for (int i = index; i < size - 1; i++) {
                employees[i] = employees[i + 1];
            }
            employees[size - 1].name = NULL;
            employees[size - 1].age = 0;
            employees[size - 1].address = NULL;
            employees[size - 1].salary = 0;
            printf("Employee '%s' deleted successfully!\n", name);
            return;
        }
        index++;
    }
    printf("Employee not found!\n");
}

int main() {
    Employee employees[10];
    int size = 0;
    int choice;
    while (1) {
        printf("1. Add employee\n2. Search employee\n3. Update employee\n4. Delete employee\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(employees, size);
                break;
            case 2:
                printf("Enter employee name: ");
                scanf("%s", employees[size].name);
                searchEmployee(employees, size, employees[size].name);
                break;
            case 3:
                printf("Enter employee name: ");
                scanf("%s", employees[size].name);
                printf("Enter new age: ");
                scanf("%d", &employees[size].age);
                printf("Enter new address: ");
                scanf("%s", employees[size].address);
                printf("Enter new salary: ");
                scanf("%d", &employees[size].salary);
                updateEmployee(employees, size, employees[size].name, employees[size].age, employees[size].address, employees[size].salary);
                break;
            case 4:
                printf("Enter employee name: ");
                scanf("%s", employees[size].name);
                deleteEmployee(employees, size, employees[size].name);
                break;
            case 5:
                printf("Thank you for using the C Database Indexing System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}