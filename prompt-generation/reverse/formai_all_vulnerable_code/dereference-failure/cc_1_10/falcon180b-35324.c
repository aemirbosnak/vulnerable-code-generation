//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char productName[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int numProducts;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* newWarehouse = (Warehouse*)malloc(sizeof(Warehouse));
    newWarehouse->numProducts = 0;
    return newWarehouse;
}

void addProduct(Warehouse* warehouse, char* productName, int quantity) {
    if (warehouse->numProducts >= MAX_WAREHOUSE_SIZE) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    Product newProduct;
    strcpy(newProduct.productName, productName);
    newProduct.quantity = quantity;

    int i;
    for (i = 0; i < warehouse->numProducts; i++) {
        if (strcmp(warehouse->products[i].productName, productName) == 0) {
            warehouse->products[i].quantity += quantity;
            return;
        }
    }

    warehouse->products[warehouse->numProducts] = newProduct;
    warehouse->numProducts++;
}

void removeProduct(Warehouse* warehouse, char* productName, int quantity) {
    int i;
    for (i = 0; i < warehouse->numProducts; i++) {
        if (strcmp(warehouse->products[i].productName, productName) == 0) {
            if (warehouse->products[i].quantity >= quantity) {
                warehouse->products[i].quantity -= quantity;
            } else {
                printf("Error: Insufficient quantity of product.\n");
            }
            return;
        }
    }

    printf("Error: Product not found.\n");
}

void displayProducts(Warehouse* warehouse) {
    printf("Product Name\tQuantity\n");
    int i;
    for (i = 0; i < warehouse->numProducts; i++) {
        printf("%s\t\t%d\n", warehouse->products[i].productName, warehouse->products[i].quantity);
    }
}

int main() {
    Warehouse* myWarehouse = createWarehouse();

    addProduct(myWarehouse, "Apples", 500);
    addProduct(myWarehouse, "Oranges", 300);

    displayProducts(myWarehouse);

    removeProduct(myWarehouse, "Apples", 100);

    displayProducts(myWarehouse);

    return 0;
}