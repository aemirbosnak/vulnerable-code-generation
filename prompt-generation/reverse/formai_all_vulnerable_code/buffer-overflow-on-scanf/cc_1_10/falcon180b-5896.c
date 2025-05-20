//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product *products, int numProducts) {
    printf("Enter product name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", products[numProducts].name);

    printf("Enter product description (up to %d characters): ", MAX_DESCRIPTION_LENGTH - 1);
    scanf("%s", products[numProducts].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[numProducts].price);
}

void displayProduct(Product product) {
    printf("Name: %s\n", product.name);
    printf("Description: %s\n", product.description);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $.2f\n\n", product.price);
}

void searchProduct(Product *products, int numProducts, char *searchTerm) {
    int found = 0;
    printf("Searching for products containing '%s'...\n", searchTerm);
    for (int i = 0; i < numProducts; i++) {
        if (strstr(products[i].name, searchTerm) || strstr(products[i].description, searchTerm)) {
            displayProduct(products[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found.\n");
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter 1 to add a product, 2 to search for a product, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, numProducts);
                numProducts++;
                break;
            case 2:
                printf("Enter search term: ");
                char searchTerm[MAX_NAME_LENGTH];
                scanf("%s", searchTerm);
                searchProduct(products, numProducts, searchTerm);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}