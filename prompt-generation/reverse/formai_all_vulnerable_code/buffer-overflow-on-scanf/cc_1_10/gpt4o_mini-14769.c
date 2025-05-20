//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

void displayInventory(Inventory *inv) {
    if (inv->count == 0) {
        printf("Alas! The inventory is but an empty grave, void of life.\n\n");
        return;
    }

    printf("Behold the Inventory, a treasure trove of delights:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < inv->count; i++) {
        printf("Product: %s | Quantity: %d | Price: %.2f Ducats\n",
               inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
    printf("-------------------------------------------------\n\n");
}

void addProduct(Inventory *inv) {
    if (inv->count >= MAX_PRODUCTS) {
        printf("Alas! We cannot add more products; the inventory is full.\n");
        return;
    }

    Product newProduct;
    printf("Enter the name of the product, dear soul: ");
    scanf("%s", newProduct.name);
    printf("Enter the quantity of this fair product: ");
    scanf("%d", &newProduct.quantity);
    printf("Bestow upon us the price for this product in Ducats: ");
    scanf("%f", &newProduct.price);

    inv->products[inv->count++] = newProduct;
    printf("Huzzah! %s has been added to our noble inventory!\n\n", newProduct.name);
}

void removeProduct(Inventory *inv) {
    char name[NAME_LENGTH];
    printf("Whisper to me the name of the product you wish to cast away: ");
    scanf("%s", name);

    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            inv->products[i] = inv->products[--inv->count]; // Remove product and shift left
            printf("The product %s hath been removed from our inventory.\n\n", name);
            return;
        }
    }
    printf("Alas! The product named %s is but a phantom in our inventory.\n\n", name);
}

void searchProduct(Inventory *inv) {
    char name[NAME_LENGTH];
    printf("State the name of the product you seek: ");
    scanf("%s", name);

    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            printf("Ah! The product %s is here, with quantity %d and price %.2f Ducats!\n\n",
                   name, inv->products[i].quantity, inv->products[i].price);
            return;
        }
    }
    printf("Despair not! The product %s wanders not in our inventory.\n\n", name);
}

void menu() {
    printf("Welcome to the Verona Product Inventory System!\n");
    printf("1. Display Inventory\n");
    printf("2. Add Product\n");
    printf("3. Remove Product\n");
    printf("4. Search Product\n");
    printf("5. Exit\n\n");
}

int main() {
    Inventory inventory = {.count = 0};
    int choice;

    do {
        menu();
        printf("Choose thy desire (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayInventory(&inventory); break;
            case 2: addProduct(&inventory); break;
            case 3: removeProduct(&inventory); break;
            case 4: searchProduct(&inventory); break;
            case 5: printf("Farewell! May your goods ever flourish!\n\n"); break;
            default: printf("A pox upon thee! Choose a valid option!\n\n"); break;
        }
    } while (choice != 5);

    return 0;
}