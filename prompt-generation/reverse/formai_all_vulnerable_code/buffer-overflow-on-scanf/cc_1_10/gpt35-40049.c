//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that the warehouse can hold.
#define MAX_PRODUCTS 50

// Define the maximum size of the product description string.
#define MAX_DESC_SIZE 100

/* Define a struct that represents a product in the warehouse.
 * The struct has four fields: the product ID (an integer), a string 
 * that describes the product, the quantity of the product in stock, 
 * and the price of the product.
 */
struct Product {
    int id;
    char description[MAX_DESC_SIZE];
    int quantity;
    float price;
};

// Define a global array to store all the products in the warehouse.
struct Product products[MAX_PRODUCTS];

// Define a global variable to keep track of the number of products in the warehouse.
int num_products = 0;

// Function prototype for adding a new product to the warehouse.
void addProduct();

// Function prototype for updating the inventory quantity of a product.
void updateInventory();

// Function prototype for displaying all the products in the warehouse.
void displayProducts();

// The main function.
int main()
{
    int choice;
    char exitChoice;
    
    printf("Welcome to our warehouse management system!\n");

    // Loop forever until the user decides to exit.
    while (1) {
        printf("Menu:\n");
        printf("1) Add a new product\n");
        printf("2) Update inventory quantity of a product\n");
        printf("3) Display all products in the warehouse\n");
        printf("4) Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateInventory();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("Are you sure you want to exit? (y/n): ");
                scanf(" %c", &exitChoice);
                if (exitChoice == 'y' || exitChoice == 'Y') {
                    printf("Thanks for using our warehouse management system!\n");
                    exit(0);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

/**
 * Add a new product to the warehouse.
 */
void addProduct()
{
    if (num_products >= MAX_PRODUCTS) {
        printf("Sorry, the warehouse is full. Cannot add more products.\n");
        return;
    }

    struct Product new_product;

    // Prompt the user to enter the product details.
    printf("Enter the product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter the product description: ");
    scanf("%s", new_product.description);
    printf("Enter the product quantity in stock: ");
    scanf("%d", &new_product.quantity);
    printf("Enter the product price: ");
    scanf("%f", &new_product.price);
    
    // Add the new product to the warehouse.
    products[num_products] = new_product;
    num_products++;

    printf("Product added successfully.\n");
}

/**
 * Update the inventory quantity of a product.
 */
void updateInventory()
{
    int productId;
    int newQuantity;

    printf("Enter the ID of the product to update: ");
    scanf("%d", &productId);

    int i;
    for (i = 0; i < num_products; i++) {
        if (products[i].id == productId) {
            printf("Current quantity in stock: %d\n", products[i].quantity);
            printf("Enter the new quantity in stock: ");
            scanf("%d", &newQuantity);
            products[i].quantity = newQuantity;
            printf("Inventory updated successfully.\n");
            return;
        }
    }

    printf("Sorry, the product with ID %d was not found.\n", productId);
}

/**
 * Display all the products in the warehouse.
 */
void displayProducts()
{
    int i;
    printf("Product ID\tDescription\tQuantity\tPrice\n");
    for (i = 0; i < num_products; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n",
               products[i].id,
               products[i].description,
               products[i].quantity,
               products[i].price);
    }
}