//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

product *inventory;
int inventory_size = 0;

void add_product() {
    product new_product;

    printf("Enter product ID: ");
    scanf("%d", &new_product.id);

    printf("Enter product name: ");
    scanf("%s", new_product.name);

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    inventory = realloc(inventory, (inventory_size + 1) * sizeof(product));
    inventory[inventory_size++] = new_product;
}

void remove_product() {
    int id;

    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < inventory_size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventory_size--;
            break;
        }
    }
}

void update_product() {
    int id;

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i].id == id) {
            printf("Enter new product name: ");
            scanf("%s", inventory[i].name);

            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            break;
        }
    }
}

void print_inventory() {
    printf("Product Inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("Product Inventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Print Inventory\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                print_inventory();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}