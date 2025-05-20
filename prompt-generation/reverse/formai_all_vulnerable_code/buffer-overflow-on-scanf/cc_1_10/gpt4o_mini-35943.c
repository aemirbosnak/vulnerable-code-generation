//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[30];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

void addProduct(Inventory *inventory) {
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Oh dear, our inventory is overflowing with love! Can't add more products.\n");
        return;
    }
    Product p;
    printf("Enter the name of your beloved product: ");
    scanf("%s", p.name);
    printf("How many of these sweethearts do we have? ");
    scanf("%d", &p.quantity);
    printf("And what will be the price to win their hearts? ");
    scanf("%f", &p.price);
    inventory->products[inventory->count++] = p;
    printf("Ah, we've added a new love to our inventory: %s!\n", p.name);
}

void removeProduct(Inventory *inventory) {
    char name[30];
    printf("Whose heart shall we break? Enter the name of the product: ");
    scanf("%s", name);
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->count--;
            printf("Ah, we parted ways with %s, a bittersweet moment.\n", name);
            return;
        }
    }
    printf("Alas, we could not find that product, our love remains unreturned.\n");
}

void viewProducts(Inventory *inventory) {
    if (inventory->count == 0) {
        printf("Our hearts are empty, there are no products to display.\n");
        return;
    }
    printf("\nHere lies the collection of our cherished products:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("Product: %s | Quantity: %d | Price: $%.2f\n",
               inventory->products[i].name,
               inventory->products[i].quantity,
               inventory->products[i].price);
    }
}

void romanceMenu() {
    printf("\nWelcome to the Heartfelt Product Inventory System!\n");
    printf("1. Add a product to our love story\n");
    printf("2. Remove a product from our memories\n");
    printf("3. View all products in our heart\n");
    printf("4. Exit this love story\n");
}

int main() {
    Inventory inventory = { .count = 0 };
    int choice;

    while (1) {
        romanceMenu();
        printf("What shall we do, dear? Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                removeProduct(&inventory);
                break;
            case 3:
                viewProducts(&inventory);
                break;
            case 4:
                printf("Until we meet again, sweet lover... 💕\n");
                exit(0);
            default:
                printf("Oh dear, that choice is a little too wild for this heart.\n");
        }
    }

    return 0;
}