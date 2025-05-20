//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum inventory capacity
#define MAX_INVENTORY_CAPACITY 100

// Define the maximum product name length
#define MAX_PRODUCT_NAME_LENGTH 50

// Define the maximum transaction history length
#define MAX_TRANSACTION_HISTORY_LENGTH 100

// Define the product structure
typedef struct {
    int id;
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    double price;
} Product;

// Define the transaction structure
typedef struct {
    int productId;
    int quantity;
    char type[10];
} Transaction;

// Define the inventory array
Product inventory[MAX_INVENTORY_CAPACITY];

// Define the transaction history array
Transaction transactionHistory[MAX_TRANSACTION_HISTORY_LENGTH];

// Define the inventory count
int inventoryCount = 0;

// Define the transaction count
int transactionCount = 0;

// Function to add a product to the inventory
void addProduct() {
    if (inventoryCount == MAX_INVENTORY_CAPACITY) {
        printf("Inventory is already full.\n");
        return;
    }

    Product p;
    p.id = inventoryCount + 1;

    printf("Enter the product name: ");
    scanf("%s", &p.name);
    printf("Enter the product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter the product price: ");
    scanf("%lf", &p.price);

    inventory[inventoryCount] = p;
    inventoryCount++;

    printf("Product added to inventory successfully.\n");
}

// Function to display all products in the inventory
void displayInventory() {
    printf("Product ID\tProduct Name\tProduct Quantity\tProduct Price\n");

    for (int i = 0; i < inventoryCount; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2lf\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to make a purchase
void purchaseProduct() {
    if (inventoryCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    int productId, quantity;

    printf("Enter the product ID to purchase: ");
    scanf("%d", &productId);

    Product *product = NULL;

    for (int i = 0; i < inventoryCount; i++) {
        if (inventory[i].id == productId) {
            product = &inventory[i];
            break;
        }
    }

    if (product == NULL) {
        printf("Product not found in inventory.\n");
        return;
    }

    printf("Enter the quantity to purchase: ");
    scanf("%d", &quantity);

    if (quantity > product->quantity) {
        printf("Not enough quantity in inventory. Available quantity: %d\n", product->quantity);
        return;
    }

    product->quantity -= quantity;

    Transaction t;
    t.productId = productId;
    t.quantity = quantity;
    strcpy(t.type, "Purchase");

    transactionHistory[transactionCount] = t;
    transactionCount++;

    printf("Purchase made successfully.\n");
}

// Function to make a sale
void sellProduct() {
    if (inventoryCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    int productId, quantity;

    printf("Enter the product ID to sell: ");
    scanf("%d", &productId);

    Product *product = NULL;

    for (int i = 0; i < inventoryCount; i++) {
        if (inventory[i].id == productId) {
            product = &inventory[i];
            break;
        }
    }

    if (product == NULL) {
        printf("Product not found in inventory.\n");
        return;
    }

    printf("Enter the quantity to sell: ");
    scanf("%d", &quantity);

    if (quantity > product->quantity) {
        printf("Not enough quantity in inventory. Available quantity: %d\n", product->quantity);
        return;
    }

    product->quantity -= quantity;

    Transaction t;
    t.productId = productId;
    t.quantity = quantity;
    strcpy(t.type, "Sale");

    transactionHistory[transactionCount] = t;
    transactionCount++;

    printf("Sale made successfully.\n");
}

// Function to display transaction history
void displayTransactionHistory() {
    printf("Product ID\tTransaction Type\tTransaction Quantity\n");

    for (int i = 0; i < transactionCount; i++) {
        printf("%d\t\t%s\t\t%d\n", transactionHistory[i].productId, transactionHistory[i].type, transactionHistory[i].quantity);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("1. Add product to inventory\n");
        printf("2. Display inventory\n");
        printf("3. Purchase a product\n");
        printf("4. Sell a product\n");
        printf("5. Display transaction history\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                purchaseProduct();
                break;
            case 4:
                sellProduct();
                break;
            case 5:
                displayTransactionHistory();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}