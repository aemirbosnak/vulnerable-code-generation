//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
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

void addProduct(Warehouse *warehouse) {
    if (warehouse->count >= MAX_PRODUCTS) {
        printf("Warehouse is full!\n");
        return;
    }
    
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    getchar(); // To consume the newline after the last scanf
    fgets(newProduct.name, NAME_LENGTH, stdin);
    strtok(newProduct.name, "\n"); // Remove trailing newline
    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Price: ");
    scanf("%f", &newProduct.price);

    warehouse->products[warehouse->count] = newProduct;
    warehouse->count++;
    printf("Product added successfully!\n");
}

void displayProducts(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }
    
    printf("\nProducts in Warehouse:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        Product p = warehouse->products[i];
        printf("%-10d %-30s %-10d $%-9.2f\n", p.id, p.name, p.quantity, p.price);
    }
}

void updateProduct(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            printf("Updating Product: %s\n", warehouse->products[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &warehouse->products[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &warehouse->products[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void deleteProduct(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    while (1) {
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
                updateProduct(&warehouse);
                break;
            case 4:
                deleteProduct(&warehouse);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}