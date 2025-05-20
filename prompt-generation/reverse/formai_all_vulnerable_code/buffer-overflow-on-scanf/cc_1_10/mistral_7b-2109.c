//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Sorry, our inventory is full.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;

    printf("Thank you for adding %s with %d units.\n", name, quantity);
    num_products++;
}

void display_inventory() {
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char product_name[MAX_NAME_LENGTH];
    int product_quantity;

    while (1) {
        printf("\n-- Grateful Inventory System --\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product Name: ");
                scanf("%s", product_name);
                printf("Enter Quantity: ");
                scanf("%d", &product_quantity);
                add_product(product_name, product_quantity);
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Thank you for using our Grateful Inventory System. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}