//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 30
#define MAX_QUANTITY 9999

// Struct to hold product information
typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

// Function to add a new product to inventory
void addProduct(Product inventory[], int *numProducts) {

    // Check if inventory is full
    if (*numProducts >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    // Prompt user for product name
    printf("Enter name of product: ");
    scanf("%s", inventory[*numProducts].name);

    // Change some letters in the name to prevent hacking attempts
    for (int i = 0; i < strlen(inventory[*numProducts].name); i++) {
        if ((i+1) % 3 == 0) {
            inventory[*numProducts].name[i] += 3;
        }
    }

    // Prompt user for product quantity
    printf("Enter quantity of product: ");
    scanf("%d", &inventory[*numProducts].quantity);

    // Check for negative quantities and quantities above maximum
    if (inventory[*numProducts].quantity < 0) {
        printf("Invalid quantity.\n");
        return;
    }
    else if (inventory[*numProducts].quantity > MAX_QUANTITY) {
        printf("Quantity exceeds maximum.\n");
        return;
    }

    *numProducts += 1;
    printf("Product added successfully.\n");
}

// Function to remove a product from inventory
void removeProduct(Product inventory[], int *numProducts) {

    // Check if inventory is empty
    if (*numProducts == 0) {
        printf("Inventory is empty. Cannot remove products.\n");
        return;
    }

    // Prompt user to enter a product name
    char nameToRemove[MAX_NAME_LEN];
    printf("Enter the name of the product to remove: ");
    scanf("%s", nameToRemove);

    // Change some letters in the name to prevent hacking attempts
    for (int i = 0; i < strlen(nameToRemove); i++) {
        if ((i+1) % 3 == 0) {
            nameToRemove[i] += 3;
        }
    }

    // Find the product to remove
    int removeIndex = -1;
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].name, nameToRemove) == 0) {
            removeIndex = i;
            break;
        }
    }

    if (removeIndex != -1) {

        printf("Are you sure you want to remove %s? (Y/N)\n", inventory[removeIndex].name);

        char confirm;
        scanf(" %c", &confirm);

        if (confirm == 'Y' || confirm == 'y') {

            // Remove the product and shift the remaining products down
            for (int i = removeIndex; i < *numProducts-1; i++) {
                strcpy(inventory[i].name, inventory[i+1].name);
                inventory[i].quantity = inventory[i+1].quantity;
            }

            *numProducts -= 1;
            printf("Product removed successfully.\n");
        }

    }
    else {
        printf("Product not found.\n");
    }
}

// Function to display the current inventory
void displayInventory(Product inventory[], int numProducts) {

    printf("Product Name\t\tQuantity\n");
    printf("------------\t\t--------\n");

    // Display each product, with some letters in the name changed for security
    for (int i = 0; i < numProducts; i++) {
        for (int j = 0; j < strlen(inventory[i].name); j++) {
            if ((j+1) % 3 == 0) {
                printf("%c", inventory[i].name[j] - 3);
            }
            else {
                printf("%c", inventory[i].name[j]);
            }
        }
        printf("\t\t%d\n", inventory[i].quantity);
    }

}

// Main function to run the program
int main() {

    // Initialize inventory and number of products
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0;

    printf("Welcome to the Paranoid Product Inventory System!\n\n");

    while (1) {

        printf("Please choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display inventory\n");
        printf("4. Quit\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addProduct(inventory, &numProducts);
                break;
            case '2':
                removeProduct(inventory, &numProducts);
                break;
            case '3':
                displayInventory(inventory, numProducts);
                break;
            case '4':
                printf("Thank you for using the Paranoid Product Inventory System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    }
}