//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} product;

void addProduct(product *products, int numProducts, char *name, int quantity, double price) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            return;
        }
    }
    strcpy(products[numProducts].name, name);
    products[numProducts].quantity = quantity;
    products[numProducts].price = price;
    numProducts++;
}

void removeProduct(product *products, int numProducts, char *name) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i] = products[numProducts - 1];
            numProducts--;
            return;
        }
    }
}

void displayProducts(product *products, int numProducts) {
    printf("Product Name\tQuantity\tPrice\n");
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    product products[MAX_PRODUCTS];
    int numProducts = 0;
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n2. Remove product\n3. Display products\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%lf", &price);
                addProduct(products, numProducts, name, quantity, price);
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                removeProduct(products, numProducts, name);
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}