//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>

struct product {
    char name[20];
    int quantity;
    float price;
};

struct warehouse {
    struct product products[100];
    int count;
};

struct warehouse myWarehouse;

void addProduct(char name[20], int quantity, float price) {
    if (myWarehouse.count == 100) {
        printf("Warehouse is full, cannot add product.\n");
        return;
    }
    struct product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;
    myWarehouse.products[myWarehouse.count] = newProduct;
    myWarehouse.count++;
}

void removeProduct(int productIndex) {
    if (productIndex < 0 || productIndex >= myWarehouse.count) {
        printf("Invalid product index.\n");
        return;
    }
    for (int i = productIndex; i < myWarehouse.count - 1; i++) {
        myWarehouse.products[i] = myWarehouse.products[i+1];
    }
    myWarehouse.count--;
}

void printWarehouse() {
    printf("Warehouse:\n");
    for (int i = 0; i < myWarehouse.count; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", i+1, myWarehouse.products[i].name, myWarehouse.products[i].quantity, myWarehouse.products[i].price);
    }
}

int main() {
    myWarehouse.count = 0;
    printf("Welcome to the Warehouse Management System\n\n");
    int choice = -1;
    while (choice != 0) {
        printf("Menu:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Print Warehouse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            char name[20];
            int quantity;
            float price;
            printf("Enter the name of the product: ");
            scanf("%s", name);
            printf("Enter the quantity of the product: ");
            scanf("%d", &quantity);
            printf("Enter the price of the product: ");
            scanf("%f", &price);
            addProduct(name, quantity, price);
            printf("Product added.\n");
        } else if (choice == 2) {
            int productIndex;
            printf("Enter the index of the product to remove: ");
            scanf("%d", &productIndex);
            removeProduct(productIndex-1);
            printf("Product removed.\n");
        } else if (choice == 3) {
            printWarehouse();
        }
        printf("\n");
    }
    printf("Goodbye!\n");
    return 0;
}