//FormAI DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <string.h>

/* Define the maximum number of products */
#define MAX_PRODUCTS 1000

/* Define the product struct */
struct Product {
    char name[50];
    int quantity;
    double price;
};

/* Declare the product array */
struct Product products[MAX_PRODUCTS];

/* Declare the current product count */
int productCount = 0;

/* Add a product to the inventory */
void addProduct() {
    /* Check if the maximum number of products has been reached */
    if (productCount == MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    /* Get input from the user */
    printf("Enter the product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter the product quantity: ");
    scanf("%d", &products[productCount].quantity);
    printf("Enter the product price: ");
    scanf("%lf", &products[productCount].price);

    /* Increment the product count */
    productCount++;

    /* Print a success message */
    printf("Product added to inventory.\n");
}

/* Remove a product from the inventory */
void removeProduct() {
    /* Get input from the user */
    char productName[50];
    printf("Enter the name of the product to remove: ");
    scanf("%s", productName);

    /* Search for the product in the inventory */
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            index = i;
            break;
        }
    }

    /* If the product was not found, print an error message */
    if (index == -1) {
        printf("Product not found in inventory.\n");
        return;
    }

    /* Remove the product at the given index */
    for (int i = index; i < productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    productCount--;

    /* Print a success message */
    printf("Product removed from inventory.\n");
}

/* Update the quantity of a product in the inventory */
void updateProductQuantity() {
    /* Get input from the user */
    char productName[50];
    printf("Enter the name of the product to update: ");
    scanf("%s", productName);

    /* Search for the product in the inventory */
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            index = i;
            break;
        }
    }

    /* If the product was not found, print an error message */
    if (index == -1) {
        printf("Product not found in inventory.\n");
        return;
    }

    /* Get input from the user */
    int newQuantity;
    printf("Enter the new quantity of the product: ");
    scanf("%d", &newQuantity);

    /* Update the quantity of the given product */
    products[index].quantity = newQuantity;

    /* Print a success message */
    printf("Product quantity updated in inventory.\n");
}

/* Update the price of a product in the inventory */
void updateProductPrice() {
    /* Get input from the user */
    char productName[50];
    printf("Enter the name of the product to update: ");
    scanf("%s", productName);

    /* Search for the product in the inventory */
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            index = i;
            break;
        }
    }

    /* If the product was not found, print an error message */
    if (index == -1) {
        printf("Product not found in inventory.\n");
        return;
    }

    /* Get input from the user */
    double newPrice;
    printf("Enter the new price of the product: ");
    scanf("%lf", &newPrice);

    /* Update the price of the given product */
    products[index].price = newPrice;

    /* Print a success message */
    printf("Product price updated in inventory.\n");
}

/* Display the current inventory */
void displayInventory() {
    /* Print the header */
    printf("%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");

    /* Loop through all products */
    for (int i = 0; i < productCount; i++) {
        printf("%-30s %-10d %-10.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

/* The main function */
int main() {
    /* Display the menu */
    printf("Product Inventory System:\n");
    printf("1. Add a product to the inventory\n");
    printf("2. Remove a product from the inventory\n");
    printf("3. Update the quantity of a product in the inventory\n");
    printf("4. Update the price of a product in the inventory\n");
    printf("5. Display the current inventory\n");
    printf("6. Exit\n");

    /* Process input from the user */
    int choice;
    do {
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
                updateProductQuantity();
                break;
            case 4:
                updateProductPrice();
                break;
            case 5:
                displayInventory();
                break;
            case 6:
                printf("Thank you for using the Product Inventory System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    /* Return with no errors */
    return 0;
}