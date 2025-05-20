//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product* products, int numProducts, char* name, int quantity, float price) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            return;
        }
    }
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;
    products[numProducts] = newProduct;
    numProducts++;
}

void removeProduct(Product* products, int numProducts, char* name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i] = products[numProducts - 1];
            numProducts--;
            return;
        }
    }
}

void displayProducts(Product* products, int numProducts) {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[100];
    int numProducts = 0;
    while (1) {
        printf("1. Add product\n2. Remove product\n3. Display products\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            char name[50];
            int quantity;
            float price;
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            addProduct(products, numProducts, name, quantity, price);
            numProducts++;
            break;
        }
        case 2: {
            char name[50];
            printf("Enter product name: ");
            scanf("%s", name);
            removeProduct(products, numProducts, name);
            numProducts--;
            break;
        }
        case 3: {
            displayProducts(products, numProducts);
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            printf("Invalid choice\n");
        }
        }
    }
    return 0;
}