//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    int quantity;
    float price;
};

// Global array to store products
struct Product products[MAX_PRODUCTS];

// Counter for number of products in inventory
int numProducts = 0;

// Function to add a product to the inventory
void addProduct() {
    if (numProducts < MAX_PRODUCTS) {
        struct Product newProduct;

        printf("Enter product name: ");
        scanf("%s", newProduct.name);

        printf("Enter quantity: ");
        scanf("%d", &newProduct.quantity);

        printf("Enter price: ");
        scanf("%f", &newProduct.price);

        products[numProducts++] = newProduct;

        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full. Cannot add product.\n");
    }
}

// Function to search and view a product from the inventory
void viewProduct() {
    char name[50];
    int found = 0;

    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

// Function to remove a product from the inventory
void removeProduct() {
    char name[50];
    int found = 0;

    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j+1];
            }

            numProducts--;

            printf("Product removed successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

// Function to display all products in the inventory
void displayInventory() {
    if (numProducts == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("Current inventory:\n");
        printf("%-25s %-15s %-10s\n", "Name", "Quantity", "Price");

        for (int i = 0; i < numProducts; i++) {
            printf("%-25s %-15d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    printf("*** Welcome to the Product Inventory System ***\n");

    int choice;

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a product\n");
        printf("2. View a product\n");
        printf("3. Remove a product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}