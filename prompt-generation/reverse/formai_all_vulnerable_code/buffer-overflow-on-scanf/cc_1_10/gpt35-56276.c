//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product_t;

product_t inventory[MAX_PRODUCTS];

int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);

    printf("Product added successfully!\n");

    num_products++;
}

void remove_product() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the product you want to remove: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            num_products--;
            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("Product not found in inventory!\n");
}

void display_inventory() {
    printf("Inventory:\n");
    printf("%-30s | %-10s | %-10s\n", "Name", "Quantity", "Price");

    for (int i = 0; i < num_products; i++) {
        printf("%-30s | %-10d | %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {

    printf("Welcome to the Linux Torvalds Product Inventory System!\n");

    int choice = 0;
    do {
        printf("\nPlease choose an action:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Quit\n");

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
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}