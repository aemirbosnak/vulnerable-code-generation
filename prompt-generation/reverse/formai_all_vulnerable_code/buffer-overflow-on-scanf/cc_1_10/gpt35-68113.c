//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Declare the struct for the product
typedef struct Product {
    char name[20];
    int quantity;
    float price;
} Product;

// Declare the array to hold the products
Product inventory[100];

// Keep track of the current number of products in inventory
int num_products = 0;

// Function to add a product to the inventory
void add_product() {
    // Make sure there is room in the inventory
    if (num_products >= 100) {
        printf("Inventory is full!\n");
        return;
    }

    // Get the product details from the user
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[num_products].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[num_products].price);

    // Increment the number of products
    num_products++;

    printf("Product added!\n");
}

// Function to display the inventory
void display_inventory() {
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("Welcome to the Product Inventory System!\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}