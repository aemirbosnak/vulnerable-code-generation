//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct Product {
    char name[MAX_NAME_LEN];
    int stock;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];

void add_product(char *name, int stock, float price) {
    for (int i = 0; i < MAX_PRODUCTS; ++i) {
        if (inventory[i].stock == 0) {
            strcpy(inventory[i].name, name);
            inventory[i].stock = stock;
            inventory[i].price = price;
            break;
        }
    }
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < MAX_PRODUCTS; ++i) {
        if (inventory[i].stock > 0) {
            printf("%s: %d units, $%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
        }
    }
}

int main() {
    char name[MAX_NAME_LEN];
    int stock, choice;
    float price;

    add_product("Apple", 50, 1.5);
    add_product("Banana", 30, 0.8);
    add_product("Orange", 20, 1.2);

    do {
        printf("\n1. Add Product\n2. Display Inventory\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Stock: ");
                scanf("%d", &stock);
                printf("Enter Price: ");
                scanf("%f", &price);
                add_product(name, stock, price);
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option! Try Again.\n");
        }
    } while (choice != 3);

    return 0;
}