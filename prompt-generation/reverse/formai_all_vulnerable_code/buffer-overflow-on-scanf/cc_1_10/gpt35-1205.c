//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <string.h>

// Define Constants
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

// Define Product Structure
struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
};

// Declare Global Variables
struct product inventory[MAX_PRODUCTS];
int numOfProducts = 0;

// Function Declarations
void addProduct();
void removeProduct(char *searchName);
void displayInventory();

// Main Function
int main() {
    int choice;
    char searchName[MAX_NAME_LENGTH];

    // Display Menu
    printf("Welcome to the Product Inventory System!\n\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n\n");

    // Get User's Choice
    do {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Product
                addProduct();
                break;
            case 2:
                // Remove Product
                printf("Enter the name of the product: ");
                scanf("%s", searchName);
                removeProduct(searchName);
                break;
            case 3:
                // Display Inventory
                displayInventory();
                break;
            case 4:
                // Exit
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Add Product Function
void addProduct() {
    // Check if Inventory is Full
    if (numOfProducts == MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add any more products.\n");
        return;
    }

    // Get Product Details
    printf("Enter the name of the product: ");
    scanf("%s", inventory[numOfProducts].name);
    printf("Enter the description of the product: ");
    scanf(" %[^\n]s", inventory[numOfProducts].description);
    printf("Enter the price of the product: ");
    scanf("%f", &inventory[numOfProducts].price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[numOfProducts].quantity);

    // Increment Number of Products
    numOfProducts++;

    // Display Success Message
    printf("Product added successfully!\n");
}

// Remove Product Function
void removeProduct(char *searchName) {
    int i, found = 0;

    // Search for Product
    for (i = 0; i < numOfProducts; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            found = 1;

            // Remove Product
            inventory[i] = inventory[numOfProducts - 1];
            numOfProducts--;

            // Display Success Message
            printf("%s removed successfully!\n", searchName);
            break;
        }
    }

    // Display Error Message if Product Not Found
    if (!found) {
        printf("%s not found in inventory!\n", searchName);
    }
}

// Display Inventory Function
void displayInventory() {
    int i;

    // Display Table Header
    printf("| %-20s | %-25s | %10s | %10s |\n", "Name", "Description", "Price", "Quantity");
    printf("|---------------------|-------------------------|------------|------------|\n");

    // Display Products
    for (i = 0; i < numOfProducts; i++) {
        printf("| %-20s | %-25s | %10.2f | %10d |\n", inventory[i].name, inventory[i].description, inventory[i].price, inventory[i].quantity);
    }

    // Display Error Message if Inventory is Empty
    if (numOfProducts == 0) {
        printf("Inventory is empty! Please add products.\n");
    }
}