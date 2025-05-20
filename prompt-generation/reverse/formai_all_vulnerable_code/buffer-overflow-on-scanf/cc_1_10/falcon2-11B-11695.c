//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[50];
    float price;
};

struct Product* createProduct(char* name, float price) {
    struct Product* product = (struct Product*) malloc(sizeof(struct Product));
    strcpy(product->name, name);
    product->price = price;
    return product;
}

void destroyProduct(struct Product* product) {
    free(product);
}

void addProduct(struct Product* products, char* name, float price) {
    struct Product* newProduct = createProduct(name, price);
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(products[i].name, newProduct->name) == 0) {
            printf("Product '%s' already exists.\n", newProduct->name);
            destroyProduct(newProduct);
            break;
        }
    }
    if (i == 10) {
        products[i] = *newProduct;
    }
}

void removeProduct(struct Product* products, char* name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(products[i].name, name) == 0) {
            destroyProduct(&products[i]);
            break;
        }
    }
}

void viewProducts(struct Product* products) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Product '%s' - $%.2f\n", products[i].name, products[i].price);
    }
}

int main() {
    struct Product products[10];
    char name[50];
    float price;

    while (1) {
        printf("1. Add a product\n2. Remove a product\n3. View products\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                addProduct(products, name, price);
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                removeProduct(products, name);
                break;
            case 3:
                viewProducts(products);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}