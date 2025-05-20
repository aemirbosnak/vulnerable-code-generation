//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSES 10
#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    int id;
    char name[50];
    char address[100];
} Customer;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    int id;
    char name[50];
    char address[100];
    float rent;
} Warehouse;

int num_warehouses = 0;
Warehouse warehouses[MAX_WAREHOUSES];

int add_warehouse() {
    if (num_warehouses >= MAX_WAREHOUSES) {
        printf("Error: Maximum number of warehouses reached.\n");
        return -1;
    }

    printf("Enter warehouse name: ");
    scanf("%s", warehouses[num_warehouses].name);
    printf("Enter warehouse address: ");
    scanf("%s", warehouses[num_warehouses].address);
    printf("Enter warehouse rent: ");
    scanf("%f", &warehouses[num_warehouses].rent);

    num_warehouses++;

    return 0;
}

int main() {
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add warehouse\n");
        printf("2. View warehouses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_warehouse();
            break;

        case 2:
            printf("\nList of Warehouses:\n");
            for (int i = 0; i < num_warehouses; i++) {
                printf("%d. %s - Rent: $%.2f\n", i + 1, warehouses[i].name, warehouses[i].rent);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}