//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ada Lovelace-inspired struct to represent inventory items
struct Product {
    char name[50];
    int stock;
};

// Function to calculate the sum of inventory stock
int calculateStockSum(struct Product inventory[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += inventory[i].stock;
    }
    return sum;
}

// Function to print inventory items with their stock levels
void printInventory(struct Product inventory[], int size) {
    printf("\nInventory Report:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d units\n", inventory[i].name, inventory[i].stock);
    }
}

// Function to add a new product to the inventory
void addProduct(struct Product inventory[], int* size, char newProductName[], int newProductStock) {
    if (*size >= 100) {
        printf("Error: Inventory is full.\n");
        return;
    }

    strcpy(inventory[*size].name, newProductName);
    inventory[*size].stock = newProductStock;
    (*size)++;
}

int main() {
    struct Product inventory[100];
    int size = 0;

    // Ada Lovelace-inspired loop for user input
    for (;;) {
        printf("\nCommand: > ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "QUIT") == 0) {
            break;
        } else if (strcmp(command, "ADD") == 0) {
            char newProductName[50];
            int newProductStock;
            printf("Enter product name: ");
            scanf("%s", newProductName);
            printf("Enter product stock level: ");
            scanf("%d", &newProductStock);
            addProduct(inventory, &size, newProductName, newProductStock);
        } else if (strcmp(command, "SHOW") == 0) {
            printInventory(inventory, size);
        } else if (strcmp(command, "STOCK") == 0) {
            int totalStock = calculateStockSum(inventory, size);
            printf("Total inventory stock: %d units\n", totalStock);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}