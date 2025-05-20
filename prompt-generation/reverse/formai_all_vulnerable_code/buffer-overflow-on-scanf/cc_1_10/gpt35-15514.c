//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the product
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Function to add a product to the inventory
void add_product(Product *inventory, int *counter) {
    printf("\n---Add Product---\n");
    printf("Enter product name: ");
    scanf("%s", inventory[*counter].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*counter].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*counter].price);
    (*counter)++;
}

// Function to remove a product from the inventory
void remove_product(Product *inventory, int *counter) {
    printf("\n---Remove Product---\n");
    char name[50];
    printf("Enter product name: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < *counter; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift all elements after the removed product to the left
            int j;
            for (j = i; j < *counter-1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*counter)--;
            printf("Product removed successfully.\n");
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

// Function to display all products in the inventory
void display_products(Product *inventory, int *counter) {
    printf("\n---Product Inventory---\n");
    int i;
    for (i = 0; i < *counter; i++) {
        printf("Name: %s, Quantity: %d, Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-----------------------\n");
}

int main() {
    int choice;
    int counter = 0; // Initialize counter to 0
    Product inventory[100]; // Create an array of 100 products

    do {
        // Display menu
        printf("------Product Inventory System------\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory, &counter);
                break;
            case 2:
                remove_product(inventory, &counter);
                break;
            case 3:
                display_products(inventory, &counter);
                break;
            case 4:
                printf("Exiting program.");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4); // Keep running until user chooses to exit

    return 0; // Return success code
}