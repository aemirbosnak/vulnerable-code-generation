//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_PRODUCT_NAME_SIZE 100

// Define a structure for the warehouse
typedef struct {
    char name[MAX_PRODUCT_NAME_SIZE];
    int quantity;
    float price;
} Product;

// Define a structure for the warehouse
typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int num_products;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    if (!w) {
        printf("Error: could not allocate memory for warehouse.\n");
        exit(1);
    }
    w->num_products = 0;
    return w;
}

void addProduct(Warehouse* w, char* name, int quantity, float price) {
    if (w->num_products >= MAX_WAREHOUSE_SIZE) {
        printf("Error: warehouse is full.\n");
        return;
    }
    Product p;
    strcpy(p.name, name);
    p.quantity = quantity;
    p.price = price;
    w->products[w->num_products++] = p;
}

void removeProduct(Warehouse* w, int index) {
    if (index < 0 || index >= w->num_products) {
        printf("Error: invalid product index.\n");
        return;
    }
    w->num_products--;
    for (int i = index; i < w->num_products; i++) {
        w->products[i] = w->products[i+1];
    }
}

void printProductList(Warehouse* w) {
    printf("Product List:\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

int main() {
    Warehouse* w = createWarehouse();

    addProduct(w, "Apples", 100, 0.50);
    addProduct(w, "Oranges", 50, 0.75);
    addProduct(w, "Bananas", 200, 0.25);

    printProductList(w);

    removeProduct(w, 1);

    printProductList(w);

    return 0;
}