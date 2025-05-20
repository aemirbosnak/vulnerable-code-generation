//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 20

// struct for product information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

// array to store products
Product products[MAX_PRODUCTS];

// current number of products in the warehouse 
int numProducts = 0;

// function to add a new product
void addProduct(char *name, int quantity, float price) {
    if(numProducts == MAX_PRODUCTS) {
        printf("Warehouse is full. Cannot add more products.\n");
        return;
    }

    // create a new product instance
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;

    // add the new product to the array
    products[numProducts] = newProduct;
    numProducts++;

    printf("Product added successfully.\n");
}

// function to update quantity of existing product
void updateQuantity(char *name, int quantity) {
    int index = -1;

    // find the index of the product with the given name
    for(int i = 0; i < numProducts; i++) {
        if(strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    // update the quantity of the product
    products[index].quantity += quantity;

    printf("Quantity updated successfully.\n");
}

// function to delete a product
void deleteProduct(char *name) {
    int index = -1;

    // find the index of the product with the given name
    for(int i = 0; i < numProducts; i++) {
        if(strcmp(products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    // shift all the products after this product by one position to the left
    for(int i = index; i < numProducts-1; i++) {
        products[i] = products[i+1];
    }
    numProducts--;

    printf("Product deleted successfully.\n");
}

// function to display all products and their details
void displayProducts() {
    printf("Product Name\tQuantity\tPrice\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%-16s %-16d %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    
    printf("Warehouse Management System\n");
    printf("---------------------------\n");

    while(1) {
        char option;
        char name[MAX_NAME_LENGTH];
        int quantity;
        float price;

        printf("\nOptions:\n");
        printf("1. Add a product\n");
        printf("2. Update quantity of a product\n");
        printf("3. Delete a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter an option (1/2/3/4/5): ");

        scanf(" %c", &option);

        switch(option) {
            case '1':
                printf("Enter product name (max length %d): ", MAX_NAME_LENGTH-1);
                scanf("%s", name);

                printf("Enter quantity: ");
                scanf("%d", &quantity);

                printf("Enter price: ");
                scanf("%f", &price);

                addProduct(name, quantity, price);
                break;

            case '2':
                printf("Enter product name: ");
                scanf("%s", name);

                printf("Enter quantity to add/subtract (positive value to add, negative value to subtract): ");
                scanf("%d", &quantity);

                updateQuantity(name, quantity);
                break;

            case '3':
                printf("Enter product name: ");
                scanf("%s", name);

                deleteProduct(name);
                break;

            case '4':
                displayProducts();
                break;

            case '5':
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}