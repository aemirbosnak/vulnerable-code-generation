//FormAI DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store product information
struct Product {
    int productId;
    char productName[50];
    int quantity;
    float price;
    char category[20];
};

// Initialize the inventory with some default products
struct Product inventory[5] = {
    { 1, "Apple iPhone X", 10, 999.99, "Electronics" },
    { 2, "Samsung Galaxy S9", 15, 799.99, "Electronics" },
    { 3, "HP Elitebook Laptop", 20, 899.99, "Computers" },
    { 4, "Sony Bravia TV", 5, 1599.99, "Electronics" },
    { 5, "Nike Air Max Shoes", 25, 129.99, "Footwear" }
};

// Function to display the current inventory
void displayInventory() {
    printf("\nCurrent Inventory:\n");
    printf("------------------------------------------------------------------\n");
    printf("Product ID \tProduct Name \t\tQuantity \tPrice \t\tCategory\n");
    printf("------------------------------------------------------------------\n");

    for(int i = 0; i < 5; i++) {
        printf("%d \t\t%s \t%d \t\t%.2f \t%s\n", inventory[i].productId, inventory[i].productName, inventory[i].quantity, inventory[i].price, inventory[i].category);
    }
    printf("------------------------------------------------------------------\n");
}

// Function to add a new product to the inventory
void addProduct() {
    printf("\nEnter the following details to add a new product to the inventory:\n");

    struct Product newProduct;
    printf("Product ID: ");
    scanf("%d", &newProduct.productId);
    printf("Product Name: ");
    scanf("%s", newProduct.productName);
    printf("Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Price: ");
    scanf("%f", &newProduct.price);
    printf("Category: ");
    scanf("%s", newProduct.category);

    inventory[5] = newProduct;
    printf("\nNew product has been added to the inventory!\n");
}

// Function to update the quantity of an existing product in the inventory
void updateQuantity() {
    printf("\nEnter the Product ID and the new quantity to update:\n");

    int productId, newQuantity;
    printf("Product ID: ");
    scanf("%d", &productId);
    printf("New Quantity: ");
    scanf("%d", &newQuantity);

    for(int i = 0; i < 5; i++) {
        if(inventory[i].productId == productId) {
            inventory[i].quantity = newQuantity;
            printf("\nQuantity has been updated for the product: %s\n", inventory[i].productName);
            return;
        }
    }
    printf("\nProduct with Product ID %d not found in the inventory!\n", productId);
}

int main() {
    int choice;

    do {
        printf("\nWelcome to the Product Inventory System!\n");
        printf("------------------------------------------------------------------\n");
        printf("1. Display Inventory\n");
        printf("2. Add Product\n");
        printf("3. Update Quantity\n");
        printf("4. Exit\n");
        printf("------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayInventory();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                updateQuantity(); 
                break;
            case 4:
                printf("\nThank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}