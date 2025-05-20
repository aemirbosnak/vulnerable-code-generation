//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_QUANTITY_SIZE 10

typedef struct {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units\n", i+1, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10], product_name[PRODUCT_NAME_SIZE];
    int quantity, index, choice;

    while (1) {
        printf("\nProduct Inventory System\n1. Add Product\n2. Display Inventory\n3. Quit\nEnter your choice: ");
        scanf("%s", command);

        if (strcmp(command, "1") == 0) {
            printf("Enter product name: ");
            scanf("%s", product_name);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            add_product(product_name, quantity);
        } else if (strcmp(command, "2") == 0) {
            display_inventory();
        } else if (strcmp(command, "3") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}