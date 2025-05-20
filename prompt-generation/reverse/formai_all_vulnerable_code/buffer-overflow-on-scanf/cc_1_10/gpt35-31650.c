//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[20];
    float price;
    int quantity;
};

// Function Prototypes
void displayMenu();
void addProduct();
void updateProduct();
void deleteProduct();
void displayProductList();

// Global Variables
struct Product products[50]; // Array of products
int productCount = 0; // Number of products in the array

// Main function
int main() {
    int choice;

    // Display the main menu
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                displayProductList();
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1); // Run forever

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("PRODUCT INVENTORY SYSTEM\n");
    printf("------------------------\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. Display Product List\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a product to the inventory
void addProduct() {
    struct Product p;
    printf("Enter product id: ");
    scanf("%d", &p.id);

    // Check if the product id already exists
    for(int i = 0; i < productCount; i++) {
        if(products[i].id == p.id) {
            printf("Product id already exists. Please try again.\n");
            return;
        }
    }

    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    products[productCount] = p;
    productCount++;

    printf("Product added successfully.\n");
}

// Function to update a product in the inventory
void updateProduct() {
    int id, choice;
    printf("Enter product id to update: ");
    scanf("%d", &id);

    // Find the product by id
    for(int i = 0; i < productCount; i++) {
        if(products[i].id == id) {
            printf("1. Update Name\n");
            printf("2. Update Price\n");
            printf("3. Update Quantity\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Enter product name: ");
                    scanf("%s", products[i].name);
                    printf("Product name updated successfully.\n");
                    break;
                case 2:
                    printf("Enter product price: ");
                    scanf("%f", &products[i].price);
                    printf("Product price updated successfully.\n");
                    break;
                case 3:
                    printf("Enter product quantity: ");
                    scanf("%d", &products[i].quantity);
                    printf("Product quantity updated successfully.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
            return;
        }
    }

    printf("Product not found. Please try again.\n");
}

// Function to delete a product from the inventory
void deleteProduct() {
    int id;
    printf("Enter product id to delete: ");
    scanf("%d", &id);

    // Find the product by id
    for(int i = 0; i < productCount; i++) {
        if(products[i].id == id) {
            // Shift the remaining products to fill the gap
            for(int j = i; j < productCount-1; j++) {
                products[j] = products[j+1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product not found. Please try again.\n");
}

// Function to display the list of products in the inventory
void displayProductList() {
    printf("PRODUCT LIST\n");
    printf("------------\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------\n");
    for(int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("---------------------------------\n");
}