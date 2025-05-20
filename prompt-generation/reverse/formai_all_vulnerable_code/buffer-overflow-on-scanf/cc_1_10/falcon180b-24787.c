//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} product;

void addProduct(product *products, int numProducts, char *name, int quantity) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            return;
        }
    }
    strcpy(products[numProducts].name, name);
    products[numProducts].quantity = quantity;
    numProducts++;
}

void removeProduct(product *products, int numProducts, char *name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;
            return;
        }
    }
}

void displayProducts(product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    product products[MAX_PRODUCTS];
    int numProducts = 0;
    char choice;
    do {
        printf("Warehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter product name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter quantity: ");
                int quantity;
                scanf("%d", &quantity);
                addProduct(products, numProducts, name, quantity);
                break;
            case '2':
                printf("Enter product name: ");
                char name2[MAX_NAME_LENGTH];
                scanf("%s", name2);
                removeProduct(products, numProducts, name2);
                break;
            case '3':
                displayProducts(products, numProducts);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');
    return 0;
}