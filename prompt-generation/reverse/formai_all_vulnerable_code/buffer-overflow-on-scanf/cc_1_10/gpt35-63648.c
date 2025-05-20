//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
};

int num_products = 0;
struct Product inventory[MAX_PRODUCTS];

void add_product(char* name, int quantity, double price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products\n");
        return;
    }
    struct Product new_product;
    strncpy(new_product.name, name, MAX_NAME_LENGTH - 1);
    new_product.quantity = quantity;
    new_product.price = price;
    inventory[num_products] = new_product;
    num_products++;
    printf("New product added to inventory:\n");
    printf("Name: %s\nQuantity: %d\nPrice: $%.2f\n", name, quantity, price);
}

void remove_product(char* name) {
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found in inventory\n");
        return;
    }
    for (int i = index; i < num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    num_products--;
    printf("Product removed from inventory: %s\n", name);
}

void show_inventory() {
    printf("Current inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s (%d) - $%.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
    while (1) {
        printf("1. Add product to inventory\n");
        printf("2. Remove product from inventory\n");
        printf("3. Show inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%lf", &price);
            add_product(name, quantity, price);
            break;
        case 2:
            printf("Enter product name: ");
            scanf("%s", name);
            remove_product(name);
            break;
        case 3:
            show_inventory();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            break;
        }
    }
    return 0;
}