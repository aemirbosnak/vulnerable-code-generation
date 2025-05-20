//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
// C Warehouse Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Order;

// Functions

void addProduct(Product *product) {
    printf("Enter product name: ");
    scanf("%s", product->name);
    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter product price: ");
    scanf("%f", &product->price);
}

void addOrder(Order *order) {
    printf("Enter order name: ");
    scanf("%s", order->name);
    printf("Enter order quantity: ");
    scanf("%d", &order->quantity);
    printf("Enter order price: ");
    scanf("%f", &order->price);
}

void displayProducts(Product *products, int numProducts) {
    printf("Products:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - %d units - $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void displayOrders(Order *orders, int numOrders) {
    printf("Orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%d. %s - %d units - $%.2f\n", orders[i].id, orders[i].name, orders[i].quantity, orders[i].price);
    }
}

void processOrder(Order *orders, int numOrders, Product *products, int numProducts) {
    printf("Processing order...\n");
    for (int i = 0; i < numOrders; i++) {
        for (int j = 0; j < numProducts; j++) {
            if (strcmp(orders[i].name, products[j].name) == 0) {
                if (orders[i].quantity <= products[j].quantity) {
                    products[j].quantity -= orders[i].quantity;
                    break;
                }
            }
        }
    }
}

// Main function

int main() {
    // Initialize products and orders
    Product products[100];
    int numProducts = 0;
    Order orders[100];
    int numOrders = 0;

    // Add products and orders
    while (1) {
        printf("1. Add product\n");
        printf("2. Add order\n");
        printf("3. Display products\n");
        printf("4. Display orders\n");
        printf("5. Process order\n");
        printf("6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(&products[numProducts]);
                numProducts++;
                break;
            case 2:
                addOrder(&orders[numOrders]);
                numOrders++;
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                displayOrders(orders, numOrders);
                break;
            case 5:
                processOrder(orders, numOrders, products, numProducts);
                break;
            case 6:
                return 0;
        }
    }
}