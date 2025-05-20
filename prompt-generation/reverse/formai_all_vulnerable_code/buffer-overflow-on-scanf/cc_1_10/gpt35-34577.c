//FormAI DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Define a product struct with relevant properties
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define global variables to store product data and number of total products
Product products[MAX_PRODUCTS];
int num_products = 0;

// Define function to add a new product to the inventory
void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    // Prompt user for product information
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    // Increment the total number of products and print a success message
    num_products++;
    printf("Product added to inventory.\n");
}

// Define function to search for a product by name
void searchProduct() {
    char search_name[50];
    printf("Enter product name to search: ");
    scanf("%s", search_name);

    // Loop through products and check if search_name matches a product name
    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_name, products[i].name) == 0) {
            printf("Product found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            return;
        }
    }

    // Print error message if product not found
    printf("Product not found.\n");
}

// Define function to print all products in inventory
void viewInventory() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    // Loop through products and print each product's information
    printf("Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n", products[i].price);
        printf("\n");
    }
}

int main() {
    // Initialize variables for user input and loop
    int choice = 0;
    int loop = 1;

    // Loop through program until user chooses to exit
    while (loop) {
        // Prompt user for choice and execute corresponding function
        printf("Menu:\n");
        printf("1. Add product to inventory\n");
        printf("2. Search for product by name\n");
        printf("3. View entire inventory\n");
        printf("4. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                viewInventory();
                break;
            case 4:
                loop = 0;
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}