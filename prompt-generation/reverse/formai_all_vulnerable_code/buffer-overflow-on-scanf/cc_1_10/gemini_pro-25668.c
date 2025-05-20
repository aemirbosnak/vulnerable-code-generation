//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the product structure
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Declare the array of products
Product products[MAX_PRODUCTS];

// Declare the number of products in the inventory
int numProducts = 0;

// Declare the main menu function
void mainMenu();

// Declare the add product function
void addProduct();

// Declare the search product function
void searchProduct();

// Declare the delete product function
void deleteProduct();

// Declare the update product function
void updateProduct();

// Declare the list products function
void listProducts();

// Declare the exit program function
void exitProgram();

// Define the main function
int main() {
    // Initialize the number of products in the inventory
    numProducts = 0;

    // Display the main menu
    mainMenu();

    return 0;
}

// Define the main menu function
void mainMenu() {
    int choice;

    // Display the main menu options
    printf("=========================================\n");
    printf("Product Inventory System\n");
    printf("=========================================\n");
    printf("1. Add Product\n");
    printf("2. Search Product\n");
    printf("3. Delete Product\n");
    printf("4. Update Product\n");
    printf("5. List Products\n");
    printf("6. Exit Program\n");
    printf("=========================================\n");
    printf("Enter your choice: ");

    // Get the user's choice
    scanf("%d", &choice);

    // Call the appropriate function based on the user's choice
    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            searchProduct();
            break;
        case 3:
            deleteProduct();
            break;
        case 4:
            updateProduct();
            break;
        case 5:
            listProducts();
            break;
        case 6:
            exitProgram();
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 6.\n");
            mainMenu();
    }
}

// Define the add product function
void addProduct() {
    // Get the product details from the user
    printf("Enter the product ID: ");
    scanf("%d", &products[numProducts].id);
    printf("Enter the product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter the product quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter the product price: ");
    scanf("%f", &products[numProducts].price);

    // Increment the number of products in the inventory
    numProducts++;

    // Return to the main menu
    mainMenu();
}

// Define the search product function
void searchProduct() {
    int id;

    // Get the product ID from the user
    printf("Enter the product ID: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Display the product details
            printf("Product ID: %d\n", products[i].id);
            printf("Product Name: %s\n", products[i].name);
            printf("Product Quantity: %d\n", products[i].quantity);
            printf("Product Price: %.2f\n", products[i].price);

            // Return to the main menu
            mainMenu();
            return;
        }
    }

    // If the product is not found, display an error message
    printf("Product not found.\n");

    // Return to the main menu
    mainMenu();
}

// Define the delete product function
void deleteProduct() {
    int id;

    // Get the product ID from the user
    printf("Enter the product ID: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Delete the product from the inventory
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;

            // Return to the main menu
            mainMenu();
            return;
        }
    }

    // If the product is not found, display an error message
    printf("Product not found.\n");

    // Return to the main menu
    mainMenu();
}

// Define the update product function
void updateProduct() {
    int id;

    // Get the product ID from the user
    printf("Enter the product ID: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Get the updated product details from the user
            printf("Enter the new product name: ");
            scanf("%s", products[i].name);
            printf("Enter the new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter the new product price: ");
            scanf("%f", &products[i].price);

            // Return to the main menu
            mainMenu();
            return;
        }
    }

    // If the product is not found, display an error message
    printf("Product not found.\n");

    // Return to the main menu
    mainMenu();
}

// Define the list products function
void listProducts() {
    // Display the list of products
    printf("=========================================\n");
    printf("Product List\n");
    printf("=========================================\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product ID: %d\n", products[i].id);
        printf("Product Name: %s\n", products[i].name);
        printf("Product Quantity: %d\n", products[i].quantity);
        printf("Product Price: %.2f\n", products[i].price);
        printf("=========================================\n");
    }

    // Return to the main menu
    mainMenu();
}

// Define the exit program function
void exitProgram() {
    // Exit the program
    exit(0);
}