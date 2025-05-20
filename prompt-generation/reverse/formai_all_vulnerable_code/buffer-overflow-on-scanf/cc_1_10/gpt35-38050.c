//FormAI DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about a product
typedef struct {
    int id;
    char name[20];
    float price;
    int quantity;
} Product;

// Define a constant for the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Declare an array to hold the inventory of products
Product inventory[MAX_PRODUCTS];

// Declare a variable to keep track of the number of products in the inventory
int numProducts = 0;

// Function to display the menu options for the user
void displayMenu() {
    printf("=====================================\n");
    printf("C Product Inventory System\n");
    printf("=====================================\n");
    printf("1. Add a product\n");
    printf("2. View a product\n");
    printf("3. Update a product\n");
    printf("4. Remove a product\n");
    printf("5. View all products\n");
    printf("6. Exit\n");
}

// Function to add a new product to the inventory
void addProduct() {
    int id;
    char name[20];
    float price;
    int quantity;

    printf("Enter product ID: ");
    scanf("%d", &id);
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    // Create a new product with the entered data
    Product p;
    p.id = id;
    strcpy(p.name, name);
    p.price = price;
    p.quantity = quantity;

    // Add the new product to the inventory
    inventory[numProducts++] = p;

    printf("Product added successfully!\n");
}

// Function to view a product in the inventory
void viewProduct() {
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            // Display the product information
            printf("Product ID: %d\n", inventory[i].id);
            printf("Product Name: %s\n", inventory[i].name);
            printf("Product Price: %.2f\n", inventory[i].price);
            printf("Product Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }

    // If the product was not found, display an error message
    printf("Product not found!\n");
}

// Function to update a product in the inventory
void updateProduct() {
    int id;
    int choice;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            // Display the product information to confirm the user's choice
            printf("Product ID: %d\n", inventory[i].id);
            printf("Product Name: %s\n", inventory[i].name);
            printf("Product Price: %.2f\n", inventory[i].price);
            printf("Product Quantity: %d\n", inventory[i].quantity);
            
            // Ask the user what they want to update
            printf("What do you want to update?\n");
            printf("1. Name\n");
            printf("2. Price\n");
            printf("3. Quantity\n");
            printf("4. Cancel\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    // Update the product name
                    printf("Enter new product name: ");
                    scanf("%s", inventory[i].name);
                    printf("Product name updated successfully!\n");
                    break;
                case 2:
                    // Update the product price
                    printf("Enter new product price: ");
                    scanf("%f", &inventory[i].price);
                    printf("Product price updated successfully!\n");
                    break;
                case 3:
                    // Update the product quantity
                    printf("Enter new product quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    printf("Product quantity updated successfully!\n");
                    break;
                default:
                    printf("Update cancelled!\n");
            }

            return;
        }
    }

    // If the product was not found, display an error message
    printf("Product not found!\n");
}

// Function to remove a product from the inventory
void removeProduct() {
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            // Shift the remaining elements of the array to cover the removed product
            for (int j = i; j < numProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            numProducts--;

            printf("Product removed successfully!\n");
            return;
        }
    }

    // If the product was not found, display an error message
    printf("Product not found!\n");
}

// Function to display all products in the inventory
void viewAllProducts() {
    if (numProducts == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("=====================================\n");
    printf("Product ID\t Product Name\t Product Price\t Product Quantity\n");
    printf("=====================================\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%d\t\t %s\t\t %.2f\t\t %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    int choice;

    // Display the menu and prompt the user for a choice
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                viewAllProducts();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}