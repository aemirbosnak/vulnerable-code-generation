//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i+1, inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char input[MAX_NAME_LENGTH];
    int quantity, command, index;

    while (1) {
        printf("\n1. Add product\n2. Display inventory\n3. Exit\n");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", input);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(input, quantity);
                break;

            case 2:
                display_inventory();
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}