//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_LENGTH 50
#define PRODUCT_QUANTITY_LENGTH 10

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

void initProducts(Product products[], int size) {
    for (int i = 0; i < size; i++) {
        products[i].quantity = 0;
        strcpy(products[i].name, "");
    }
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Check inventory\n");
    printf("4. Exit\n");
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int size = 0;

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX_PRODUCTS) {
                    printf("Inventory is full.\n");
                    break;
                }
                printf("Enter product name: ");
                scanf("%s", inventory[size].name);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[size].quantity);
                size++;
                break;

            case 2:
                if (size == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("Enter product name to remove: ");
                char name[PRODUCT_NAME_LENGTH];
                scanf("%s", name);

                for (int i = 0; i < size; i++) {
                    if (strcmp(inventory[i].name, name) == 0) {
                        inventory[i].quantity = 0;
                        strcpy(inventory[i].name, "");
                        size--;
                        i--;
                        break;
                    }
                }
                break;

            case 3:
                if (size == 0) {
                    printf("Inventory is empty.\n");
                    break;
                }
                printf("\nCurrent inventory:\n");
                for (int i = 0; i < size; i++) {
                    printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}