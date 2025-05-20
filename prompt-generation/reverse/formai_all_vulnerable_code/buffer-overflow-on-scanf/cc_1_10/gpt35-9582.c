//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum products that can be stored
#define MAX_NAME_LENGTH 50 // Maximum length of product name

/* Structs */

// Product struct
typedef struct Product {
    char name[MAX_NAME_LENGTH]; // Name of the product
    int quantity; // Quantity of the product in the warehouse
} Product;

// Warehouse struct
typedef struct Warehouse {
    Product products[MAX_PRODUCTS]; // Array of products in the warehouse
    int numProducts; // Number of products currently in the warehouse
} Warehouse;

/* Function prototypes */

void displayMenu();
void addProduct(Warehouse* warehouse);
void removeProduct(Warehouse* warehouse);
void displayWarehouse(Warehouse* warehouse);

/* Main function */

int main() {
    Warehouse warehouse; // Initialize empty warehouse
    warehouse.numProducts = 0; // Set number of products to 0

    int choice; // User input for menu selection
    do {
        displayMenu(); // Display menu options
        scanf("%d", &choice); // Get user input
        switch(choice) {
            case 1:
                addProduct(&warehouse); // Add a product to the warehouse
                break;
            case 2:
                removeProduct(&warehouse); // Remove a product from the warehouse
                break;
            case 3:
                displayWarehouse(&warehouse); // Display products in the warehouse
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!\n"); // Display error message if user enters invalid choice
                break;
        }
    } while(choice != 4);

    return 0;
}

/* Function definitions */

// Function to display menu options
void displayMenu() {
    printf("\n----- Warehouse Management System -----\n\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Display products in the warehouse\n");
    printf("4. Exit program\n\n");
    printf("Enter your choice: ");
}

// Function to add a product to the warehouse
void addProduct(Warehouse* warehouse) {
    // Check if maximum number of products have been reached
    if(warehouse->numProducts >= MAX_PRODUCTS) {
        printf("Maximum number of products have been reached!\n");
        return;
    }

    // Get product details from user
    printf("Enter name of the product: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    printf("Enter quantity of the product: ");
    int qty;
    scanf("%d", &qty);

    // Add product to warehouse
    strcpy(warehouse->products[warehouse->numProducts].name, name);
    warehouse->products[warehouse->numProducts].quantity = qty;
    warehouse->numProducts++;

    printf("Product added to the warehouse!\n");
}

// Function to remove a product from the warehouse
void removeProduct(Warehouse* warehouse) {
    // Check if there are products in the warehouse
    if(warehouse->numProducts == 0) {
        printf("There are no products in the warehouse!\n");
        return;
    }

    // Get product name from user
    printf("Enter name of the product to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    // Find product in warehouse
    int index = -1;
    for(int i = 0; i < warehouse->numProducts; i++) {
        if(strcmp(warehouse->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Remove product from warehouse if found
    if(index != -1) {
        for(int i = index; i < warehouse->numProducts - 1; i++) {
            strcpy(warehouse->products[i].name, warehouse->products[i+1].name);
            warehouse->products[i].quantity = warehouse->products[i+1].quantity;
        }
        warehouse->numProducts--;
        printf("Product removed from the warehouse!\n");
    } else {
        printf("Product not found in the warehouse!\n");
    }
}

// Function to display products in the warehouse
void displayWarehouse(Warehouse* warehouse) {
    // Check if there are products in the warehouse
    if(warehouse->numProducts == 0) {
        printf("There are no products in the warehouse!\n");
        return;
    }

    // Display products in the warehouse
    printf("Products in the warehouse:\n");
    for(int i = 0; i < warehouse->numProducts; i++) {
        printf("%s - %d\n", warehouse->products[i].name, warehouse->products[i].quantity);
    }
}