//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products a store can hold
#define MAX_PRODUCTS 100

// Define a struct for product objects
typedef struct Product {
    char name[30];
    float price;
    int quantity;
} Product;

// Define a struct for the inventory of the store
typedef struct Inventory {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

// Function to add a new product to the store's inventory
void addProduct(Inventory *inventory) {
    // Only add a product if the store has space in its inventory
    if (inventory->count < MAX_PRODUCTS) {
        // Prompt the user to enter the name and price of the new product
        char name[30];
        float price;
        printf("Enter the name of the new product: ");
        scanf("%s", name);
        printf("Enter the price of the new product: ");
        scanf("%f", &price);
        // Create a new product object with the user's input
        Product newProduct;
        strcpy(newProduct.name, name);
        newProduct.price = price;
        newProduct.quantity = 0;
        // Add the new product to the inventory
        inventory->products[inventory->count] = newProduct;
        inventory->count++;
        printf("New product added to the inventory.\n");
    } else {
        printf("The inventory is full. Cannot add any more products.\n");
    }
}

// Function to remove a product from the store's inventory
void removeProduct(Inventory *inventory) {
    // Prompt the user to enter the name of the product to be removed
    char name[30];
    printf("Enter the name of the product to be removed: ");
    scanf("%s", name);
    // Iterate through the inventory to find the product with the specified name
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            // If the product is found, remove it from the inventory
            int j;
            for (j = i; j < inventory->count-1; j++) {
                inventory->products[j] = inventory->products[j+1];
            }
            inventory->count--;
            printf("Product removed from the inventory.\n");
            return;
        }
    }
    // If the product is not found, print an error message
    printf("Product not found in the inventory.\n");
}

// Function to update the quantity of a product in the store's inventory
void updateQuantity(Inventory *inventory) {
    // Prompt the user to enter the name of the product to be updated
    char name[30];
    printf("Enter the name of the product to be updated: ");
    scanf("%s", name);
    // Iterate through the inventory to find the product with the specified name
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            // If the product is found, prompt the user to enter the new quantity
            int quantity;
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);
            // Update the quantity of the product in the inventory
            inventory->products[i].quantity = quantity;
            printf("Quantity updated for the product.\n");
            return;
        }
    }
    // If the product is not found, print an error message
    printf("Product not found in the inventory.\n");
}

// Function to find a product in the store's inventory by name
Product* findProductByName(Inventory *inventory, char *name) {
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

// Function to sell a product to a customer
void sellProduct(Inventory *inventory) {
    // Prompt the user to enter the name of the product to be sold
    char name[30];
    printf("Enter the name of the product to be sold: ");
    scanf("%s", name);
    // Find the product in the inventory
    Product *product = findProductByName(inventory, name);
    if (product != NULL) {
        // If the product is found, prompt the user to enter the quantity to be sold
        int quantity;
        printf("Enter the quantity to be sold: ");
        scanf("%d", &quantity);
        if (product->quantity >= quantity) {
            // If the store has enough of the product, update the quantity
            product->quantity -= quantity;
            // Print the total cost of the sale
            float cost = quantity * product->price;
            printf("Total cost: $%.2f\n", cost);
        } else {
            // If the store does not have enough of the product, print an error message
            printf("Insufficient quantity. The store only has %d %s.\n", product->quantity, product->name);
        }
    } else {
        // If the product is not found, print an error message
        printf("Product not found in the inventory.\n");
    }
}

// Main function to run the program
int main() {
    // Create an empty inventory for the store
    Inventory inventory;
    inventory.count = 0;
    // Display the menu options to the user and prompt them to choose an option
    int choice;
    while (1) {
        printf("\n==== Medical Store Management System ====\n");
        printf("1. Add new product\n");
        printf("2. Remove product\n");
        printf("3. Update quantity\n");
        printf("4. Sell product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                removeProduct(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                sellProduct(&inventory);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}