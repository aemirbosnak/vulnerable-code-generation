//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50
#define PRODUCT_QUANTITY_LENGTH 10

typedef struct Product {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void display_inventory() {
    printf("\nProduct Inventory\n");
    printf("------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i + 1, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10];
    char name[PRODUCT_NAME_LENGTH];
    int quantity;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("-------------------------\n");
        printf("Enter command (ADD/DISP/QUIT): ");
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            add_product(name, quantity);
        } else if (strcmp(command, "DISP") == 0) {
            display_inventory();
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}