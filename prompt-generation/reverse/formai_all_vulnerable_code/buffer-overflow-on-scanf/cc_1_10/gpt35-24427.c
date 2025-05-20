//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our product struct
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Functions
void addProduct(Product* inventory, int* numProducts);
void editProduct(Product* inventory, int numProducts);
void removeProduct(Product* inventory, int* numProducts);
void displayInventory(Product* inventory, int numProducts);

// Main function
int main() {
    int numProducts = 0;
    Product inventory[100];
    int choice = 0;
    char newline;

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a product to the inventory\n");
        printf("2. Edit a product in the inventory\n");
        printf("3. Remove a product from the inventory\n");
        printf("4. Display the inventory\n");
        printf("5. Exit the program\n");
        
        // Get user's choice
        scanf("%d", &choice);
        scanf("%c", &newline);

        switch(choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                editProduct(inventory, numProducts);
                break;
            case 3:
                removeProduct(inventory, &numProducts);
                break;
            case 4:
                displayInventory(inventory, numProducts);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}

void addProduct(Product* inventory, int* numProducts) {
    // Make sure we don't exceed max product limit
    if (*numProducts >= 100) {
        printf("Cannot add more products to inventory.\n");
        return;
    }

    Product newProduct;

    printf("Enter product name: ");
    fgets(newProduct.name, 50, stdin);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    // Clear newline character from buffer
    char newline;
    scanf("%c", &newline);

    // Add product to inventory
    inventory[*numProducts] = newProduct;
    (*numProducts)++;

    printf("Product added to inventory!\n");
}

void editProduct(Product* inventory, int numProducts) {
    // Make sure there are products in the inventory
    if (numProducts == 0) {
        printf("There are no products in the inventory.\n");
        return;
    }

    char productName[50];
    int productIndex = -1;

    printf("Enter the name of the product you want to edit: ");
    fgets(productName, 50, stdin);

    // Remove newline character from productName string
    char* newlinePtr = strchr(productName, '\n');
    if (newlinePtr) {
        *newlinePtr = '\0';
    }

    // Find the product's index in inventory
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        printf("Product not found in inventory.\n");
        return;
    }

    // Prompt user for new values
    printf("Enter new product name (or press enter to keep current name): ");
    fgets(inventory[productIndex].name, 50, stdin);

    printf("Enter new product quantity: ");
    scanf("%d", &inventory[productIndex].quantity);

    printf("Enter new product price: ");
    scanf("%f", &inventory[productIndex].price);

    // Clear newline character from buffer
    char newline;
    scanf("%c", &newline);

    printf("Product updated!\n");
}

void removeProduct(Product* inventory, int* numProducts) {
    // Make sure there are products in the inventory
    if (*numProducts == 0) {
        printf("There are no products in the inventory.\n");
        return;
    }

    char productName[50];
    int productIndex = -1;

    printf("Enter the name of the product you want to remove: ");
    fgets(productName, 50, stdin);

    // Remove newline character from productName string
    char* newlinePtr = strchr(productName, '\n');
    if (newlinePtr) {
        *newlinePtr = '\0';
    }

    // Find the product's index in inventory
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        printf("Product not found in inventory.\n");
        return;
    }

    // Shift remaining products in inventory over
    for (i = productIndex; i < (*numProducts - 1); i++) {
        inventory[i] = inventory[i+1];
    }

    (*numProducts)--;

    printf("Product removed from inventory.\n");
}

void displayInventory(Product* inventory, int numProducts) {
    // Make sure there are products in the inventory
    if (numProducts == 0) {
        printf("There are no products in the inventory.\n");
        return;
    }

    printf("Inventory:\n");
    printf("Name\tQuantity\tPrice\n");

    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}