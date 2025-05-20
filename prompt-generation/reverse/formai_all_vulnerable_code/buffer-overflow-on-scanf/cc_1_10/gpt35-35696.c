//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product struct definition
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Function to display a product
void displayProduct(Product product) {
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2f\n", product.price);
    printf("\n");
}

// Function to add a product to the inventory
void addProduct(Product *inventory, int *numProducts) {
    // Prompt user for product details
    printf("Enter product name: ");
    scanf("%s", inventory[*numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*numProducts].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*numProducts].price);
    printf("Product added!\n\n");
    // Increment number of products in inventory
    (*numProducts)++;
}

// Function to remove a product from the inventory
void removeProduct(Product *inventory, int *numProducts) {
    // Prompt user for product name
    char nameToRemove[50];
    printf("Enter name of product to remove: ");
    scanf("%s", nameToRemove);
    // Search for product in inventory
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].name, nameToRemove) == 0) {
            // Move products after removed product up one index
            int j;
            for (j = i+1; j < *numProducts; j++) {
                inventory[j-1] = inventory[j];
            }
            // Decrement number of products in inventory
            (*numProducts)--;
            // Inform user that product was removed
            printf("Product removed!\n\n");
            return;
        }
    }
    // If product was not found
    printf("Product not found.\n\n");
}

int main() {
    // Initialize inventory array
    Product inventory[100];
    // Initialize number of products in inventory
    int numProducts = 0;
    // Loop to display menu and get user input
    int choice;
    do {
        printf("1. Display products\n");
        printf("2. Add product\n");
        printf("3. Remove product\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                if (numProducts == 0) {
                    printf("Inventory is empty.\n\n");
                } else {
                    // Loop to display all products in inventory
                    int i;
                    for (i = 0; i < numProducts; i++) {
                        displayProduct(inventory[i]);
                    }
                }
                break;
            case 2:
                addProduct(inventory, &numProducts);
                break;
            case 3:
                removeProduct(inventory, &numProducts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n\n");
        }
    } while (choice != 4);

    return 0;
}