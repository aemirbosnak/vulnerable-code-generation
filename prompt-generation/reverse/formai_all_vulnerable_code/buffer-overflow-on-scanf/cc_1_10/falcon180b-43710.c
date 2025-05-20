//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int id;
    float salary;
} Employee;

void addItem(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\nItems in the warehouse:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %d units - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void addEmployee(Employee employees[], int *size) {
    printf("Enter employee name: ");
    scanf("%s", employees[*size].name);
    printf("Enter employee ID: ");
    scanf("%d", &employees[*size].id);
    printf("Enter employee salary: ");
    scanf("%f", &employees[*size].salary);
    (*size)++;
}

void displayEmployees(Employee employees[], int size) {
    printf("\nEmployees in the warehouse:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - ID: %d - Salary: $%.2f\n", employees[i].name, employees[i].id, employees[i].salary);
    }
}

int main() {
    Item items[MAX_SIZE];
    int itemSize = 0;

    Employee employees[MAX_SIZE];
    int employeeSize = 0;

    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Add employee\n");
        printf("4. Display employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &itemSize);
                break;
            case 2:
                displayItems(items, itemSize);
                break;
            case 3:
                addEmployee(employees, &employeeSize);
                break;
            case 4:
                displayEmployees(employees, employeeSize);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}