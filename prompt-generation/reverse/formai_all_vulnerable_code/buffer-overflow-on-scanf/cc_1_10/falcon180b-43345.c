//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void removeProduct() {
    if (num_products == 0) {
        printf("Error: No products found.\n");
        return;
    }

    printf("Enter product name to remove: ");
    char name[50];
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    num_products--;
    for (int i = index; i < num_products; i++) {
        strcpy(products[i].name, products[i+1].name);
        products[i].quantity = products[i+1].quantity;
        products[i].price = products[i+1].price;
    }
}

void displayProducts() {
    if (num_products == 0) {
        printf("No products found.\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct() {
    if (num_products == 0) {
        printf("No products found.\n");
        return;
    }

    printf("Enter product name to search: ");
    char name[50];
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found.\n");
    } else {
        printf("Product found.\n");
        printf("Product Name: %s\n", products[index].name);
        printf("Quantity: %d\n", products[index].quantity);
        printf("Price: $%.2f\n", products[index].price);
    }
}

int main() {
    printf("Product Inventory System\n");

    while (1) {
        printf("1. Add product\n2. Remove product\n3. Display products\n4. Search product\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            removeProduct();
            break;
        case 3:
            displayProducts();
            break;
        case 4:
            searchProduct();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}