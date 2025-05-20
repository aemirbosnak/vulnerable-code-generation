//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Struct for a single product
struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
};

// Global list of products
struct product products[MAX_PRODUCTS];
int numProducts = 0;

// Function prototypes
void displayMenu();
void addProduct();
void removeProduct();
void updateProduct();
void searchProduct();
void displayProducts();

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                displayProducts();
                break;
            case 6:
                printf("Exiting the program. Goodbye!");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\nPRODUCT INVENTORY SYSTEM\n");
    printf("-------------------------\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Update a product\n");
    printf("4. Search for a product\n");
    printf("5. Display all products\n");
    printf("6. Exit\n");
}

// Function to add a new product to the inventory
void addProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }
    struct product newProduct;
    printf("Enter the name of the product: ");
    scanf("%s", newProduct.name);
    printf("Enter the price of the product: ");
    scanf("%f", &newProduct.price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);
    newProduct.id = numProducts + 1;
    products[numProducts] = newProduct;
    numProducts++;
    printf("Product added successfully.\n");
}

// Function to remove a product from the inventory
void removeProduct() {
    int id;
    printf("Enter the ID of the product to remove: ");
    scanf("%d", &id);
    int i;
    for (i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Product '%s' removed successfully.\n", products[i].name); 
            for (int j = i; j < numProducts-1; j++) {
                products[j] = products[j+1];
            }
            numProducts--;
            return;
        }
    }
    printf("Error: Could not find the product with ID %d.\n", id);
}

// Function to update a product in the inventory
void updateProduct() {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);
    int i;
    for (i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Product '%s', Price = %.2f, Quantity = %d\n", products[i].name, products[i].price, products[i].quantity);
            printf("Enter the new name of the product (or '0' to skip): ");
            char newName[MAX_NAME_LENGTH];
            scanf("%s", newName);
            if (strcmp(newName, "0") != 0) {
                strcpy(products[i].name, newName);
            }
            printf("Enter the new price of the product (or '0' to skip): ");
            float newPrice;
            scanf("%f", &newPrice);
            if (newPrice != 0) {
                products[i].price = newPrice;
            }
            printf("Enter the new quantity of the product (or '0' to skip): ");
            int newQuantity;
            scanf("%d", &newQuantity);
            if (newQuantity != 0) {
                products[i].quantity = newQuantity;
            }
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Error: Could not find the product with ID %d.\n", id);
}

// Function to search for a product in the inventory
void searchProduct() {
    char keyword[MAX_NAME_LENGTH];
    printf("Enter the name (or part of the name) of the product you are looking for: ");
    scanf("%s", keyword);
    int i, found = 0;
    for (i = 0; i < numProducts; i++) {
        if (strstr(products[i].name, keyword) != NULL) {
            printf("ID = %d, Name = '%s', Price = %.2f, Quantity = %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found containing the keyword '%s'.\n", keyword);
    }
}

// Function to display all products in the inventory
void displayProducts() {
    if (numProducts == 0) {
        printf("No products to display.\n");
        return;
    }
    int i;
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < numProducts; i++) {
        printf("%d\t%-16s%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}