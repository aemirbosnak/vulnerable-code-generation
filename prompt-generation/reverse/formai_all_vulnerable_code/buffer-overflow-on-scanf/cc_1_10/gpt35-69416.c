//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for Product
struct Product {
    int productId;
    char productName[50];
    int quantity;
    float price;
};

// Define a function to add new product to the inventory
void addProduct(struct Product inventory[], int *pInventorySize) {
    printf("Enter product name: ");
    scanf("%s", inventory[*pInventorySize].productName);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*pInventorySize].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*pInventorySize].price);

    // Assign a unique ID to each product
    inventory[*pInventorySize].productId = *pInventorySize + 1;

    // Increment the inventory size
    (*pInventorySize)++;
}

// Define a function to display all products in the inventory
void displayInventory(struct Product inventory[], int inventorySize) {
    printf("\n--- Inventory ---\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].productId, inventory[i].productName, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------\n\n");
}

// Define a function to search for a product in the inventory by ID and return its index
int findProductById(struct Product inventory[], int inventorySize, int productId) {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].productId == productId) {
            return i;
        }
    }
    return -1;
}

// Define a function to update a product in the inventory by ID
void updateProduct(struct Product inventory[], int inventorySize) {
    int productId, productIndex, quantity;
    float price;
    printf("Enter product ID: ");
    scanf("%d", &productId);
    productIndex = findProductById(inventory, inventorySize, productId);
    if (productIndex == -1) {
        printf("Product with ID %d not found.\n", productId);
    } else {
        printf("Enter new product name: ");
        scanf("%s", inventory[productIndex].productName);
        printf("Enter new product quantity: ");
        scanf("%d", &quantity);
        inventory[productIndex].quantity += quantity;
        printf("Enter new product price: ");
        scanf("%f", &price);
        inventory[productIndex].price = price;
        printf("Product with ID %d updated successfully.\n", productId);
    }
}

// Define a function to delete a product from the inventory by ID
void deleteProduct(struct Product inventory[], int *pInventorySize) {
    int productId, productIndex;
    printf("Enter product ID: ");
    scanf("%d", &productId);
    productIndex = findProductById(inventory, *pInventorySize, productId);
    if (productIndex == -1) {
        printf("Product with ID %d not found.\n", productId);
    } else {
        for (int i = productIndex; i < *pInventorySize - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*pInventorySize)--;
        printf("Product with ID %d deleted successfully.\n", productId);
    }
}

int main() {
    struct Product inventory[100];
    int inventorySize = 0;
    int choice;

    while (1) {
        printf("Medical Store Management System\n");
        printf("1. Add new product\n");
        printf("2. Display inventory\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &inventorySize);
                break;
            case 2:
                displayInventory(inventory, inventorySize);
                break;
            case 3:
                updateProduct(inventory, inventorySize);
                break;
            case 4:
                deleteProduct(inventory, &inventorySize);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}