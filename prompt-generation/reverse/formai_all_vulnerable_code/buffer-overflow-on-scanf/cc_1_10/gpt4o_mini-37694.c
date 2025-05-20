//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
    int quantity;
    float price;
} Product;

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Update Product\n");
    printf("4. Display Products\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);
    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter Price: ");
    scanf("%f", &newProduct.price);

    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void removeProduct(Product *inventory, int *count) {
    int id, i, found = 0;
    printf("Enter Product ID to remove: ");
    scanf("%d", &id);
    
    for (i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Product removed successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void updateProduct(Product *inventory, int count) {
    int id, i, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    for (i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Product: %s\n", inventory[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void displayProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory!\n");
        return;
    }

    printf("\nID\tName\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct(Product *inventory, int count) {
    int id, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("\nFound Product:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                removeProduct(inventory, &count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                displayProducts(inventory, count);
                break;
            case 5:
                searchProduct(inventory, count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}