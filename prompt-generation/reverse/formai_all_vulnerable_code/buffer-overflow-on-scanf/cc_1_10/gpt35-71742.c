//FormAI DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT_NAME 50
#define MAX_PRODUCT_CATEGORY 20

// Structure to hold product information
typedef struct product {
    char name[MAX_PRODUCT_NAME];
    char category[MAX_PRODUCT_CATEGORY];
    float price;
    int quantity;
} product;

// Function declarations
void addProduct(product *inventory, int *numProducts);
void removeProduct(product *inventory, int *numProducts);
void printInventory(product *inventory, int numProducts);
void printProduct(product prod);

int main() {
    product inventory[100]; // Array to hold products
    int numProducts = 0; // Number of products in inventory
    int choice; // Choice input by user

    printf("Welcome to the Product Inventory System!\n");

    do {
        // Display menu options
        printf("\nChoose an option:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Print Inventory\n");
        printf("4. Exit Program\n");

        // Retrieve user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch(choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                removeProduct(inventory, &numProducts);
                break;
            case 3:
                printInventory(inventory, numProducts);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addProduct(product *inventory, int *numProducts) {
    product newProduct;

    // Retrieve product information from user
    printf("\nADDING PRODUCT\n");
    printf("Enter product name: ");
    fgets(newProduct.name, MAX_PRODUCT_NAME, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // Remove newline character from input
    printf("Enter product category: ");
    fgets(newProduct.category, MAX_PRODUCT_CATEGORY, stdin);
    newProduct.category[strcspn(newProduct.category, "\n")] = '\0'; // Remove newline character from input
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    getchar(); // Clear input buffer

    // Add new product to inventory
    inventory[*numProducts] = newProduct;
    *numProducts += 1;

    printf("\nProduct successfully added!\n");
}

void removeProduct(product *inventory, int *numProducts) {
    char searchName[MAX_PRODUCT_NAME];
    int found = 0;
    int i;

    // Retrieve name of product to be removed
    printf("\nREMOVING PRODUCT\n");
    printf("Enter name of product to be removed: ");
    fgets(searchName, MAX_PRODUCT_NAME, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character from input

    // Search for product in inventory
    for (i=0; i<*numProducts; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            found = 1;
            break;
        }
    }

    // Remove product if found
    if (found) {
        for (; i<(*numProducts)-1; i++) {
            inventory[i] = inventory[i+1];
        }
        *numProducts -= 1;
        printf("\nProduct successfully removed!\n");
    } else {
        printf("\nProduct not found in inventory. Please try again.\n");
    }
}

void printInventory(product *inventory, int numProducts) {
    int i;

    // Check if inventory is empty
    if (numProducts == 0) {
        printf("\nInventory is empty.\n");
    } else {
        // Print header
        printf("\n%-25s %-15s %10s %10s\n", "Product Name", "Product Category", "Price", "Quantity");
        printf("--------------------------------------------------------------------\n");

        // Print each product
        for (i=0; i<numProducts; i++) {
            printProduct(inventory[i]);
        }
    }
}

void printProduct(product prod) {
    printf("%-25s %-15s %10.2f %10d\n", prod.name, prod.category, prod.price, prod.quantity);
}