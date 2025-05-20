//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_SIZE];
    int count;
} Inventory;

void addProduct(Inventory *inventory) {
    int id, quantity;
    float price;
    char name[50];

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Check if product ID already exists
    for(int i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == id) {
            printf("Product ID already exists\n");
            return;
        }
    }

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%f", &price);

    // Add product to inventory
    Product product = {id, name, quantity, price};
    inventory->products[inventory->count++] = product;

    printf("Product added to inventory\n");
}

void displayInventory(Inventory inventory) {
    printf("Product Inventory:\n");
    printf("------------------\n");

    if(inventory.count == 0) {
        printf("No products in inventory\n");
        return;
    }

    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------------\n");

    for(int i = 0; i < inventory.count; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", inventory.products[i].id,
            inventory.products[i].name, inventory.products[i].quantity,
            inventory.products[i].price);
    }
}

void removeProduct(Inventory *inventory) {
    int id;

    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    for(int i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == id) {
            // Remove product from inventory
            for(int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }

            inventory->count--;
            printf("Product removed from inventory\n");
            return;
        }
    }

    printf("Product not found in inventory\n");
}

void updateProduct(Inventory *inventory) {
    int id, quantity;
    float price;
    char name[50];

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == id) {
            printf("Enter updated product name: ");
            scanf("%s", name);

            printf("Enter updated product quantity: ");
            scanf("%d", &quantity);

            printf("Enter updated product price: ");
            scanf("%f", &price);

            // Update product in inventory
            Product product = {id, name, quantity, price};
            inventory->products[i] = product;

            printf("Product updated in inventory\n");
            return;
        }
    }

    printf("Product not found in inventory\n");
}

int main() {
    Inventory inventory;
    inventory.count = 0;

    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("\n1. Add Product");
        printf("\n2. Display Inventory");
        printf("\n3. Remove Product");
        printf("\n4. Update Product");
        printf("\n5. Exit");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                removeProduct(&inventory);
                break;
            case 4:
                updateProduct(&inventory);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 5);

    return 0;
}