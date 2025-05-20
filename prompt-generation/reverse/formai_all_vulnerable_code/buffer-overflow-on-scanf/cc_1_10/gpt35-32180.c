//FormAI DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products in inventory

// Struct defining a single product
struct Product {
    char name[50]; // Product name
    int count; // Number of items in inventory
    float price; // Price of each item
};

// Struct defining the entire inventory
struct Inventory {
    int count; // Number of products in inventory
    struct Product products[MAX_PRODUCTS]; // Array of products
};

// Function prototypes
void addProduct(struct Inventory *inventory);
void removeProduct(struct Inventory *inventory);
void listProducts(struct Inventory *inventory);
void saveInventory(struct Inventory *inventory);

int main() {
    struct Inventory inventory; // Create a new inventory
    inventory.count = 0; // Initialize with 0 products
    
    char choice; // User's menu choice
    
    printf("Welcome to the Future Product Inventory System!\n");
    
    // Main menu loop
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. List all products\n");
        printf("4. Save inventory to file\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1': addProduct(&inventory); break;
            case '2': removeProduct(&inventory); break;
            case '3': listProducts(&inventory); break;
            case '4': saveInventory(&inventory); break;
            case '0': printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');
    
    return 0;
}

void addProduct(struct Inventory *inventory) {
    // Check if there is space in inventory
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    // Get product details from user
    printf("\nEnter product name: ");
    scanf(" %s", inventory->products[inventory->count].name);
    printf("Enter number of items in inventory: ");
    scanf("%d", &inventory->products[inventory->count].count);
    printf("Enter price of each item: $");
    scanf("%f", &inventory->products[inventory->count].price);
    
    inventory->count++; // Increment product count in inventory
    printf("Product added successfully.\n");
}

void removeProduct(struct Inventory *inventory) {
    // Check if inventory is empty
    if (inventory->count == 0) {
        printf("Inventory is empty. Cannot remove any products.\n");
        return;
    }
    
    // Display list of products and their details
    printf("\nList of products:\n");
    printf("%-30s%-15s%-10s\n", "Name", "Count", "Price");
    for (int i = 0; i < inventory->count; i++) {
        printf("%-30s%-15d$%.2f\n", inventory->products[i].name, inventory->products[i].count, inventory->products[i].price);
    }
    
    // Get product name to be removed from user
    char productName[50];
    printf("\nEnter name of product to be removed: ");
    scanf(" %s", productName);
    
    // Search for product in inventory and remove it
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->products[i].name, productName) == 0) {
            // Shift all products after the removed product to the left in the array
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j+1];
            }
            
            inventory->count--; // Decrement product count in inventory
            printf("Product removed successfully.\n");
            return;
        }
    }
    
    // Product not found in inventory
    printf("Product not found in inventory.\n");
}

void listProducts(struct Inventory *inventory) {
    // Check if inventory is empty
    if (inventory->count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    // Display list of products and their details
    printf("\nList of products:\n");
    printf("%-30s%-15s%-10s\n", "Name", "Count", "Price");
    for (int i = 0; i < inventory->count; i++) {
        printf("%-30s%-15d$%.2f\n", inventory->products[i].name, inventory->products[i].count, inventory->products[i].price);
    }
}

void saveInventory(struct Inventory *inventory) {
    // Check if inventory is empty
    if (inventory->count == 0) {
        printf("Inventory is empty. Nothing to save.\n");
        return;
    }
    
    // Get file name from user
    char fileName[50];
    printf("\nEnter file name*: ");
    scanf(" %s", fileName);
    
    // Add .txt extension to file name if not present
    int len = strlen(fileName);
    if (len >= 4 && strcmp(fileName+len-4, ".txt") != 0) {
        strcat(fileName, ".txt");
    }
    
    // Open file for writing
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file. Cannot save inventory.\n");
        return;
    }
    
    // Write inventory data to file
    fprintf(file, "%-30s%-15s%-10s\n", "Name", "Count", "Price");
    for (int i = 0; i < inventory->count; i++) {
        fprintf(file, "%-30s%-15d$%.2f\n", inventory->products[i].name, inventory->products[i].count, inventory->products[i].price);
    }
    
    fclose(file); // Close file
    printf("Inventory saved to file successfully.\n");
}