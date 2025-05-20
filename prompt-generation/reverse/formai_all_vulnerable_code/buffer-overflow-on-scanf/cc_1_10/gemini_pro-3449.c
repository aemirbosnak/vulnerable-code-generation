//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    int id;
    char name[50];
    int quantity;
    float price;

    printf("Enter product ID: ");
    scanf("%d", &id);

    printf("Enter product name: ");
    scanf(" %[^\n]", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%f", &price);

    inventory[num_products].id = id;
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    inventory[num_products].price = price;

    num_products++;
}

void remove_product() {
    int id;

    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }

    for (; i < num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    num_products--;
}

void update_product() {
    int id;

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }

    int choice;

    printf("Choose field to update:\n");
    printf("1. Name\n");
    printf("2. Quantity\n");
    printf("3. Price\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new product name: ");
            scanf(" %[^\n]", inventory[i].name);
            break;
        case 2:
            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            break;
        case 3:
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void display_inventory() {
    printf("\nInventory:\n\n");

    int i;
    for (i = 0; i < num_products; i++) {
        printf("%d. %s\n",
               inventory[i].id,
               inventory[i].name);
        printf("    Quantity: %d\n", inventory[i].quantity);
        printf("    Price: %.2f\n\n", inventory[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("-------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display inventory\n");
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
                display_inventory();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}