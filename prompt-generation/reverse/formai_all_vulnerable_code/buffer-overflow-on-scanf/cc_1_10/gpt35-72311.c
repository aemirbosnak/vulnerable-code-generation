//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 20
#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    float price;
    int quantity;
} Product;

int addProduct(Product inventory[], int size);
int removeProduct(Product inventory[], int size);
void displayInventory(Product inventory[], int size);

int main() {
    Product inventory[MAX_PRODUCTS];
    int size = 0;
    char option;

    while (1) {
        printf("\n\nProduct Inventory System");
        printf("\n1. Add Product");
        printf("\n2. Remove Product");
        printf("\n3. Display Inventory");
        printf("\n4. Exit\n");

        printf("\nEnter option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                size = addProduct(inventory, size);
                break;
            case '2':
                size = removeProduct(inventory, size);
                break;
            case '3':
                displayInventory(inventory, size);
                break;
            case '4':
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }
}

int addProduct(Product inventory[], int size) {
    if (size >= MAX_PRODUCTS) {
        printf("\nInventory is full! Cannot add more products.\n");
        return size;
    }

    printf("\nEnter product name: ");
    scanf(" %[^\n]s", inventory[size].name);

    printf("Enter product price: ");
    scanf(" %f", &inventory[size].price);

    printf("Enter product quantity: ");
    scanf(" %d", &inventory[size].quantity);

    printf("\nProduct added successfully!\n");

    return size + 1;
}

int removeProduct(Product inventory[], int size) {
    if (size <= 0) {
        printf("\nInventory is empty! Cannot remove any products.\n");
        return size;
    }

    int index;
    char name[MAX_NAME];

    printf("\nEnter product name to remove: ");
    scanf(" %[^\n]s", name);

    for (index = 0; index < size; index++) {
        if (strcmp(name, inventory[index].name) == 0) {
            printf("\nProduct removed successfully: %s - %.2f - %d\n", inventory[index].name, inventory[index].price, inventory[index].quantity);
            size--;

            for (; index < size; index++) {
                inventory[index] = inventory[index + 1];
            }

            return size;
        }
    }

    printf("\nProduct not found! Please try again.\n");

    return size;
}

void displayInventory(Product inventory[], int size) {
    if (size <= 0) {
        printf("\nInventory is empty! There are no products to display.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("%-20s %-20s %-20s\n", "Name", "Price", "Quantity");

    int index;
    for (index = 0; index < size; index++) {
        printf("%-20s %-20.2f %-20d\n", inventory[index].name, inventory[index].price, inventory[index].quantity);
    }
}