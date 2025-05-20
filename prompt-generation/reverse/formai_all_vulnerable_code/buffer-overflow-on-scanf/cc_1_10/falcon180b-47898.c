//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void addProduct() {
    printf("Enter product name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void removeProduct() {
    int index;

    printf("Enter product index to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_products) {
        num_products--;

        for (int i = index; i < num_products; i++) {
            strcpy(products[i].name, products[i+1].name);
            products[i].quantity = products[i+1].quantity;
            products[i].price = products[i+1].price;
        }
    }
}

void updateProduct() {
    int index;

    printf("Enter product index to update: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_products) {
        printf("Enter new product name (max %d characters): ", MAX_NAME_LEN - 1);
        scanf("%s", products[index].name);

        printf("Enter new product quantity: ");
        scanf("%d", &products[index].quantity);

        printf("Enter new product price: ");
        scanf("%f", &products[index].price);
    }
}

void displayProducts() {
    printf("Product Name\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display products\n");
        printf("5. Exit\n");

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
                updateProduct();
                break;

            case 4:
                displayProducts();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}