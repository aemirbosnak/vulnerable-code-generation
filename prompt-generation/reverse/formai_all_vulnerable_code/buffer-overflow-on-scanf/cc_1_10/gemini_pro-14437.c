//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Declare the array of products
product products[MAX_PRODUCTS];

// Declare the number of products
int num_products = 0;

// Define the menu options
enum menu_options {
    ADD_PRODUCT = 1,
    REMOVE_PRODUCT,
    UPDATE_PRODUCT,
    DISPLAY_PRODUCTS,
    QUIT
};

// Display the menu
void display_menu() {
    printf("\nProduct Inventory System\n");
    printf("========================\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Update Product\n");
    printf("4. Display Products\n");
    printf("5. Quit\n");
    printf("========================\n");
    printf("Enter your choice: ");
}

// Get the user's choice
int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Add a product to the inventory
void add_product() {
    // Get the product details
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    // Increment the number of products
    num_products++;
}

// Remove a product from the inventory
void remove_product() {
    // Get the product ID
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    // Find the product index
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the product was found
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    // Shift the products down to fill the gap
    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    // Decrement the number of products
    num_products--;
}

// Update a product in the inventory
void update_product() {
    // Get the product ID
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    // Find the product index
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the product was found
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    // Get the updated product details
    printf("Enter product name: ");
    scanf("%s", products[index].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[index].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[index].price);
}

// Display the products in the inventory
void display_products() {
    printf("\nProducts:\n");
    printf("========================\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    printf("========================\n");
}

// Main function
int main() {
    // Display the menu
    display_menu();

    // Get the user's choice
    int choice = get_choice();

    // Loop until the user quits
    while (choice != QUIT) {
        // Perform the selected action
        switch (choice) {
            case ADD_PRODUCT:
                add_product();
                break;
            case REMOVE_PRODUCT:
                remove_product();
                break;
            case UPDATE_PRODUCT:
                update_product();
                break;
            case DISPLAY_PRODUCTS:
                display_products();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Display the menu again
        display_menu();

        // Get the user's choice
        choice = get_choice();
    }

    // Quit the program
    printf("Goodbye!\n");
    return 0;
}