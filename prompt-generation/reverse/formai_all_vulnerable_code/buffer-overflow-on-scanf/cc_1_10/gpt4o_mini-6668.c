//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
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

void addProduct(Inventory *inventory, const char *name, int quantity, float price) {
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Oops! Inventory is full! Can't add more products.\n");
        return;
    }
    strcpy(inventory->products[inventory->count].name, name);
    inventory->products[inventory->count].quantity = quantity;
    inventory->products[inventory->count].price = price;
    inventory->count++;
    printf("Yay! Added %s to the inventory!\n", name);
}

void displayInventory(const Inventory *inventory) {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("Product %d: Name: %s, Quantity: %d, Price: $%.2f\n",
               i + 1, inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
    printf("-----------------\n");
}

Product* searchProduct(const Inventory *inventory, const char *name) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

void updateProduct(Inventory *inventory, const char *name, int quantity, float price) {
    Product *product = searchProduct(inventory, name);
    if (product) {
        product->quantity += quantity; // Adding quantity
        product->price = price; // Update the price
        printf("Hooray! Updated %s: New Quantity: %d, New Price: $%.2f\n", name, product->quantity, product->price);
    } else {
        printf("Oh no! Product %s not found.\n", name);
    }
}

void showMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Search Product\n");
    printf("4. Update Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Inventory inventory = { .count = 0 };
    int choice;
    char name[NAME_LENGTH];
    int quantity;
    float price;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addProduct(&inventory, name, quantity, price);
                break;

            case 2:
                displayInventory(&inventory);
                break;

            case 3:
                printf("Enter product name to search: ");
                scanf("%s", name);
                Product *product = searchProduct(&inventory, name);
                if (product) {
                    printf("Found %s: Quantity: %d, Price: $%.2f\n", product->name, product->quantity, product->price);
                } else {
                    printf("Sorry! Product %s not found in inventory.\n", name);
                }
                break;

            case 4:
                printf("Enter product name to update: ");
                scanf("%s", name);
                printf("Enter additional quantity: ");
                scanf("%d", &quantity);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateProduct(&inventory, name, quantity, price);
                break;

            case 5:
                printf("Exiting the program. Goodbye! 🎉\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}