//FormAI DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product struct
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Function prototypes
void addProduct(Product products[], int *currentInventory);
void removeProduct(Product products[], int *currentInventory);
void updateProduct(Product products[], int *currentInventory);
void displayInventory(Product products[], int currentInventory);
void displayMenu();

int main() {
    // Initialize variables
    Product products[100];
    int currentInventory = 0;
    int choice;

    // Display menu and get user's choice
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &currentInventory);
                break;
            case 2:
                removeProduct(products, &currentInventory);
                break;
            case 3:
                updateProduct(products, &currentInventory);
                break;
            case 4:
                displayInventory(products, currentInventory);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addProduct(Product products[], int *currentInventory) {
    // Check if inventory is full
    if (*currentInventory == 100) {
        printf("Inventory is full. Cannot add new product.\n");
        return;
    }

    // Create new product and add to inventory
    Product newProduct;

    printf("Enter name of product: ");
    scanf("%s", newProduct.name);

    printf("Enter quantity of product: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter price of product: ");
    scanf("%f", &newProduct.price);

    products[*currentInventory] = newProduct;
    *currentInventory += 1;

    printf("Product added successfully.\n");
}

void removeProduct(Product products[], int *currentInventory) {
    // Check if inventory is empty
    if (*currentInventory == 0) {
        printf("Inventory is empty. Cannot remove product.\n");
        return;
    }

    // Remove product from inventory
    char nameToRemove[50];
    int indexToRemove = -1;

    printf("Enter name of product to remove: ");
    scanf("%s", nameToRemove);

    for (int i = 0; i < *currentInventory; i++) {
        if (strcmp(nameToRemove, products[i].name) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Product not found. Cannot remove.\n");
        return;
    }

    for (int i = indexToRemove; i < *currentInventory - 1; i++) {
        products[i] = products[i + 1];
    }

    *currentInventory -= 1;

    printf("Product removed successfully.\n");
}

void updateProduct(Product products[], int *currentInventory) {
    // Check if inventory is empty
    if (*currentInventory == 0) {
        printf("Inventory is empty. Cannot update product.\n");
        return;
    }

    // Update product in inventory
    char nameToUpdate[50];
    int indexToUpdate = -1;
    int choice;

    printf("Enter name of product to update: ");
    scanf("%s", nameToUpdate);

    for (int i = 0; i < *currentInventory; i++) {
        if (strcmp(nameToUpdate, products[i].name) == 0) {
            indexToUpdate = i;
            break;
        }
    }

    if (indexToUpdate == -1) {
        printf("Product not found. Cannot update.\n");
        return;
    }

    do {
        printf("What would you like to update?\n");
        printf("1. Name\n");
        printf("2. Quantity\n");
        printf("3. Price\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new name of product: ");
                scanf("%s", products[indexToUpdate].name);
                break;
            case 2:
                printf("Enter new quantity of product: ");
                scanf("%d", &products[indexToUpdate].quantity);
                break;
            case 3:
                printf("Enter new price of product: ");
                scanf("%f", &products[indexToUpdate].price);
                break;
            case 4:
                printf("Exiting update menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    printf("Product updated successfully.\n");
}

void displayInventory(Product products[], int currentInventory) {
    // Check if inventory is empty
    if (currentInventory == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    // Display inventory
    printf("%-30s%-15s%s\n", "NAME", "QUANTITY", "PRICE");

    for (int i = 0; i < currentInventory; i++) {
        printf("%-30s%-15d%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void displayMenu() {
    printf("\n");
    printf("PRODUCT INVENTORY SYSTEM\n");
    printf("-------------------------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n");
}