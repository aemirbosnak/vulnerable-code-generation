//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
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

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void addProduct();
void displayInventory();
void updateProduct();
void searchProduct();

int main() {
    int choice;
    do {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void addProduct() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product new_product;
    new_product.id = product_count + 1; // Simple ID based on count
    printf("Enter product name: ");
    getchar(); // consume newline
    fgets(new_product.name, NAME_LENGTH, stdin);
    strtok(new_product.name, "\n"); // Remove trailing newline

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    inventory[product_count] = new_product;
    product_count++;
    printf("Product added successfully!\n");
}

void displayInventory() {
    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    if (product_count == 0) {
        printf("No products in inventory.\n");
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *p = &inventory[id - 1]; // Adjust ID to zero-based index

    printf("Updating product: %s\n", p->name);
    printf("Current quantity: %d\n", p->quantity);
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);

    printf("Current price: %.2f\n", p->price);
    printf("Enter new price: ");
    scanf("%f", &p->price);

    printf("Product updated successfully!\n");
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    getchar(); // consume newline
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove trailing newline
    
    int found = 0;
    for (int i = 0; i < product_count; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("Found Product -> ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}