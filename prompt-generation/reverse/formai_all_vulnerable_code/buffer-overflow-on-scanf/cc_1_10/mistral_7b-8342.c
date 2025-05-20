//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("The inventory is full.\n");
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
            int j;
            for (j = i; j < num_products - 1; j++) {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].quantity = inventory[j+1].quantity;
            }
            num_products--;
            return;
        }
    }
    printf("The product %s does not exist in the inventory.\n", name);
}

void display_inventory() {
    int i;
    printf("\nCurrent Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char command[50], name[MAX_NAME_LENGTH];
    int quantity, i;

    while (1) {
        printf("\nSherlock Holmes' Inventory System\n");
        printf("Please enter a command: add <product> <quantity> | remove <product> | display | exit\n");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &quantity);
            add_product(name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", name);
            remove_product(name);
        } else if (strcmp(command, "display") == 0) {
            display_inventory();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}