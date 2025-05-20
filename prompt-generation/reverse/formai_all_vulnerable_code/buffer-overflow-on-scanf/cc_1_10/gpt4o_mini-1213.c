//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addProduct(Warehouse *warehouse, int id, const char *name, int quantity, float price) {
    if (warehouse->count >= MAX_PRODUCTS) {
        printf("Warehouse is full, cannot add more products.\n");
        return;
    }
    Product *newProduct = &warehouse->products[warehouse->count];
    newProduct->id = id;
    strncpy(newProduct->name, name, NAME_LENGTH);
    newProduct->quantity = quantity;
    newProduct->price = price;
    warehouse->count++;
    printf("Product added: %s\n", newProduct->name);
}

void removeProduct(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            printf("Removing product: %s\n", warehouse->products[i].name);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->count--;
            return;
        }
    }
    printf("Product ID %d not found.\n", id);
}

void listProducts(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }
    printf("Available Products:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse->products[i].id, 
               warehouse->products[i].name, 
               warehouse->products[i].quantity, 
               warehouse->products[i].price);
    }
}

void updateProductQuantity(Warehouse *warehouse, int id, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            warehouse->products[i].quantity += quantity;
            printf("Updated product '%s' to new quantity: %d\n", 
                   warehouse->products[i].name, 
                   warehouse->products[i].quantity);
            return;
        }
    }
    printf("Product ID %d not found for quantity update.\n", id);
}

float calculateInventoryValue(const Warehouse *warehouse) {
    float totalValue = 0.0;
    for (int i = 0; i < warehouse->count; i++) {
        totalValue += warehouse->products[i].quantity * warehouse->products[i].price;
    }
    return totalValue;
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice, id, quantity;
    char name[NAME_LENGTH];
    float price;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. List Products\n");
        printf("4. Update Product Quantity\n");
        printf("5. Calculate Inventory Value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                addProduct(&warehouse, id, name, quantity, price);
                break;

            case 2:
                printf("Enter Product ID to remove: ");
                scanf("%d", &id);
                removeProduct(&warehouse, id);
                break;

            case 3:
                listProducts(&warehouse);
                break;

            case 4:
                printf("Enter Product ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter Quantity (positive to add, negative to remove): ");
                scanf("%d", &quantity);
                updateProductQuantity(&warehouse, id, quantity);
                break;

            case 5:
                printf("Total Inventory Value: $%.2f\n", calculateInventoryValue(&warehouse));
                break;

            case 0:
                printf("Exiting the system. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}