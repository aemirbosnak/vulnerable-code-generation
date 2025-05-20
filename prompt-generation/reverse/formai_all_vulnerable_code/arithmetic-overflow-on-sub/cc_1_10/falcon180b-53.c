//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product structure
typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

// Function to add a new product
void addProduct(Product products[], int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);

    printf("Enter product price: ");
    scanf("%f", &products[numProducts].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);

    numProducts++;
}

// Function to display all products
void displayProducts(Product products[], int numProducts) {
    printf("\nProduct List:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - $%.2f - %d units\n", i+1, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to update product quantity
void updateQuantity(Product products[], int numProducts) {
    printf("\nEnter product number to update quantity: ");
    scanf("%d", &numProducts);

    printf("Enter new quantity: ");
    scanf("%d", &products[--numProducts].quantity);
}

// Function to search for a product
void searchProduct(Product products[], int numProducts) {
    printf("\nEnter product name to search: ");
    scanf("%s", products[0].name);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, products[0].name) == 0) {
            printf("\nProduct found:\n");
            printf("%s - $%.2f - %d units\n", products[i].name, products[i].price, products[i].quantity);
        }
    }
}

// Main function
int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("\nEnter 1 to add a new product, 2 to display all products, 3 to update product quantity, 4 to search for a product, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                updateQuantity(products, numProducts);
                break;
            case 4:
                searchProduct(products, numProducts);
                break;
            case 0:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}