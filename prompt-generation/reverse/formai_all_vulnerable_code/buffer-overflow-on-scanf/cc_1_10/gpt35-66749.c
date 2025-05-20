//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 50 // maximum number of products that can be stored
#define MAX_NAME_LENGTH 20 // maximum length of the product name
#define MAX_CATEGORY_LENGTH 10 // maximum length of the product category

struct Product {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int quantity;
}; // define the structure of each product

struct Product inventory[MAX_PRODUCTS]; // an array of the structure Product to store the inventory
int numOfProducts = 0; // counter for the number of products currently stored in inventory

// function to add a new product to the inventory
void addProduct() {
    if (numOfProducts >= MAX_PRODUCTS) {
        printf("\nInventory is full! Cannot add more products.");
        return;
    }

    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int quantity;

    printf("\nEnter the name of the product: ");
    scanf("%s", name);
    printf("Enter the category of the product: ");
    scanf("%s", category);
    printf("Enter the price of the product: ");
    scanf("%f", &price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &quantity);

    struct Product newProduct;
    strncpy(newProduct.name, name, MAX_NAME_LENGTH);
    strncpy(newProduct.category, category, MAX_CATEGORY_LENGTH);
    newProduct.price = price;
    newProduct.quantity = quantity;

    inventory[numOfProducts++] = newProduct;

    printf("\nNew product added to inventory successfully!");
}

// function to display all products in the inventory
void displayProducts() {
    if (numOfProducts == 0) {
        printf("\nInventory is empty! Nothing to display.");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s\n", "Name", "Category", "Price", "Quantity");
    for (int i = 0; i < numOfProducts; i++) {
        printf("%-20s %-10s %-10.2f %-10d\n", inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
    }
}

// function to search for a product in the inventory by name
void searchProduct() {
    if (numOfProducts == 0) {
        printf("\nInventory is empty! Cannot search for any product.");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("\nEnter the name of the product to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numOfProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\n%-20s %-10s %-10s %-10s\n", "Name", "Category", "Price", "Quantity");
            printf("%-20s %-10s %-10.2f %-10d\n", inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found in inventory.");
    }
}

// function to update the quantity of an existing product in the inventory
void updateProduct() {
    if (numOfProducts == 0) {
        printf("\nInventory is empty! Cannot update any product.");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("\nEnter the name of the product to update: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < numOfProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nEnter the new quantity of the product: ");
            scanf("%d", &inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found in inventory.");
    } else {
        printf("\nQuantity of product updated successfully!");
    }
}

// main function to drive the program
int main() {
    int choice;

    while (1) {
        printf("\n-------- Product Inventory --------\n");
        printf("1. Add product to inventory\n");
        printf("2. Display all products in inventory\n");
        printf("3. Search for a product by name\n");
        printf("4. Update the quantity of a product\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: printf("\nExiting product inventory system...\n"); exit(0);
            default: printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}