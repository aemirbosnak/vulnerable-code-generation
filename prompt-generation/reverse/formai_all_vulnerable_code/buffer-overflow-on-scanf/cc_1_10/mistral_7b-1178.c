//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

typedef struct Product {
    char name[50];
    int stock;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int stock) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].stock = stock;
    num_products++;
}

void remove_product(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product %s removed.\n", name);
            return;
        }
    }

    printf("Product %s not found.\n", name);
}

void display_inventory() {
    printf("\nCurrent inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].stock);
    }
}

int main() {
    char command[20];
    char name[50];
    int stock;

    while (1) {
        printf("\nProduct inventory system\n1. Add product\n2. Remove product\n3. Display inventory\n4. Quit\nEnter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter stock: ");
                scanf("%d", &stock);
                add_product(name, stock);
                break;

            case '2':
                printf("Enter product name: ");
                scanf("%s", name);
                remove_product(name);
                break;

            case '3':
                display_inventory();
                break;

            case '4':
                printf("Quitting.\n");
                exit(0);

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}