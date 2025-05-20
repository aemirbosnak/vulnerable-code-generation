//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    float price;
    int stock;
};

struct inventory {
    struct product products[MAX_PRODUCTS];
    int count;
};

struct inventory inv = { .count = 0 };

void add_product(struct product p) {
    if (inv.count >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }
    inv.products[inv.count++] = p;
    printf("Product added successfully.\n");
}

void print_product(struct product p) {
    printf("%d: %s ($%.2f) - %d in stock.\n", p.id, p.name, p.price, p.stock);
}

void print_inventory() {
    if (inv.count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    for (int i = 0; i < inv.count; i++) {
        print_product(inv.products[i]);
    }
}

void sell_product(int id, int quantity) {
    for (int i = 0; i < inv.count; i++) {
        if (inv.products[i].id == id) {
            if (inv.products[i].stock < quantity) {
                printf("Not enough stock.\n");
                return;
            }
            inv.products[i].stock -= quantity;
            printf("%d x %s sold for $%.2f each. Total: $%.2f\n",
                   quantity, inv.products[i].name, inv.products[i].price,
                   quantity * inv.products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    char command[50];
    while (1) {
        printf("\nType a command (add, list, sell, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            struct product p;
            printf("Enter product name: ");
            scanf("%s", p.name);
            printf("Enter product price: ");
            scanf("%f", &p.price);
            printf("Enter product stock: ");
            scanf("%d", &p.stock);
            p.id = inv.count + 1;
            add_product(p);
        }
        else if (strcmp(command, "list") == 0) {
            print_inventory();
        }
        else if (strcmp(command, "sell") == 0) {
            int id, quantity;
            printf("Enter product ID: ");
            scanf("%d", &id);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            sell_product(id, quantity);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            return 0;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}