//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>

// Define maximum number of products in warehouse
#define MAX_PRODUCTS 100

// Define structure for product
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Declare array of products
struct Product products[MAX_PRODUCTS];

// Declare variable for number of products in warehouse
int numProducts = 0;

// Function to add new product to warehouse
void addProduct() {
    // Check if maximum number of products already reached
    if (numProducts == MAX_PRODUCTS) {
        printf("Warehouse is full!\n");
        return;
    }

    // Get product details from user
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[numProducts].price);

    // Assign unique id to product
    products[numProducts].id = numProducts + 1;

    // Increment number of products in warehouse
    numProducts++;

    printf("Product added successfully!\n");
}

// Function to remove product from warehouse
void removeProduct() {
    // Declare variable for product id to remove
    int productId;

    // Get product id from user
    printf("Enter product id to remove: ");
    scanf("%d", &productId);

    // Find product with given id and remove it
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == productId) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;
            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

// Function to display all products in warehouse
void displayProducts() {
    // Check if there are any products in warehouse
    if (numProducts == 0) {
        printf("No products in warehouse!\n");
        return;
    }

    // Display header for table of products
    printf("%5s %20s %10s %10s\n", "ID", "NAME", "QUANTITY", "PRICE");
    printf("---------------------------------------\n");

    // Loop through all products and display them in a table
    for (int i = 0; i < numProducts; i++) {
        printf("%5d %20s %10d %10.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    // Declare variable for user's choice
    int choice;

    printf("Welcome to Warehouse Management System!\n");

    // Display menu options while user does not choose to quit
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}