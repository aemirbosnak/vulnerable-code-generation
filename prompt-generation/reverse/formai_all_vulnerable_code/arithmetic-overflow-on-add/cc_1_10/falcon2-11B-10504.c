//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>

void addProduct(int *products, int productID, int quantity) {
    if (productID == 0) {
        printf("Adding product ID: %d with quantity: %d\n", productID, quantity);
        *products = *products + quantity;
    } else {
        addProduct(products, productID - 1, quantity);
    }
}

void removeProduct(int *products, int productID, int quantity) {
    if (productID == 0) {
        printf("Removing product ID: %d with quantity: %d\n", productID, quantity);
        *products = *products - quantity;
    } else {
        removeProduct(products, productID - 1, quantity);
    }
}

void searchProduct(int *products, int productID) {
    if (productID == 0) {
        printf("Product ID: %d not found\n", productID);
    } else {
        searchProduct(products, productID - 1);
    }
}

int main() {
    int products[10];
    int quantity;

    printf("Enter the quantity of products:\n");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        int productID;
        printf("Enter the product ID:\n");
        scanf("%d", &productID);

        int productQuantity;
        printf("Enter the quantity of the product:\n");
        scanf("%d", &productQuantity);

        addProduct(products, productID, productQuantity);
    }

    printf("Products in store:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", products[i]);
    }

    printf("\n");

    int searchID;
    printf("Enter the product ID to search for:\n");
    scanf("%d", &searchID);

    searchProduct(products, searchID);

    return 0;
}