//FormAI DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be in inventory
#define MAX_PRODUCTS 100

// Define the maximum length of the product name and description
#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 100

// Define the product struct
struct Product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    int quantity;
};

// Declare the inventory array to hold products
struct Product inventory[MAX_PRODUCTS];

// Declare the current number of products in inventory
int num_products = 0;

// Function to add a new product to inventory
void add_product() {
    // Check if there is space for a new product
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }
    
    // Ask the user for product information
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter product description: ");
    scanf("%s", inventory[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);
    
    // Increment the number of products and notify the user
    num_products++;
    printf("Product added to inventory.\n");
}

// Function to remove a product from inventory
void remove_product() {
    // Check if there are products in inventory
    if (num_products == 0) {
        printf("Inventory is empty, no products to remove.\n");
        return;
    }
    
    // Ask the user for the name of the product to remove
    char product_name[MAX_NAME_LENGTH];
    printf("Enter product name to remove: ");
    scanf("%s", product_name);
    
    // Search for the product in inventory
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, product_name) == 0) {
            // Remove the product by shifting all following products to the left
            int j;
            for (j = i; j < num_products-1; j++) {
                inventory[j] = inventory[j+1];
            }
            // Decrement the number of products and notify the user
            num_products--;
            printf("Product removed from inventory.\n");
            return;
        }
    }
    
    // If the product was not found, notify the user
    printf("Product not found in inventory.\n");
}

// Function to display all products in inventory
void display_inventory() {
    // Check if there are products in inventory
    if (num_products == 0) {
        printf("Inventory is empty, no products to display.\n");
        return;
    }
    
    // Display each product's information
    int i;
    for (i = 0; i < num_products; i++) {
        printf("Product %d:\n", i+1);
        printf("Name: %s\n", inventory[i].name);
        printf("Description: %s\n", inventory[i].description);
        printf("Quantity: %d\n", inventory[i].quantity);
    }
}

// Main function to run the program
int main() {
    int choice;
    
    while (1) {
        // Display the menu and ask for user input
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Call the corresponding function based on user input
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}