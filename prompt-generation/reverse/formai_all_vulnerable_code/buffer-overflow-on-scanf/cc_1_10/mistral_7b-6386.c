//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int current_product = 0;

void add_product(char* name, int quantity) {
    if (current_product >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    strcpy(inventory[current_product].name, name);
    inventory[current_product].quantity = quantity;
    current_product++;
}

void display_inventory() {
    printf("\nCURRENT INVENTORY:\n");

    for (int i = 0; i < current_product; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[10];
    char product_name[MAX_NAME_LENGTH];
    int product_quantity;

    while (1) {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter product name: ");
                scanf("%s", product_name);
                printf("Enter product quantity: ");
                scanf("%d", &product_quantity);
                add_product(product_name, product_quantity);
                break;
            case '2':
                display_inventory();
                break;
            case '3':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}