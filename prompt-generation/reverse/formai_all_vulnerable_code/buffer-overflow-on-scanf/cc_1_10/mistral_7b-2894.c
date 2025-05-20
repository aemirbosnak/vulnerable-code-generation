//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: peaceful
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

void add_product(const char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void remove_product(const char *name) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product '%s' removed successfully.\n", name);
            return;
        }
    }

    printf("Error: Product '%s' not found in inventory.\n", name);
}

void display_inventory() {
    printf("\nCurrent inventory:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i + 1, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10];
    char name[PRODUCT_NAME_LENGTH];
    int quantity, index;

    while (1) {
        printf("\nProduct Inventory System\n"
               "1. Add product\n"
               "2. Remove product\n"
               "3. Display inventory\n"
               "4. Quit\n"
               "> ");
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
                display_inventory();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}