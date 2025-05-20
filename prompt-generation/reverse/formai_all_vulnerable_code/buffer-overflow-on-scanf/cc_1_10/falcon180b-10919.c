//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Define the structure of a product
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

// Function to add a new product to the inventory
void addProduct(Product* inventory, int numProducts, char* name, int quantity, float price) {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    strncpy(inventory[numProducts].name, name, MAX_NAME_LENGTH);
    inventory[numProducts].quantity = quantity;
    inventory[numProducts].price = price;
    printf("Product added successfully.\n");
}

// Function to update the quantity of a product
void updateQuantity(Product* inventory, int numProducts, char* name, int quantity) {
    int i;

    for (i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity;
            printf("Product quantity updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

// Function to display the inventory
void displayInventory(Product* inventory, int numProducts) {
    printf("Inventory:\n");
    printf("Name\tQuantity\tPrice\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter product name (or type 'quit' to exit): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter product quantity: ");
        int quantity;
        scanf("%d", &quantity);

        printf("Enter product price: ");
        float price;
        scanf("%f", &price);

        addProduct(inventory, numProducts, name, quantity, price);
    }

    printf("\nInitial inventory:\n");
    displayInventory(inventory, numProducts);

    while (1) {
        printf("\nEnter '1' to add a product, '2' to update product quantity, '3' to display inventory, or 'quit' to exit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter product name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);

            printf("Enter product quantity: ");
            int quantity;
            scanf("%d", &quantity);

            printf("Enter product price: ");
            float price;
            scanf("%f", &price);

            addProduct(inventory, numProducts, name, quantity, price);
        } else if (choice == '2') {
            printf("Enter product name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);

            printf("Enter quantity to update: ");
            int quantity;
            scanf("%d", &quantity);

            updateQuantity(inventory, numProducts, name, quantity);
        } else if (choice == '3') {
            printf("\nCurrent inventory:\n");
            displayInventory(inventory, numProducts);
        } else if (choice == 'quit') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}