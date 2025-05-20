//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity, float price) {
    if (num_products < MAX_PRODUCTS) {
        strcpy(inventory[num_products].name, name);
        inventory[num_products].quantity = quantity;
        inventory[num_products].price = price;
        num_products++;
    } else {
        printf("Sorry, you cannot add more products. The inventory is full.\n");
    }
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i] = inventory[num_products - 1];
            num_products--;
            break;
        }
    }
}

void update_product(char *name, int quantity, float price) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            break;
        }
    }
}

void print_inventory() {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;

    while (1) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf(" %s", name);
                printf("Enter quantity: ");
                scanf(" %d", &quantity);
                printf("Enter price: ");
                scanf(" %f", &price);
                add_product(name, quantity, price);
                break;
            case 2:
                printf("Enter product name: ");
                scanf(" %s", name);
                remove_product(name);
                break;
            case 3:
                printf("Enter product name: ");
                scanf(" %s", name);
                printf("Enter quantity: ");
                scanf(" %d", &quantity);
                printf("Enter price: ");
                scanf(" %f", &price);
                update_product(name, quantity, price);
                break;
            case 4:
                print_inventory();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}