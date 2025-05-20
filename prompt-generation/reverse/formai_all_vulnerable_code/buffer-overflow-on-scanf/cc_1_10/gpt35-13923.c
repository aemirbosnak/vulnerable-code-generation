//FormAI DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products in the inventory
#define MAX_NAME_SIZE 50 // Maximum size of a product name
#define MAX_PRICE_SIZE 20 // Maximum size of a price value
#define MAX_QUANTITY_SIZE 10 // Maximum size of a quantity value

// Define a product struct to store each product's information 
typedef struct {
    char name[MAX_NAME_SIZE];
    float price;
    int quantity;
} Product;

// Initialize an empty inventory array with a fixed capacity 
Product inventory[MAX_PRODUCTS];

// Track how many products are currently in the inventory
int num_products = 0;

// Function to add a new product to the inventory
void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add product.\n");
        return;
    }

    // Prompt user to enter product information
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    // Increment product count in inventory
    num_products++;
}

// Function to print all products in the inventory
void print_inventory() {
    // Check if inventory is empty
    if (num_products == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    // Print table header
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-12s | %-10s |\n", "Product Name", "Price", "Quantity");
    printf("----------------------------------------------------------------------------------------\n");

    // Print each product's information from inventory array
    for (int i = 0; i < num_products; i++) {
        printf("| %-20s | %-12.2f | %-10d |\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    printf("----------------------------------------------------------------------------------------\n");
}

// Function to search for a product by name and return its index in the inventory array
int search_product(char* name) {
    // Convert product name to uppercase for case-insensitive search
    for (int i = 0; name[i]; i++) {
        name[i] = toupper(name[i]);
    }

    // Search for product in inventory array
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i; // Return index of matching product
        }
    }

    return -1; // If no matching product found, return -1
}

// Function to update the quantity of a product in the inventory
void update_quantity(char* name, int quantity) {
    int index = search_product(name);

    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    inventory[index].quantity += quantity;
    printf("%d %s(s) added to inventory!\n", quantity, name);
}

// Function to remove a product from the inventory
void remove_product(char* name) {
    int index = search_product(name);

    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    // Remove product by shifting all subsequent products to the left by one position
    for (int i = index; i < num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement product count in inventory
    num_products--;
    printf("%s removed from inventory!\n", name);
}

// Main function to run the product inventory system
int main() {
    char choice;
    char name[MAX_NAME_SIZE];
    char price[MAX_PRICE_SIZE];
    char quantity[MAX_QUANTITY_SIZE];

    while (1) {
        // Print menu options
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("--------------------------------\n");
        printf("1. Add product\n");
        printf("2. Update product quantity\n");
        printf("3. Remove product\n");
        printf("4. View inventory\n");
        printf("5. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice (1-5): ");

        // Read user input and sanitize the input to prevent buffer overflow
        fgets(&choice, 2, stdin);
        while (getchar() != '\n');

        switch (choice) {
            case '1':
                add_product();
                break;

            case '2':
                printf("Enter product name: ");
                fgets(name, MAX_NAME_SIZE, stdin);
                name[strlen(name) - 1] = '\0'; // Remove newline character
                printf("Enter quantity to add or remove (negative to remove, positive to add): ");
                fgets(quantity, MAX_QUANTITY_SIZE, stdin);
                update_quantity(name, atoi(quantity));
                break;

            case '3':
                printf("Enter product name: ");
                fgets(name, MAX_NAME_SIZE, stdin);
                name[strlen(name) - 1] = '\0'; // Remove newline character
                remove_product(name);
                break;

            case '4':
                print_inventory();
                break;

            case '5':
                exit(0);
                break;

            default:
                printf("Invalid choice! Please enter a number from 1 to 5.\n");
                break;
        }
    }

    return 0;
}