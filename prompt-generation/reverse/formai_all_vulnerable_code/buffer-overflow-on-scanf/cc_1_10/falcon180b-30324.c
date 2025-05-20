//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

void add_product(struct product *inventory, int num_products) {
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);
}

void display_products(struct product *inventory, int num_products) {
    printf("\nProduct Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_quantity(struct product *inventory, int num_products) {
    int product_id;
    printf("Enter product ID to update quantity: ");
    scanf("%d", &product_id);
    if (product_id >= 0 && product_id < num_products) {
        printf("Enter new quantity: ");
        scanf("%d", &inventory[product_id].quantity);
    } else {
        printf("Invalid product ID.\n");
    }
}

void main() {
    struct product inventory[MAX_PRODUCTS];
    int num_products = 0;

    printf("Enter number of products: ");
    scanf("%d", &num_products);

    if (num_products > MAX_PRODUCTS) {
        printf("Error: Maximum number of products is %d.\n", MAX_PRODUCTS);
        exit(1);
    }

    for (int i = 0; i < num_products; i++) {
        add_product(inventory, i);
    }

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n2. Display products\n3. Update quantity\n4. Exit\n");
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
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}