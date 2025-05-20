//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_QUANTITY 100

typedef struct {
    char productName[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int currentProductCount;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->currentProductCount = 0;
    for (int i = 0; i < MAX_WAREHOUSE_SIZE; i++) {
        strcpy(warehouse->products[i].productName, "");
        warehouse->products[i].quantity = 0;
    }
    return warehouse;
}

void destroyWarehouse(Warehouse* warehouse) {
    free(warehouse);
}

int addProduct(Warehouse* warehouse, char* productName, int quantity) {
    if (warehouse->currentProductCount >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full!\n");
        return -1;
    }
    strcpy(warehouse->products[warehouse->currentProductCount].productName, productName);
    warehouse->products[warehouse->currentProductCount].quantity = quantity;
    warehouse->currentProductCount++;
    return 0;
}

int removeProduct(Warehouse* warehouse, char* productName) {
    for (int i = 0; i < warehouse->currentProductCount; i++) {
        if (strcmp(warehouse->products[i].productName, productName) == 0) {
            warehouse->products[i].productName[0] = '\0';
            warehouse->products[i].quantity = 0;
            return 0;
        }
    }
    printf("Product not found!\n");
    return -1;
}

void printWarehouse(Warehouse* warehouse) {
    printf("Current warehouse status:\n");
    printf("-------------------------\n");
    for (int i = 0; i < warehouse->currentProductCount; i++) {
        printf("%s - %d units\n", warehouse->products[i].productName, warehouse->products[i].quantity);
    }
    printf("-------------------------\n");
}

int main() {
    Warehouse* warehouse = createWarehouse();
    addProduct(warehouse, "Apples", 50);
    addProduct(warehouse, "Oranges", 100);
    printWarehouse(warehouse);
    removeProduct(warehouse, "Apples");
    printWarehouse(warehouse);
    destroyWarehouse(warehouse);
    return 0;
}