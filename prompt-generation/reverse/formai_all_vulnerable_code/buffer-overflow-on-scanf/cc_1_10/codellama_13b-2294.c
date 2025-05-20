//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

void displayProducts(struct Product products[], int numProducts) {
    printf("---------------------------------\n");
    printf("Product ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("---------------------------------\n");
}

void addProduct(struct Product products[], int* numProducts) {
    printf("Enter the product ID: ");
    int id = 0;
    scanf("%d", &id);
    printf("Enter the product name: ");
    char name[50];
    scanf("%s", name);
    printf("Enter the product price: ");
    float price = 0.0;
    scanf("%f", &price);
    printf("Enter the product quantity: ");
    int quantity = 0;
    scanf("%d", &quantity);
    products[*numProducts].id = id;
    strcpy(products[*numProducts].name, name);
    products[*numProducts].price = price;
    products[*numProducts].quantity = quantity;
    (*numProducts)++;
}

void removeProduct(struct Product products[], int* numProducts) {
    printf("Enter the product ID to remove: ");
    int id = 0;
    scanf("%d", &id);
    for (int i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            products[i] = products[*numProducts - 1];
            (*numProducts)--;
            break;
        }
    }
}

void updateProduct(struct Product products[], int* numProducts) {
    printf("Enter the product ID to update: ");
    int id = 0;
    scanf("%d", &id);
    for (int i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            printf("Enter the new product name: ");
            char name[50];
            scanf("%s", name);
            strcpy(products[i].name, name);
            printf("Enter the new product price: ");
            float price = 0.0;
            scanf("%f", &price);
            products[i].price = price;
            printf("Enter the new product quantity: ");
            int quantity = 0;
            scanf("%d", &quantity);
            products[i].quantity = quantity;
            break;
        }
    }
}

int main() {
    int numProducts = 0;
    struct Product products[100];
    char option = ' ';
    while (option != 'q') {
        printf("Menu\n");
        printf("1. Display products\n");
        printf("2. Add product\n");
        printf("3. Remove product\n");
        printf("4. Update product\n");
        printf("q. Quit\n");
        printf("Enter your option: ");
        scanf(" %c", &option);
        switch (option) {
            case '1':
                displayProducts(products, numProducts);
                break;
            case '2':
                addProduct(products, &numProducts);
                break;
            case '3':
                removeProduct(products, &numProducts);
                break;
            case '4':
                updateProduct(products, &numProducts);
                break;
            case 'q':
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}