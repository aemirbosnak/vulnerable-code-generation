//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int totalProducts;
} Warehouse;

// Function prototypes
void addProduct(Warehouse *warehouse);
void removeProduct(Warehouse *warehouse);
void displayProducts(Warehouse *warehouse);
void restockProduct(Warehouse *warehouse);
void checkStock(Warehouse *warehouse);

int main() {
    Warehouse warehouse = { .totalProducts = 0 };
    int choice;

    while (1) {
        printf("-------------------------------------------------\n");
        printf("WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM!\n");
        printf("-------------------------------------------------\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Restock Product\n");
        printf("5. Check Stock\n");
        printf("6. Exit\n");
        printf("-------------------------------------------------\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addProduct(&warehouse); 
                break;
            case 2: 
                removeProduct(&warehouse); 
                break;
            case 3: 
                displayProducts(&warehouse); 
                break;
            case 4: 
                restockProduct(&warehouse); 
                break;
            case 5: 
                checkStock(&warehouse); 
                break;
            case 6: 
                printf("Exiting... Thank you for using the system!\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again...\n");
        }
    }

    return 0;
}

void addProduct(Warehouse *warehouse) {
    if (warehouse->totalProducts >= MAX_PRODUCTS) {
        printf("OH NO! Cannot add more products, warehouse full!\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    warehouse->products[warehouse->totalProducts++] = newProduct;
    printf("Product added successfully!\n");
}

void removeProduct(Warehouse *warehouse) {
    char name[50];
    printf("Enter the product name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->totalProducts; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->products[i] = warehouse->products[--warehouse->totalProducts];
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product not found! You must be dreaming!\n");
}

void displayProducts(Warehouse *warehouse) {
    if (warehouse->totalProducts == 0) {
        printf("YIKES! No products in the warehouse!\n");
        return;
    }

    printf("Current products in the warehouse:\n");
    for (int i = 0; i < warehouse->totalProducts; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", 
                i + 1, warehouse->products[i].name, 
                warehouse->products[i].quantity, 
                warehouse->products[i].price);
    }
}

void restockProduct(Warehouse *warehouse) {
    char name[50];
    int quantity;
    printf("Enter the product name to restock: ");
    scanf("%s", name);
    printf("Enter the quantity to restock: ");
    scanf("%d", &quantity);

    for (int i = 0; i < warehouse->totalProducts; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->products[i].quantity += quantity;
            printf("Product restocked successfully!\n");
            return;
        }
    }
    printf("Product not found! Wait, this can't be happening!\n");
}

void checkStock(Warehouse *warehouse) {
    int lowStockThreshold = 10;
    printf("Checking stock levels...\n");
    for (int i = 0; i < warehouse->totalProducts; i++) {
        if (warehouse->products[i].quantity < lowStockThreshold) {
            printf("WARNING: Low stock for %s - Only %d left!\n", 
                   warehouse->products[i].name, 
                   warehouse->products[i].quantity);
        }
    }
}