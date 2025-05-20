//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

void addProduct(Product* products, int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    products[numProducts].quantity = 0;
    numProducts++;
}

void displayProducts(Product* products, int numProducts) {
    printf("Product Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - %d units\n", i+1, products[i].name, products[i].quantity);
    }
}

void updateQuantity(Product* products, int numProducts) {
    int productId;
    printf("Enter product ID: ");
    scanf("%d", &productId);
    if (productId >= 1 && productId <= numProducts) {
        printf("Enter new quantity: ");
        scanf("%d", &products[productId-1].quantity);
    } else {
        printf("Invalid product ID.\n");
    }
}

void removeProduct(Product* products, int numProducts) {
    int productId;
    printf("Enter product ID: ");
    scanf("%d", &productId);
    if (productId >= 1 && productId <= numProducts) {
        for (int i = productId-1; i < numProducts-1; i++) {
            strcpy(products[i].name, products[i+1].name);
            products[i].quantity = products[i+1].quantity;
        }
        numProducts--;
    } else {
        printf("Invalid product ID.\n");
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("\n1. Add product\n2. Display products\n3. Update quantity\n4. Remove product\n5. Exit\n");
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
                removeProduct(products, numProducts);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}