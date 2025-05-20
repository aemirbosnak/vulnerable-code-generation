//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct Inventory {
    int num_products;
    Product products[MAX_PRODUCTS];
} Inventory;

Inventory inv;

void addProduct(char name[], int quantity, float price) {
    if (inv.num_products >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    Product newProduct = { .quantity = quantity, .price = price };
    strcpy(newProduct.name, name);
    inv.products[inv.num_products++] = newProduct;
    printf("Added %d %s to inventory at a price of $%.2f per unit\n", quantity, name, price);
}

void removeProduct(char name[], int quantity) {
    for (int i = 0; i < inv.num_products; i++) {
        if (strcmp(inv.products[i].name, name) == 0) {
            if (inv.products[i].quantity >= quantity) {
                inv.products[i].quantity -= quantity;
                printf("Removed %d %s from inventory\n", quantity, name);
            }
            else {
                printf("Not enough %s in inventory\n", name);
            }
            return;
        }
    }
    printf("%s not found in inventory\n", name);
}

void displayInventory() {
    printf("\n--- INVENTORY ---\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < inv.num_products; i++) {
        printf("%-20s %10d $%9.2f\n", inv.products[i].name, inv.products[i].quantity, inv.products[i].price);
    }
    printf("------------------\n");
}

int main() {
    inv.num_products = 0;
    int choice, quantity;
    char name[50];
    float price;
    bool running = true;
    while (running) {
        printf("Enter your choice:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price per unit: ");
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                removeProduct(name, quantity);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}