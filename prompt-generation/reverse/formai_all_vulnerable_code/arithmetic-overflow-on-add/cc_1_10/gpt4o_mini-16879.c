//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
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
    
    Product *product = &warehouse->products[warehouse->count];
    
    printf("Enter product ID: ");
    scanf("%d", &product->id);
    
    printf("Enter product name: ");
    scanf(" %[^\n]", product->name);
    
    printf("Enter quantity: ");
    scanf("%d", &product->quantity);
    
    printf("Enter price: ");
    scanf("%f", &product->price);
    
    warehouse->count++;
    printf("Product added successfully!\n");
}

void updateProduct(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", warehouse->products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->products[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void deleteProduct(Warehouse *warehouse) {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            printf("Deleting product: %s\n", warehouse->products[i].name);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void listProducts(Warehouse *warehouse) {
    printf("==== Product List ====\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                warehouse->products[i].id,
                warehouse->products[i].name,
                warehouse->products[i].quantity,
                warehouse->products[i].price);
    }
}

void manageWarehouse(Warehouse *warehouse) {
    int choice;
    do {
        printf("\n1. Add Product\n2. Update Product\n3. Delete Product\n4. List Products\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(warehouse);
                break;
            case 2:
                updateProduct(warehouse);
                break;
            case 3:
                deleteProduct(warehouse);
                break;
            case 4:
                listProducts(warehouse);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    manageWarehouse(&warehouse);
    
    return 0;
}