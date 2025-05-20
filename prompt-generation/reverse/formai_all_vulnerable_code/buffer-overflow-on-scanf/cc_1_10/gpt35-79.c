//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 1000 // max number of products in the warehouse
#define MAX_NAME_LENGTH 20 // max length of product name

// Product struct to store product details
struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS]; // array to store products
int numProducts = 0; // current number of products in the warehouse

// Function to add a product to the warehouse
void addProduct() {
    if (numProducts == MAX_PRODUCTS) { // if the warehouse is full
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }

    printf("Enter product name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    // Check if the product already exists in the warehouse
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(name, products[i].name) == 0) { // if product already exists
            printf("Product already exists in the warehouse! Please update the quantity instead.\n");
            return;
        }
    }

    printf("Enter product quantity: ");
    int quantity;
    scanf("%d", &quantity);

    printf("Enter product price: ");
    float price;
    scanf("%f", &price);

    struct Product p = { .quantity = quantity, .price = price };
    strcpy(p.name, name);
    products[numProducts++] = p; // add the product to the warehouse
    printf("Product added successfully!\n");
}

// Function to remove a product from the warehouse
void removeProduct() {
    if (numProducts == 0) { // if the warehouse is empty
        printf("Warehouse is empty! Cannot remove any products.\n");
        return;
    }

    printf("Enter product name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    // Check if the product exists in the warehouse
    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(name, products[i].name) == 0) { // if product is found
            // Shift all the products after it one position to the left
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j+1];
            }
            numProducts--; // remove the product and decrement the total number of products
            found = true;
            break;
        }
    }

    if (found) {
        printf("Product removed successfully!\n");
    } else {
        printf("Product not found in the warehouse!\n");
    }
}

// Function to update the quantity of a product in the warehouse
void updateQuantity() {
    if (numProducts == 0) { // if the warehouse is empty
        printf("Warehouse is empty! Cannot update the quantity of any products.\n");
        return;
    }

    printf("Enter product name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    // Check if the product exists in the warehouse
    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(name, products[i].name) == 0) { // if product is found
            printf("Enter new quantity: ");
            int quantity;
            scanf("%d", &quantity);
            products[i].quantity = quantity; // update the quantity of the product
            found = true;
            break;
        }
    }

    if (found) {
        printf("Quantity updated successfully!\n");
    } else {
        printf("Product not found in the warehouse!\n");
    }
}

// Function to print the details of all the products in the warehouse
void printWarehouse() {
    if (numProducts == 0) { // if the warehouse is empty
        printf("Warehouse is empty!\n");
        return;
    }

    printf("Warehouse contains %d products:\n", numProducts);
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - quantity: %d, price: %.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    do {
        // Display the menu
        printf("\nWarehouse Management System\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update the quantity of a product\n");
        printf("4. Print the details of all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the respective action based on the user's choice
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                printWarehouse();
                break;
            case 5:
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}