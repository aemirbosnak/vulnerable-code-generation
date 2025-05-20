//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define product structure
typedef struct Product {
    char name[50];
    int stock;
    float price;
} Product;

// Function to add new product to inventory
void addProduct(Product inventory[], int *size, char name[], int stock, float price) {
    if (*size >= 100) {
        printf("Inventory is full!\n");
        return;
    }

    strcpy(inventory[*size].name, name);
    inventory[*size].stock = stock;
    inventory[*size].price = price;
    (*size)++;
}

// Function to update product stock
void updateStock(Product inventory[], int size, char name[], int newStock) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].stock = newStock;
            printf("Stock for %s updated successfully.\n", name);
            return;
        }
    }

    printf("Product %s not found in inventory.\n", name);
}

// Function to sell product
void sellProduct(Product inventory[], int size, char name[], int quantity) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].stock >= quantity) {
                inventory[i].stock -= quantity;
                printf("Sold %d units of %s for a total of $%.2f.\n", quantity, name, inventory[i].stock * inventory[i].price);
                return;
            } else {
                printf("Insufficient stock for %s.\n", name);
                return;
            }
        }
    }

    printf("Product %s not found in inventory.\n", name);
}

// Function to print inventory
void printInventory(Product inventory[], int size) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d units ($%.2f each)\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

int main() {
    srand(time(NULL));

    // Initialize inventory with some products
    Product inventory[10];
    int size = 0;

    addProduct(inventory, &size, "Apple", 50, 0.5);
    addProduct(inventory, &size, "Banana", 30, 0.3);
    addProduct(inventory, &size, "Orange", 20, 0.4);

    // Randomly update stock for a product
    char updateName[50];
    int newStock = rand() % 100 + 1;

    printf("Enter product name to update stock: ");
    scanf("%s", updateName);

    updateStock(inventory, size, updateName, newStock);

    // Sell products
    char sellName[50];
    int sellQuantity;

    printf("Enter product name to sell: ");
    scanf("%s", sellName);
    printf("Enter quantity to sell: ");
    scanf("%d", &sellQuantity);

    sellProduct(inventory, size, sellName, sellQuantity);

    // Print updated inventory
    printInventory(inventory, size);

    return 0;
}