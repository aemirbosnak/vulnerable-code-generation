//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define the inventory as an array of products
product inventory[MAX_PRODUCTS];

// Define the current number of products in the inventory
int num_products = 0;

// Function to add a product to the inventory
void add_product() {
    // Get the product details from the user
    printf("Enter the product ID: ");
    scanf("%d", &inventory[num_products].id);

    printf("Enter the product name: ");
    scanf(" %[^\n]s", inventory[num_products].name);

    printf("Enter the product quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    printf("Enter the product price: ");
    scanf("%f", &inventory[num_products].price);

    // Increment the number of products in the inventory
    num_products++;
}

// Function to search for a product in the inventory
void search_product() {
    // Get the product ID from the user
    int id;
    printf("Enter the product ID to search for: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            // Product found
            printf("Product found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    // If the product was not found, display an error message
    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to update a product in the inventory
void update_product() {
    // Get the product ID from the user
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            // Product found
            printf("Enter the new product details:\n");

            // Get the updated product details from the user
            printf("Enter the product name: ");
            scanf(" %[^\n]s", inventory[i].name);

            printf("Enter the product quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter the product price: ");
            scanf("%f", &inventory[i].price);

            found = 1;
            break;
        }
    }

    // If the product was not found, display an error message
    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to delete a product from the inventory
void delete_product() {
    // Get the product ID from the user
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            // Product found
            // Shift the remaining products down one position in the array
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            // Decrement the number of products in the inventory
            num_products--;

            found = 1;
            break;
        }
    }

    // If the product was not found, display an error message
    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to display the inventory
void display_inventory() {
    // Print a header
    printf("Product Inventory:\n");
    printf("------------------\n");

    // Print the product details for each product in the inventory
    for (int i = 0; i < num_products; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Display a welcome message
    printf("Welcome to the Product Inventory System!\n");

    // Loop until the user exits the program
    int choice;
    while (1) {
        // Display a menu of options
        printf("\nPlease choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Search for a product\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Display the inventory\n");
        printf("6. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                search_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                display_inventory();
                break;
            case 6:
                // Exit the program
                printf("Thank you for using the Product Inventory System!\n");
                return 0;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}