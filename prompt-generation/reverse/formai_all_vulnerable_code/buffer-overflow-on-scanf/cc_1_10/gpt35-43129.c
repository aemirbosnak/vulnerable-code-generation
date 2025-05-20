//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold product information */
typedef struct Product {
    char name[20];
    int id;
    double price;
    int quantity;
} Product;

/* Function to print out a product */
void printProduct(Product p) {
    printf("%d: %s - $%0.2f - %d in stock\n", p.id, p.name, p.price, p.quantity);
}

/* Function to add a product to the inventory */
void addProduct(Product *inventory, int *numProducts) {
    char name[20];
    double price;
    int quantity;

    printf("Enter product name: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter product price: ");
    scanf("%lf", &price);

    printf("Enter number of products in stock: ");
    scanf("%d", &quantity);

    /* Create new product */
    Product newProduct;
    strncpy(newProduct.name, name, 20);
    newProduct.price = price;
    newProduct.quantity = quantity;

    /* Add new product to inventory and increment product count */
    inventory[*numProducts] = newProduct;
    (*numProducts)++;
}

/* Function to remove a product from the inventory */
void removeProduct(Product *inventory, int *numProducts, int productId) {
    int i;
    int productIndex = -1;

    /* Find index of product to remove */
    for (i = 0; i < *numProducts; i++) {
        if (inventory[i].id == productId) {
            productIndex = i;
            break;
        }
    }

    /* If product was found, remove it */
    if (productIndex != -1) {
        for (i = productIndex; i < *numProducts-1; i++) {
            inventory[i] = inventory[i+1];
        }

        (*numProducts)--;
        printf("Product removed successfully!\n");
    } else {
        printf("Product not found.\n");
    }
}

/* Function to update the quantity of a product in the inventory */
void updateQuantity(Product *inventory, int numProducts, int productId, int newQuantity) {
    int i;

    /* Find product and update quantity */
    for (i = 0; i < numProducts; i++) {
        if (inventory[i].id == productId) {
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    /* Product not found */
    printf("Product not found.\n");
}

/* Main function */
int main() {
    Product inventory[50];
    int numProducts = 0;
    int choice;
    int productId;
    int newQuantity;

    printf("Welcome to our Product Inventory System!\n");

    /* Enter main loop */
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. View all products\n");
        printf("2. Add a product\n");
        printf("3. Remove a product\n");
        printf("4. Update product quantity\n");
        printf("5. Exit program\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* View all products */
                if (numProducts == 0) {
                    printf("No products in inventory.\n");
                } else {
                    int i;
                    for (i = 0; i < numProducts; i++) {
                        printProduct(inventory[i]);
                    }
                }
                break;

            case 2:
                /* Add a product */
                addProduct(inventory, &numProducts);
                printf("Product added successfully!\n");
                break;

            case 3:
                /* Remove a product */
                printf("Enter ID of product to remove: ");
                scanf("%d", &productId);

                removeProduct(inventory, &numProducts, productId);
                break;

            case 4:
                /* Update product quantity */
                printf("Enter ID of product to update: ");
                scanf("%d", &productId);

                printf("Enter new quantity: ");
                scanf("%d", &newQuantity);

                updateQuantity(inventory, numProducts, productId, newQuantity);
                break;

            case 5:
                /* Exit program */
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}