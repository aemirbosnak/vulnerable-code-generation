//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 150
#define MAX_PRICE 100000

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int price;
    int quantity;
};

void addProduct(struct product* inventory, int size, char* name, char* description, int price, int quantity) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].quantity == 0) {
            strcpy(inventory[i].name, name);
            strcpy(inventory[i].description, description);
            inventory[i].price = price;
            inventory[i].quantity = quantity;
            printf("Product added to inventory: %s\n", name);
            return;
        }
    }
    printf("Inventory is full. ");
}

void removeProduct(struct product* inventory, int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = 0;
            printf("Product removed from inventory: %s\n", name);
            return;
        }
    }
    printf("Product not found in inventory. ");
}

void displayInventory(struct product* inventory, int size) {
    printf("\nInventory:\n");
    for (int i = 0; i < size; i++) {
        if (inventory[i].quantity > 0) {
            printf("%-20s %-50s %10d %10d\n", inventory[i].name, inventory[i].description, inventory[i].price, inventory[i].quantity);
        }
    }
}

int main() {
    struct product inventory[MAX_PRODUCTS];
    int size = 0;

    while (size < MAX_PRODUCTS) {
        printf("\nEnter product name (up to %d characters): ", MAX_NAME_LENGTH);
        scanf("%s", inventory[size].name);

        printf("Enter product description (up to %d characters): ", MAX_DESCRIPTION_LENGTH);
        scanf("%s", inventory[size].description);

        printf("Enter product price: ");
        scanf("%d", &inventory[size].price);

        printf("Enter product quantity: ");
        scanf("%d", &inventory[size].quantity);

        size++;
    }

    int choice;
    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                addProduct(inventory, size, name, "", 0, 0);
                break;
            case 2:
                printf("Enter product name: ");
                char name2[MAX_NAME_LENGTH];
                scanf("%s", name2);
                removeProduct(inventory, size, name2);
                break;
            case 3:
                displayInventory(inventory, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. ");
        }
    }

    return 0;
}