//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product warehouse[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Warehouse is full. Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = productCount + 1;  // Simple id generation
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    warehouse[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void viewInventory() {
    if (productCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("Current Inventory:\n");
    printf("%-5s %-25s %-10s\n", "ID", "Name", "Quantity");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-25s %-10d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void updateProductQuantity() {
    int id, newQuantity;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }
    printf("Enter new quantity for product ID %d: ", id);
    scanf("%d", &newQuantity);
    warehouse[id - 1].quantity = newQuantity;
    printf("Quantity updated successfully!\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. View Inventory\n");
    printf("3. Update Product Quantity\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                updateProductQuantity();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}