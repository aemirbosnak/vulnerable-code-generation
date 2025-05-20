//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define a struct to represent a product
struct Product {
    int id;
    char name[50];
    double price;
    int quantity;
};

// Define an array to store all products in the inventory
struct Product products[MAX_PRODUCTS];

// Define a variable to keep track of the current number of products in the inventory
int numProducts = 0;

// Function to add a new product to the inventory
void addProduct() {
    struct Product product;
    printf("Enter product ID: ");
    scanf("%d", &product.id);
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product price: ");
    scanf("%lf", &product.price);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    products[numProducts++] = product;
    printf("Product added successfully!\n\n");
}

// Function to search for a product by name or ID
void searchProduct() {
    char input[50];
    printf("Enter product name or ID: ");
    scanf("%s", input);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(input, products[i].name) == 0 || atoi(input) == products[i].id) {
            printf("\nProduct ID: %d\nProduct Name: %s\nProduct Price: %.2lf\nProduct Quantity: %d\n", 
                    products[i].id, products[i].name, products[i].price, products[i].quantity);
            return;
        }
    }
    printf("Product not found!\n\n");
}

// Function to print the entire inventory
void printInventory() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product ID: %d\nProduct Name: %s\nProduct Price: %.2lf\nProduct Quantity: %d\n\n", 
                products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    int choice;
    do {
        printf("Choose one of the following options:\n");
        printf("1. Add a product to the inventory\n");
        printf("2. Search for a product by name or ID\n");
        printf("3. Print entire inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                printInventory();
                break;
            case 4:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    } while (1);
    return 0;
}