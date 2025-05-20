//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>

// Define maximum number of products and maximum length of product name
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Define struct for product information
typedef struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product;

// Declare global array of products and variable to track the number of products
product inventory[MAX_PRODUCTS];
int numProducts = 0;

// Function to add a product to the inventory
void addProduct() {
    // Check if inventory is full
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: Inventory is full\n");
        return;
    }

    // Get product information from user
    printf("Enter name of product: ");
    scanf("%s", inventory[numProducts].name);
    printf("Enter quantity of product: ");
    scanf("%d", &inventory[numProducts].quantity);
    printf("Enter price of product: ");
    scanf("%f", &inventory[numProducts].price);

    // Increment number of products in inventory
    numProducts++;

    printf("%s added to inventory\n", inventory[numProducts-1].name);
}

// Function to remove a product from the inventory
void removeProduct() {
    // Get name of product to remove from user
    char nameToRemove[MAX_NAME_LENGTH];
    printf("Enter name of product to remove: ");
    scanf("%s", nameToRemove);

    // Loop through inventory to find product
    int i, found = 0;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(nameToRemove, inventory[i].name) == 0) {
            // Found the product, so remove it from the inventory
            int j;
            for (j = i; j < numProducts-1; j++) {
                inventory[j] = inventory[j+1];
            }
            numProducts--;
            printf("%s removed from inventory\n", nameToRemove);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: %s not found in inventory\n", nameToRemove);
    }
}

// Function to display the inventory
void displayInventory() {
    printf("-----------------------------\n");
    printf("Name\tQuantity\tPrice\n");
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------------\n");
}

// Main function to run the program
int main() {
    // Display menu and process user input
    int choice;
    do {
        printf("1. Add product to inventory\n");
        printf("2. Remove product from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }

    } while (choice != 4);

    return 0;
}