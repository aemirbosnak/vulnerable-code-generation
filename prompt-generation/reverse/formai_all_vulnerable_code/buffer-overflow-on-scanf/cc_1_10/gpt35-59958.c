//FormAI DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Product struct
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function prototypes
int addProduct(Product inventory[], int size);
void displayProducts(Product inventory[], int size);

int main() {
    // Initialize inventory array
    Product inventory[MAX_PRODUCTS];
    int size = 0;

    // Welcome message
    printf("Welcome to the Product Inventory System!\n");

    // Menu loop
    int choice = 0;
    while (choice != 3) {
        printf("\nPlease select an option:\n");
        printf("1. Add a new product\n");
        printf("2. Display products\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add new product
                if (size < MAX_PRODUCTS) {
                    size += addProduct(inventory, size);
                    printf("Product successfully added!\n");
                } else {
                    printf("Error: inventory is full.\n");
                }
                break;
            case 2:
                // Display product inventory
                displayProducts(inventory, size);
                break;
            case 3:
                // Quit program
                printf("Goodbye!\n");
                break;
            default:
                // Invalid choice
                printf("Error: invalid choice.\n");
        }
    }

    return 0;
}

// Function to add a new product to the inventory
int addProduct(Product inventory[], int size) {
    // Get product information from user
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    // Set product ID
    newProduct.id = size + 1;

    // Add product to array
    inventory[size] = newProduct;

    // Return the number of items added (1)
    return 1;
}

// Function to display all products in the inventory
void displayProducts(Product inventory[], int size) {
    printf("\nProduct inventory:\n");

    // Print header row
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");

    // Print each product
    for (int i = 0; i < size; i++) {
        printf("%-5d %-20s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}