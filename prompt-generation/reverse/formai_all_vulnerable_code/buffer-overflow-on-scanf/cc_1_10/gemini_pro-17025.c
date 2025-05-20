//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>


// Product struct
typedef struct Product {
    char name[20];
    int quantity;
    float price;
} Product;

// Inventory system functions
void addProduct(Product *inventory, int *count);
void removeProduct(Product *inventory, int *count);
void updateProduct(Product *inventory, int count);
void printInventory(Product *inventory, int count);

// Main function
int main() {
    // Initialize the inventory system
    Product inventory[100];
    int count = 0;

    // Run the inventory system loop
    while (1) {
        // Display the menu
        printf("\n--- Inventory System ---\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");

        // Get the user's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                removeProduct(inventory, &count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                printInventory(inventory, count);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Add a product to the inventory
void addProduct(Product *inventory, int *count) {
    // Get the product information from the user
    printf("Enter product name: ");
    scanf(" %s", inventory[*count].name);
    printf("Enter product quantity: ");
    scanf(" %d", &inventory[*count].quantity);
    printf("Enter product price: ");
    scanf(" %f", &inventory[*count].price);

    // Increment the product count
    (*count)++;
}

// Remove a product from the inventory
void removeProduct(Product *inventory, int *count) {
    // Get the product name from the user
    char name[20];
    printf("Enter product name: ");
    scanf(" %s", name);

    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was found
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    // Remove the product from the inventory
    for (int i = index; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement the product count
    (*count)--;
}

// Update a product in the inventory
void updateProduct(Product *inventory, int count) {
    // Get the product name from the user
    char name[20];
    printf("Enter product name: ");
    scanf(" %s", name);

    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was found
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    // Update the product information
    printf("Enter new product quantity: ");
    scanf(" %d", &inventory[index].quantity);
    printf("Enter new product price: ");
    scanf(" %f", &inventory[index].price);
}

// Print the inventory
void printInventory(Product *inventory, int count) {
    // Print the inventory header
    printf("\n--- Inventory ---\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");

    // Print the inventory items
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}