//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int stock;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int stock, float price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].stock = stock;
    inventory[num_products].price = price;
    num_products++;
}

void display_inventory() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - Stock: %d, Price: %.2f\n", i + 1, inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

int main() {
    char name[PRODUCT_NAME_LENGTH];
    int stock, choice;
    float price;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter stock: ");
                scanf("%d", &stock);
                printf("Enter price: ");
                scanf("%f", &price);
                add_product(name, stock, price);
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}