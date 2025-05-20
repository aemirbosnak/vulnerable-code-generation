//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
// C Product Inventory System
#include <stdio.h>
#include <stdlib.h>

// Structure to store product details
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product
void addProduct(struct Product *products, int *numProducts) {
    printf("Enter the name of the product: ");
    scanf("%s", products[*numProducts].name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &products[*numProducts].quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &products[*numProducts].price);
    (*numProducts)++;
}

// Function to update the quantity of a product
void updateQuantity(struct Product *products, int *numProducts, int index) {
    printf("Enter the new quantity of the product: ");
    scanf("%d", &products[index].quantity);
}

// Function to delete a product
void deleteProduct(struct Product *products, int *numProducts, int index) {
    products[index] = products[*numProducts - 1];
    (*numProducts)--;
}

// Function to display all products
void displayAllProducts(struct Product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %.2f\n", products[i].price);
    }
}

int main() {
    struct Product products[100];
    int numProducts = 0;
    char option;

    do {
        printf("Enter an option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                addProduct(products, &numProducts);
                break;
            case 'u':
                updateQuantity(products, &numProducts, numProducts - 1);
                break;
            case 'd':
                deleteProduct(products, &numProducts, numProducts - 1);
                break;
            case 'q':
                displayAllProducts(products, numProducts);
                break;
            case 'e':
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 'e');

    return 0;
}