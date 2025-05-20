//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_ORDERS 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int orderId;
    int productId;
    int quantity;
} Order;

Product products[MAX_PRODUCTS];
Order orders[MAX_ORDERS];

int numProducts = 0;
int numOrders = 0;

void addProduct(char* name, int quantity, float price) {
    numProducts++;
    strcpy(products[numProducts-1].name, name);
    products[numProducts-1].quantity = quantity;
    products[numProducts-1].price = price;
}

void addOrder(int orderId, int productId, int quantity) {
    numOrders++;
    orders[numOrders-1].orderId = orderId;
    orders[numOrders-1].productId = productId;
    orders[numOrders-1].quantity = quantity;
}

void displayProducts() {
    printf("Product List:\n");
    for (int i=0; i<numProducts; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void displayOrders() {
    printf("\nOrder List:\n");
    for (int i=0; i<numOrders; i++) {
        printf("%d. Order %d - %d units of product %d - $%.2f\n", i+1, orders[i].orderId, orders[i].quantity, orders[i].productId, products[orders[i].productId-1].price*orders[i].quantity);
    }
}

int main() {
    addProduct("Widget A", 100, 5.99);
    addProduct("Widget B", 50, 9.99);
    addProduct("Widget C", 25, 19.99);

    addOrder(1, 0, 10);
    addOrder(2, 1, 5);
    addOrder(3, 2, 2);

    displayProducts();
    displayOrders();

    return 0;
}