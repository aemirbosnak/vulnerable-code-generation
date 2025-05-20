//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int size;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->size = 0;
}

int addProduct(Warehouse *warehouse, int id, const char *name, int quantity) {
    if (warehouse->size >= MAX_PRODUCTS) {
        printf("Warehouse is full, cannot add more products.\n");
        return -1;
    }
    warehouse->products[warehouse->size].id = id;
    strcpy(warehouse->products[warehouse->size].name, name);
    warehouse->products[warehouse->size].quantity = quantity;
    warehouse->size++;
    return 0;
}

void displayProducts(Warehouse *warehouse) {
    if (warehouse->size == 0) {
        printf("No products in warehouse.\n");
        return;
    }
    printf("\nCurrent Products in Warehouse:\n");
    printf("-------------------------------\n");
    for (int i = 0; i < warehouse->size; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse->products[i].id, warehouse->products[i].name, warehouse->products[i].quantity);
    }
    printf("-------------------------------\n");
}

int updateProductQuantity(Warehouse *warehouse, int id, int newQuantity) {
    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].id == id) {
            warehouse->products[i].quantity = newQuantity;
            printf("Updated Product ID: %d to Quantity: %d\n", id, newQuantity);
            return 0;
        }
    }
    printf("Product ID: %d not found.\n", id);
    return -1;
}

void removeProduct(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].id == id) {
            printf("Removing Product ID: %d from Warehouse.\n", id);
            for (int j = i; j < warehouse->size - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->size--;
            return;
        }
    }
    printf("Product ID: %d not found.\n", id);
}

void menu() {
    printf("--------- Warehouse Management System ---------\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product Quantity\n");
    printf("4. Remove Product\n");
    printf("5. Exit\n");
}

int main() {
    Warehouse myWarehouse;
    initializeWarehouse(&myWarehouse);

    int choice, id, quantity;
    char name[50];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Product Quantity: ");
                scanf("%d", &quantity);
                addProduct(&myWarehouse, id, name, quantity);
                break;
            case 2:
                displayProducts(&myWarehouse);
                break;
            case 3:
                printf("Enter Product ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(&myWarehouse, id, quantity);
                break;
            case 4:
                printf("Enter Product ID to remove: ");
                scanf("%d", &id);
                removeProduct(&myWarehouse, id);
                break;
            case 5:
                printf("Exiting Warehouse Management System. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}