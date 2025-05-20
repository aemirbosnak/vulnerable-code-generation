//FormAI DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // maximum number of products

// structure to store product information
struct Product {
    char name[50];
    int id;
    int quantity;
    float price;
};

// function prototypes
void addProduct(struct Product *products, int *numProducts);
void removeProduct(struct Product *products, int *numProducts);
void displayInventory(struct Product *products, int numProducts);

int main() {
    struct Product products[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;

    do {
        // display menu
        printf("\nProduct Inventory System\n");
        printf("==============================\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display inventory\n");
        printf("4. Quit\n");
        printf("==============================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                displayInventory(products, numProducts);
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice. Please enter a value between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// function to add a product
void addProduct(struct Product *products, int *numProducts) {
    if (*numProducts == MAX_PRODUCTS) {
        printf("Maximum number of products reached. Cannot add more.\n");
        return;
    }

    // read product information
    struct Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    // add new product to array
    products[*numProducts] = newProduct;
    (*numProducts)++;

    printf("Product added successfully.\n");
}

// function to remove a product
void removeProduct(struct Product *products, int *numProducts) {
    int id, i, j;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // find the index of the product with the given ID
    for (i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            // shift the remaining products one index to the left
            for (j = i; j < (*numProducts) - 1; j++) {
                products[j] = products[j + 1];
            }

            (*numProducts)--;
            printf("Product removed successfully.\n");
            return;
        }
    }

    printf("Product with ID %d not found.\n", id);
}

// function to display inventory
void displayInventory(struct Product *products, int numProducts) {
    if (numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Product Inventory\n");
    printf("==============================\n");
    printf("ID\tName\tQuantity\tPrice\n");
    printf("==============================\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }

    printf("==============================\n");
}