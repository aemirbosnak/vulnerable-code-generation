//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: real-life
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

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add product.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void remove_product(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].quantity = inventory[j+1].quantity;
            }
            num_products--;
            break;
        }
    }
}

void view_inventory() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10];
    char name[PRODUCT_NAME_LENGTH];
    int quantity;

    while (1) {
        printf("\nProduct Inventory System\n"
               "1. Add Product\n"
               "2. Remove Product\n"
               "3. View Inventory\n"
               "4. Exit\n"
               "Enter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;

            case '2':
                printf("Enter product name to remove: ");
                scanf("%s", name);
                remove_product(name);
                break;

            case '3':
                view_inventory();
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}