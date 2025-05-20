//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define max number of warehouses, items and orders
#define MAX_WAREHOUSE 10
#define MAX_ITEM 50
#define MAX_ORDERS 100

// Global variables
char warehouseNames[MAX_WAREHOUSE][20];
int warehouseCapacity[MAX_WAREHOUSE];
int numWarehouses = 0;

char itemNames[MAX_ITEM][20];
float itemPrices[MAX_ITEM];
int numItems = 0;

char orderNames[MAX_ORDERS][20];
int orderQuantities[MAX_ORDERS][MAX_ITEM];
int orderWarehouse[MAX_ORDERS];
int numOrders = 0;

// Function to add a new warehouse
void addNewWarehouse() {
    if (numWarehouses >= MAX_WAREHOUSE) {
        printf("No more warehouse can be added to the system.\n");
        return;
    }

    printf("Enter the name of the new warehouse: ");
    scanf("%s", warehouseNames[numWarehouses]);

    printf("Enter the capacity of the new warehouse: ");
    scanf("%d", &warehouseCapacity[numWarehouses]);

    printf("New warehouse successfully added!\n");
    numWarehouses++;
}

// Function to add a new item
void addNewItem() {
    if (numItems >= MAX_ITEM) {
        printf("No more item can be added to the system.\n");
        return;
    }

    printf("Enter the name of the new item: ");
    scanf("%s", itemNames[numItems]);

    printf("Enter the price of the new item: ");
    scanf("%f", &itemPrices[numItems]);

    printf("New item successfully added!\n");
    numItems++;
}

// Function to place a new order
void placeNewOrder() {
    if (numOrders >= MAX_ORDERS) {
        printf("No more order can be placed at the moment.\n");
        return;
    }

    printf("Enter the name of the new order: ");
    scanf("%s", orderNames[numOrders]);

    // Enter the items and quantities for the order
    printf("Enter the items and quantities for the order:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: ", itemNames[i]);
        scanf("%d", &orderQuantities[numOrders][i]);
    }

    // Enter the warehouse for the order
    printf("Enter the warehouse for the order:\n");
    for (int i = 0; i < numWarehouses; i++) {
        printf("%d. %s\n", i+1, warehouseNames[i]);
    }
    scanf("%d", &orderWarehouse[numOrders]);

    printf("New order successfully placed!\n");
    numOrders++;
}

// Function to print all warehouses
void printWarehouses() {
    printf("List of all warehouses:\n");
    for (int i = 0; i < numWarehouses; i++) {
        printf("%d. %s, Capacity: %d\n", i+1, warehouseNames[i], warehouseCapacity[i]);
    }
}

// Function to print all items
void printItems() {
    printf("List of all items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s, Price: %0.2f\n", i+1, itemNames[i], itemPrices[i]);
    }
}

// Function to print all orders
void printOrders() {
    printf("List of all orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%d. %s, Warehouse: %s\n", i+1, orderNames[i], warehouseNames[orderWarehouse[i]-1]);
        printf("   Items:\n");
        for (int j = 0; j < numItems; j++) {
            if (orderQuantities[i][j] > 0) {
                printf("   - %s: %d\n", itemNames[j], orderQuantities[i][j]);
            }
        }
    }
}

// Main function
int main() {
    printf("Welcome to the CyberWarehouse Management System!\n");

    // Menu loop
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add new warehouse\n");
        printf("2. Add new item\n");
        printf("3. Place new order\n");
        printf("4. Print all warehouses\n");
        printf("5. Print all items\n");
        printf("6. Print all orders\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewWarehouse();
                break;
            case 2:
                addNewItem();
                break;
            case 3:
                placeNewOrder();
                break;
            case 4:
                printWarehouses();
                break;
            case 5:
                printItems();
                break;
            case 6:
                printOrders();
                break;
            case 7:
                printf("Thank you for using the CyberWarehouse Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 7);

    return 0;
}