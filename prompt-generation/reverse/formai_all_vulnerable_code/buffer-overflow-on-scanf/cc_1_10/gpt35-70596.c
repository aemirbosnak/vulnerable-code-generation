//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[20];
    int quantity;
    float price;
};

void addProduct(struct Product products[], int *productCount);
void removeProduct(struct Product products[], int *productCount);
void viewProducts(struct Product products[], int *productCount);

int main() {
    int choice, productCount = 0;
    struct Product products[100];
    do {
        printf("Product Inventory System\n");
        printf("1.Add Product\n");
        printf("2.Remove Product\n");
        printf("3.View Products\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                removeProduct(products, &productCount);
                break;
            case 3:
                viewProducts(products, &productCount);
                break;
            case 4:
                printf("Exiting Product Inventory System...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (1);
    return 0;
}

void addProduct(struct Product products[], int *productCount) {
    struct Product product;
    printf("Enter product id: ");
    scanf("%d", &product.id);
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    products[*productCount] = product;
    *productCount += 1;
}

void removeProduct(struct Product products[], int *productCount) {
    int id, i, found = 0;
    printf("Enter product id to remove: ");
    scanf("%d", &id);
    for (i = 0; i < *productCount; i++) {
        if (products[i].id == id) {
            int j = i;
            while (j < *productCount - 1) {
                products[j] = products[j+1];
                j++;
            }
            *productCount -= 1;
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Product with id %d removed successfully.\n", id);
    } else {
        printf("Product with id %d not found.\n", id);
    }
}

void viewProducts(struct Product products[], int *productCount) {
    int i;
    printf("Product Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (i = 0; i < *productCount; i++) {
        printf("%d\t%s\t%d\t%f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}