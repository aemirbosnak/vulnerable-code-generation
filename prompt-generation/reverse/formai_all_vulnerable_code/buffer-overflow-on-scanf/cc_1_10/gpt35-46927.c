//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>

#define MAX_PRODUCTS 100 // Maximum number of products in the inventory.

struct Product {
    char name[20];
    float price;
    int quantity;
};

void display_menu() {
    printf("\n===== Product Inventory System =====\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display inventory\n");
    printf("4. Exit\n");
    printf("Enter your selection: ");
}

int get_selection() {
    int selection;
    scanf("%d", &selection);
    return selection;
}

void add_product(struct Product inventory[], int *count) {
    struct Product new_product;

    printf("\nEnter product name: ");
    scanf("%s", new_product.name);

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    inventory[*count] = new_product;
    *count += 1;

    printf("\nProduct added successfully!\n");
}

void remove_product(struct Product inventory[], int *count) {
    char product_name[20];
    int found = 0;

    printf("\nEnter product name to remove: ");
    scanf("%s", product_name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(product_name, inventory[i].name) == 0) {
            found = 1;
            inventory[i] = inventory[*count-1];
            *count -= 1;
            printf("\nProduct removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found in inventory!\n");
    }
}

void display_inventory(struct Product inventory[], int count) {
    printf("\nProduct name\tPrice\tQuantity\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    struct Product inventory[MAX_PRODUCTS];
    int count = 0;

    int selection = 0;
    while (selection != 4) {
        display_menu();
        selection = get_selection();

        switch (selection) {
            case 1:
                add_product(inventory, &count);
                break;
            case 2:
                remove_product(inventory, &count);
                break;
            case 3:
                display_inventory(inventory, count);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid selection. Please try again.\n");
                break;
        }
    }

    return 0;
}