//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Warehouse;

void addProduct(Warehouse *warehouse) {
    if (warehouse->count >= MAX_PRODUCTS) {
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    warehouse->products[warehouse->count] = newProduct;
    warehouse->count++;
    printf("Product added successfully!\n");
}

void displayProducts(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }
    printf("\nProducts in Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Product %d: %s | Quantity: %d | Price: %.2f\n", 
               i + 1, warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

void searchProduct(const Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            printf("Found: %s | Quantity: %d | Price: %.2f\n", 
                   warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateProduct(Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter product name to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            printf("Current Quantity: %d | Current Price: %.2f\n", 
                   warehouse->products[i].quantity, warehouse->products[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->products[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct(Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter product name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product\n");
    printf("4. Update Product\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
}

int main() {
    Warehouse warehouse = {.count = 0};
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&warehouse);
                break;
            case 2:
                displayProducts(&warehouse);
                break;
            case 3:
                searchProduct(&warehouse);
                break;
            case 4:
                updateProduct(&warehouse);
                break;
            case 5:
                deleteProduct(&warehouse);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}