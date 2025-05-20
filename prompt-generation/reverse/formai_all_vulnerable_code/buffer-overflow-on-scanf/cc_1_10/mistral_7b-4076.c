//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int stock;
} Product;

Product inventory[MAX_PRODUCTS];

void add_product(char *name, int quantity) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].stock == 0) {
            strcpy(inventory[i].name, name);
            inventory[i].stock = quantity;
            break;
        }
    }
}

int find_product(char *name) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity, index;

    memset(inventory, 0, sizeof(inventory));

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Check Stock\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter stock quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                printf("Product added successfully!\n");
                break;

            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                index = find_product(name);
                if (index == -1) {
                    printf("Product not found!\n");
                } else {
                    printf("Stock of %s: %d\n", inventory[index].name, inventory[index].stock);
                }
                break;

            case 3:
                printf("Exiting the system...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}