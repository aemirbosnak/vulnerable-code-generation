//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

int num_items = 0;
struct product inventory[MAX_ITEMS];

void add_product() {
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    struct product new_product;
    printf("Enter product name:\n");
    scanf("%s", new_product.name);
    printf("Enter quantity:\n");
    scanf("%d", &new_product.quantity);
    printf("Enter price:\n");
    scanf("%f", &new_product.price);

    inventory[num_items] = new_product;
    num_items++;

    printf("Product added successfully.\n");
}

void remove_product() {
    if (num_items == 0) {
        printf("Inventory is empty. Nothing to remove.\n");
        return;
    }

    char name_to_remove[50];
    printf("Enter name of product to remove:\n");
    scanf("%s", name_to_remove);

    int removed = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(name_to_remove, inventory[i].name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_items--;
            removed = 1;
            printf("Product removed successfully.\n");
            break;
        }
    }

    if (!removed) {
        printf("Product not found in inventory. Cannot remove.\n");
    }
}

void view_inventory() {
    if (num_items == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("Product Name\tQuantity\tPrice\n");
        for (int i = 0; i < num_items; i++) {
            printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int main() {
    int selection;
    char input[50];

    while (1) {
        printf("Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
        printf("Enter selection:\n");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
        }

        printf("Press enter to continue.\n");
        fgets(input, 50, stdin);
        fgets(input, 50, stdin);
    }

    return 0;
}