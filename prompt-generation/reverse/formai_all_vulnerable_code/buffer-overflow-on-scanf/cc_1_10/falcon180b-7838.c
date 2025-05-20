//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void initProduct(Product *p) {
    strcpy(p->name, "");
    p->quantity = 0;
    p->price = 0.0;
}

void displayProduct(Product p) {
    printf("Name: %s\n", p.name);
    printf("Quantity: %d\n", p.quantity);
    printf("Price: $%.2f\n", p.price);
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter product name (leave blank to finish): ");
        scanf("%s", products[numProducts].name);

        if (strcmp(products[numProducts].name, "") == 0) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &products[numProducts].quantity);

        printf("Enter price: ");
        scanf("%f", &products[numProducts].price);

        numProducts++;
    }

    printf("\nProduct Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        displayProduct(products[i]);
    }

    return 0;
}