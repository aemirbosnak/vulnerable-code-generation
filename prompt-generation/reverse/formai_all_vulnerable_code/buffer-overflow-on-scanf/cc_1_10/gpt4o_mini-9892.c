//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

void displayMenu();
void addProduct(Product *inventory, int *count);
void listProducts(Product *inventory, int count);
void updateProduct(Product *inventory, int count);
void searchProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(inventory, &count); break;
            case 2: listProducts(inventory, count); break;
            case 3: updateProduct(inventory, count); break;
            case 4: searchProduct(inventory, count); break;
            case 5: deleteProduct(inventory, &count); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Update Product\n");
    printf("4. Search Product\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    printf("Enter product name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter product ID: ");
    scanf("%d", &inventory[*count].id);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*count].price);

    (*count)++;
    printf("Product added successfully!\n");
}

void listProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < count; i++) {
        printf("Product ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("-------------------------\n");
    }
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void searchProduct(Product *inventory, int count) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Found product:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}