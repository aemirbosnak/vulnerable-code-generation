//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
};

void add_product(struct product* inventory, int num_products) {
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &inventory[num_products].price);
    printf("\nProduct added successfully.\n");
}

void display_products(struct product* inventory, int num_products) {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units - $%.2lf\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_quantity(struct product* inventory, int num_products) {
    printf("Enter product number to update: ");
    int product_number;
    scanf("%d", &product_number);
    if (product_number >= 1 && product_number <= num_products) {
        printf("Enter new quantity: ");
        scanf("%d", &inventory[product_number-1].quantity);
        printf("\nQuantity updated successfully.\n");
    } else {
        printf("Invalid product number.\n");
    }
}

void main() {
    struct product inventory[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the Romeo and Juliet Product Inventory System.\n");
    while (num_products < MAX_PRODUCTS) {
        printf("\nEnter 1 to add a product, 2 to display products, 3 to update quantity, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(inventory, num_products);
                break;
            case 2:
                display_products(inventory, num_products);
                break;
            case 3:
                update_quantity(inventory, num_products);
                break;
            case 0:
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}