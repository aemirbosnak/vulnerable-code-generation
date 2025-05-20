//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[MAX_SIZE];
    float salary;
} Employee;

void addProduct(Product products[], int *size) {
    printf("Enter product name: ");
    scanf("%s", products[*size].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*size].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*size].price);
    (*size)++;
}

void displayProducts(Product products[], int size) {
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i + 1, products[i].name, products[i].quantity, products[i].price);
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
    printf("Employee ID\tEmployee Name\tSalary\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

int main() {
    Product products[MAX_SIZE];
    int productSize = 0;

    Employee employees[MAX_SIZE];
    int employeeSize = 0;

    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n2. Display products\n3. Add employee\n4. Display employees\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, &productSize);
            break;
        case 2:
            displayProducts(products, productSize);
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