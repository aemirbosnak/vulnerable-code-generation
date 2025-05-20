//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_SIZE 50

typedef struct Product {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int qty, float price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = qty;
    inventory[num_products].price = price;

    num_products++;
}

void remove_product(char* name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            i--;
            break;
        }
    }
}

void view_inventory() {
    printf("Product Name\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    char command[10], name[PRODUCT_NAME_SIZE];
    int qty;
    float price;

    while (1) {
        printf("\nEnter command (add/remove/view/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &qty);
            printf("Enter price: ");
            scanf("%f", &price);
            add_product(name, qty, price);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            remove_product(name);
        } else if (strcmp(command, "view") == 0) {
            view_inventory();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}