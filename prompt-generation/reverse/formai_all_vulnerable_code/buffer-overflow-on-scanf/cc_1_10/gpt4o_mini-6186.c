//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
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

void addProduct(Warehouse *warehouse) {
    if (warehouse->count >= MAX_PRODUCTS) {
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = warehouse->count + 1;
    
    printf("Enter product name: ");
    fgets(newProduct.name, MAX_NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    getchar(); // Clear the newline character from the buffer

    warehouse->products[warehouse->count] = newProduct;
    warehouse->count++;
    printf("Product added successfully!\n");
}

void removeProduct(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty! Cannot remove products.\n");
        return;
    }
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    getchar(); // Clear the newline character from the buffer

    if (id <= 0 || id > warehouse->count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < warehouse->count - 1; i++) {
        warehouse->products[i] = warehouse->products[i + 1];
    }
    
    warehouse->count--;
    printf("Product removed successfully!\n");
}

void listProducts(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty!\n");
        return;
    }

    printf("\nProducts in Warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
            warehouse->products[i].id, 
            warehouse->products[i].name, 
            warehouse->products[i].quantity, 
            warehouse->products[i].price);
    }
}

void updateProduct(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty! Cannot update products.\n");
        return;
    }
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    getchar(); // Clear the newline character from the buffer

    if (id <= 0 || id > warehouse->count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &warehouse->products[id - 1];
    
    printf("Update product name (current: %s): ", product->name);
    fgets(product->name, MAX_NAME_LENGTH, stdin);
    product->name[strcspn(product->name, "\n")] = 0; // Remove newline

    printf("Update product quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);
    printf("Update product price (current: %.2f): ", product->price);
    scanf("%f", &product->price);
    getchar(); // Clear the newline character from the buffer

    printf("Product updated successfully!\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. List Products\n");
    printf("4. Update Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer
        
        switch (choice) {
            case 1:
                addProduct(&warehouse);
                break;
            case 2:
                removeProduct(&warehouse);
                break;
            case 3:
                listProducts(&warehouse);
                break;
            case 4:
                updateProduct(&warehouse);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}