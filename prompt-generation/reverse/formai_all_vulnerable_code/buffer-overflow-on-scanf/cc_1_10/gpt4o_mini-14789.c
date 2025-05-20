//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Warehouse;

// Function prototypes
void addProduct(Warehouse *warehouse);
void removeProduct(Warehouse *warehouse);
void displayProducts(Warehouse *warehouse);
void updateProduct(Warehouse *warehouse);
void searchProduct(Warehouse *warehouse);
void menu();

int main() {
    Warehouse warehouse = { .count = 0 };
    menu(&warehouse);
    return 0;
}

void menu(Warehouse *warehouse) {
    int choice;
    
    do {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Update Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(warehouse);
                break;
            case 2:
                removeProduct(warehouse);
                break;
            case 3:
                displayProducts(warehouse);
                break;
            case 4:
                updateProduct(warehouse);
                break;
            case 5:
                searchProduct(warehouse);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

void addProduct(Warehouse *warehouse) {
    if (warehouse->count >= MAX_PRODUCTS) {
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]s", newProduct.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    
    warehouse->products[warehouse->count] = newProduct;
    warehouse->count++;
    printf("Product added successfully!\n");
}

void removeProduct(Warehouse *warehouse) {
    int id, i, found = 0;
    printf("Enter Product ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->count--;
            printf("Product removed successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void displayProducts(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }

    printf("\n--- List of Products ---\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               warehouse->products[i].id,
               warehouse->products[i].name,
               warehouse->products[i].quantity,
               warehouse->products[i].price);
    }
}

void updateProduct(Warehouse *warehouse) {
    int id, i, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            printf("Enter new Product Name: ");
            scanf(" %[^\n]s", warehouse->products[i].name);
            printf("Enter new Product Quantity: ");
            scanf("%d", &warehouse->products[i].quantity);
            printf("Enter new Product Price: ");
            scanf("%f", &warehouse->products[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void searchProduct(Warehouse *warehouse) {
    int id, i, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < warehouse->count; i++) {
        if (warehouse->products[i].id == id) {
            found = 1;
            printf("Product found - ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   warehouse->products[i].id,
                   warehouse->products[i].name,
                   warehouse->products[i].quantity,
                   warehouse->products[i].price);
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}