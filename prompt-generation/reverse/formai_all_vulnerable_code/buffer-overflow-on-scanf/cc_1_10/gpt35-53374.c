//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Define max inventory size and product name length
#define MAX_INVENTORY_SIZE 1000
#define MAX_PRODUCT_NAME_LENGTH 50

// Define struct to store product info
typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int id;
    float price;
    int quantity;
} Product;

// Define inventory array and size
Product inventory[MAX_INVENTORY_SIZE];
int inventorySize = 0;

// Function to add product to inventory
void addProduct(Product product) {
    // Check if inventory is full
    if (inventorySize == MAX_INVENTORY_SIZE) {
        printf("Inventory is full. Cannot add more products.\n");
    }
    else {
        // Check if product already exists in inventory
        for (int i = 0; i < inventorySize; i++) {
            if (strcmp(product.name, inventory[i].name) == 0) {
                printf("Product already exists in inventory. Quantity updated.\n");
                inventory[i].quantity += product.quantity;
                return;
            }
        }
        // Product does not exist in inventory, add it
        inventory[inventorySize] = product;
        inventorySize++;
        printf("Product added to inventory.\n");
    }
}

// Function to remove product from inventory
void removeProduct(int id) {
    // Search for product with given id
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].id == id) {
            // Shift all elements after i one position to the left
            for (int j = i; j < inventorySize - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            // Decrement inventory size
            inventorySize--;
            printf("Product removed from inventory.\n");
            return;
        }
    }
    // Product not found in inventory
    printf("Product not found in inventory.\n");
}

// Function to display inventory
void displayInventory() {
    // Calculate total inventory value
    float totalValue = 0;
    for (int i = 0; i < inventorySize; i++) {
        totalValue += inventory[i].price * inventory[i].quantity;
    }
    // Print inventory header
    printf("ID\tName\t\t\tPrice\tQuantity\n");
    printf("=================================================\n");
    // Print each product in inventory
    for (int i = 0; i < inventorySize; i++) {
        printf("%d\t%-30s%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    // Print total inventory value
    printf("Total inventory value: $%.2f\n", totalValue);
}

int main() {
    // Initialize inventory with some products
    inventory[0] = (Product){"Aspirin", 1, 5.99, 50};
    inventory[1] = (Product){"Tylenol", 2, 6.99, 30};
    inventorySize = 2;
    // Display menu
    int choice = 0;
    do {
        printf("\n1. Add product to inventory\n");
        printf("2. Remove product from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                // Get product info from user and add it to inventory
                Product product;
                printf("Enter product name: ");
                scanf("%s", product.name);
                printf("Enter product price: ");
                scanf("%f", &product.price);
                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);
                product.id = inventorySize + 1;
                addProduct(product);
                break;
            }
            case 2: {
                // Get product id from user and remove product from inventory
                int id;
                printf("Enter product id: ");
                scanf("%d", &id);
                removeProduct(id);
                break;
            }
            case 3: {
                // Display inventory
                displayInventory();
                break;
            }
            case 4: {
                // Exit program
                printf("Exiting program.\n");
                break;
            }
            default: {
                // Invalid choice
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}