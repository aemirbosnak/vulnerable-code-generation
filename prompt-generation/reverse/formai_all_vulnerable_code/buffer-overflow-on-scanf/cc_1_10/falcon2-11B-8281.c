//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct product {
    int id;
    char name[100];
    double price;
    int quantity;
} Product;

void createProduct(Product *product, char *name, double price, int quantity) {
    product->id = getNextId();
    strcpy(product->name, name);
    product->price = price;
    product->quantity = quantity;
}

int getNextId() {
    static int idCounter = 1;
    return idCounter++;
}

void printProduct(Product product) {
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Price: $%.2f\n", product.price);
    printf("Quantity: %d\n", product.quantity);
}

int main() {
    Product products[10];

    int i;
    for (i = 0; i < 10; i++) {
        char name[100];
        double price;
        int quantity;

        printf("Enter product %d's name: ", i+1);
        scanf("%s", name);
        printf("Enter product %d's price: ", i+1);
        scanf("%lf", &price);
        printf("Enter product %d's quantity: ", i+1);
        scanf("%d", &quantity);

        createProduct(&products[i], name, price, quantity);
    }

    for (i = 0; i < 10; i++) {
        printProduct(products[i]);
    }

    return 0;
}