//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored
#define MAX_PRODUCTS 100

// Define the structure of a product
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Declare the array of products
struct Product inventory[MAX_PRODUCTS];

// Define the index of the last product added
int last_index = -1;

// Define a function to add a product to the inventory
void add_product() {
    // Check if the inventory is already full
    if (last_index == MAX_PRODUCTS - 1) {
        printf("Cannot add more products, inventory is full.\n");
        return;
    }

    // Prompt the user to enter the name, quantity, and price of the product
    printf("Enter the name of the product: ");
    scanf("%s", inventory[last_index + 1].name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[last_index + 1].quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &inventory[last_index + 1].price);

    // Increase the index of the last product added
    last_index++;
    printf("Product added successfully.\n");
}

// Define a function to remove a product from the inventory
void remove_product() {
    // Check if the inventory is already empty
    if (last_index == -1) {
        printf("Cannot remove any products, inventory is empty.\n");
        return;
    }
    
    // Prompt the user to enter the name of the product to be removed
    char product_name[50];
    printf("Enter the name of the product to be removed: ");
    scanf("%s", product_name);

    // Search for the product in the inventory
    int found_product = 0;
    for (int i = 0; i <= last_index; i++) {
        if (strcmp(inventory[i].name, product_name) == 0) {
            found_product = 1;
            // Move all the products after this one by one position to the left
            for (int j = i; j <= last_index - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            // Decrease the index of the last product added
            last_index--;
            printf("Product removed successfully.\n");
            break;
        }
    }

    // If the product was not found, print an error message
    if (!found_product) {
        printf("Product not found.\n");
    }
}

// Define a function to display all the products in the inventory
void display_products() {
    // Check if the inventory is empty
    if (last_index == -1) {
        printf("The inventory is empty.\n");
        return;
    }

    // Print the header of the table
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");

    // Print each product in the table
    for (int i = 0; i <= last_index; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Define the main function
int main() {
    printf("Welcome to the Cyberpunk Product Inventory System.\n");
    printf("Commands:\n");
    printf("1. Add a product.\n");
    printf("2. Remove a product.\n");
    printf("3. Display all products.\n");
    printf("0. Exit.\n");

    // Run the inventory system in a loop
    while (1) {
        // Prompt the user to enter a command
        printf("Enter a command: ");
        int command;
        scanf("%d", &command);

        // Handle the command
        switch (command) {
            case 0:
                printf("Thank you for using the Cyberpunk Product Inventory System.\n");
                return 0;
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    return 0;
}