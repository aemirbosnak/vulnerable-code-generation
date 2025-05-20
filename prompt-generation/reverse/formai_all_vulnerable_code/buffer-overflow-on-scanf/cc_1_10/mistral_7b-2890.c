//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
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

void remove_product(char *name) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (; i < num_products - 1; i++) {
                strcpy(inventory[i].name, inventory[i + 1].name);
                inventory[i].quantity = inventory[i + 1].quantity;
            }
            num_products--;
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

void update_quantity(char *name, int new_quantity) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = new_quantity;
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

void display_inventory() {
    int i;

    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10], name[PRODUCT_NAME_LENGTH], temp_name[PRODUCT_NAME_LENGTH];
    int quantity, choice;

    while (1) {
        printf("\nProduct Inventory System\n1. Add product\n2. Remove product\n3. Update product quantity\n4. Display inventory\n5. Exit\nEnter your choice: ");
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
                printf("Enter product name: ");
                scanf("%s", name);
                remove_product(name);
                break;
            case '3':
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter new product quantity: ");
                scanf("%d", &quantity);
                update_quantity(name, quantity);
                break;
            case '4':
                display_inventory();
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}