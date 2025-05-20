//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    num_products++;
}

void remove_product() {
    char product_name[50];
    int i;

    printf("Enter product name to remove: ");
    scanf("%s", product_name);

    for (i = 0; i < num_products; i++) {
        if (strcmp(product_name, inventory[i].name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Product\n2. Remove Product\n3. Display Inventory\n4. Exit\n");
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
                display_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}