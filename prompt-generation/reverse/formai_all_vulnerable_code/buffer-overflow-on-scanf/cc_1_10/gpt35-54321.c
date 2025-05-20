//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10

typedef struct {
    int id;
    char *name;
    int quantity;
} Product;

Product product_inventory[MAX_PRODUCTS];

int num_of_products = 0;

void add_product(int id, char *name, int quantity) {
    if (num_of_products >= MAX_PRODUCTS) {
        printf("Error: maximum number of products reached.\n");
    }
    else {
        Product new_product;
        new_product.id = id;
        new_product.name = strdup(name);
        new_product.quantity = quantity;
        product_inventory[num_of_products] = new_product;
        num_of_products++;
    }
}

void print_products() {
    printf("Product Inventory:\n");
    printf("-------------------\n");
    for (int i = 0; i < num_of_products; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", product_inventory[i].id, product_inventory[i].name, product_inventory[i].quantity);
    }
}

void decrease_quantity(int id, int amount) {
    for (int i = 0; i < num_of_products; i++) {
        if (product_inventory[i].id == id) {
            if (product_inventory[i].quantity < amount) {
                printf("Error: not enough quantity available.\n");
            }
            else {
                product_inventory[i].quantity -= amount;
                printf("Success: quantity decreased.\n");
            }
            return;
        }
    }
    printf("Error: product not found.\n");
}

void increase_quantity(int id, int amount) {
    for (int i = 0; i < num_of_products; i++) {
        if (product_inventory[i].id == id) {
            product_inventory[i].quantity += amount;
            return;
        }
    }
    printf("Error: product not found.\n");
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    printf("----------------------------------------\n");
    while (1) {
        char command[10];
        printf("Enter a command (add, print, decrease, increase, exit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            int id, quantity;
            printf("Enter product ID: ");
            scanf("%d", &id);
            char name[50];
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            add_product(id, name, quantity);
        }
        else if (strcmp(command, "print") == 0) {
            print_products();
        }
        else if (strcmp(command, "decrease") == 0) {
            int id, amount;
            printf("Enter product ID: ");
            scanf("%d", &id);
            printf("Enter amount to decrease: ");
            scanf("%d", &amount);
            decrease_quantity(id, amount);
        }
        else if (strcmp(command, "increase") == 0) {
            int id, amount;
            printf("Enter product ID: ");
            scanf("%d", &id);
            printf("Enter amount to increase: ");
            scanf("%d", &amount);
            increase_quantity(id, amount);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}