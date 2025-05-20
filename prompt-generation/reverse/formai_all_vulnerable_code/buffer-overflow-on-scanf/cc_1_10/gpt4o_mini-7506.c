//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addProduct(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->count < MAX_PRODUCTS) {
        strcpy(warehouse->products[warehouse->count].name, name);
        warehouse->products[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Oh beloved, I have added %s with quantity %d to our collection!\n", name, quantity);
    } else {
        printf("Alas, my love, the warehouse is full! We cannot hold more products.\n");
    }
}

void listProducts(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("My sweet, our collection is empty. No products to cherish here.\n");
        return;
    }

    printf("Here are the treasures of our hearts:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("  - %s: %d\n", warehouse->products[i].name, warehouse->products[i].quantity);
    }
}

void sellProduct(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            if (warehouse->products[i].quantity >= quantity) {
                warehouse->products[i].quantity -= quantity;
                printf("Oh darling, we sold %d of %s! A sweet exchange of affection in the market!\n", quantity, name);
                return;
            } else {
                printf("Oh no, my love! We don't have enough %s to fulfill this wish.\n", name);
                return;
            }
        }
    }
    printf("Alas, my heart aches, we do not possess %s in our warehouse.\n", name);
}

void romanticMenu() {
    printf("Welcome, my dear, to our Warehouse Management System!\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Sell Product\n");
    printf("4. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    char name[NAME_LEN];
    int quantity;

    while (1) {
        romanticMenu();
        printf("Choose your action, my love (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the product you wish to add, my darling: ");
                scanf("%s", name);
                printf("How many of %s shall we add to our precious collection? ", name);
                scanf("%d", &quantity);
                addProduct(&warehouse, name, quantity);
                break;
            case 2:
                listProducts(&warehouse);
                break;
            case 3:
                printf("What sweet product shall we sell today, love? ");
                scanf("%s", name);
                printf("How many of %s do you wish to sell, dearest? ", name);
                scanf("%d", &quantity);
                sellProduct(&warehouse, name, quantity);
                break;
            case 4:
                printf("Farewell, my darling! Until our next rendezvous.\n");
                exit(0);
            default:
                printf("Oh, my sweet! That choice is beyond my comprehension, try again.\n");
        }
    }

    return 0;
}