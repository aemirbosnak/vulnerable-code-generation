//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct product {
    char name[50];
    int quantity;
} Product;

Product *products;

void addProduct(char name[], int quantity) {
    Product p;
    strcpy(p.name, name);
    p.quantity = quantity;
    products = realloc(products, sizeof(Product) * (products? products[0].quantity + 1 : 1));
    products[products? products[0].quantity : 0] = p;
}

void removeProduct(char name[]) {
    int i;
    for (i = 0; i < products? products[i].quantity : 0; i++) {
        if (strcmp(products[i].name, name) == 0) {
            if (i < products? products[i].quantity : 0) {
                for (; i < products? products[i].quantity : 0; i++)
                    products[i - 1] = products[i];
                products[products? products[i].quantity : 0].quantity--;
                return;
            }
            else
                free(products);
            products = realloc(products, sizeof(Product) * (products? products[0].quantity : 1));
            return;
        }
    }
}

void printProducts() {
    int i;
    for (i = 0; i < products? products[i].quantity : 0; i++)
        printf("%s: %d\n", products[i].name, products[i].quantity);
}

int main() {
    int choice;
    char name[50];

    while (1) {
        printf("Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Print Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                addProduct(name, 100);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                removeProduct(name);
                break;
            case 3:
                printProducts();
                break;
            case 4:
                printf("Thank you for using the Inventory System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}