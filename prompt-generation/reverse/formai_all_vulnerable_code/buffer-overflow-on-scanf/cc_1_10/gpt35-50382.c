//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int id;
    float price;
    int stock;
};

void addProduct(struct product products[], int* count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    struct product newProduct;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product id: ");
    scanf("%d", &newProduct.id);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product stock: ");
    scanf("%d", &newProduct.stock);

    products[*count] = newProduct;
    *count += 1;

    printf("Product added successfully!\n");
}

void removeProduct(struct product products[], int* count, int id) {
    for (int i = 0; i < *count; i++) {
        if (products[i].id == id) {
            for (int j = i; j < (*count) - 1; j++) {
                products[j] = products[j + 1];
            }
            *count -= 1;
            printf("Product %d removed successfully!\n", id);
            return;
        }
    }
    printf("Product %d not found!\n", id);
}

void viewInventory(struct product products[], int count) {
    printf("==============================================\n");
    printf("%-30s | %-10s | %-10s | %-10s\n", "Name", "ID", "Price", "Stock");
    printf("==============================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s | %-10d | %-10.2f | %-10d\n", products[i].name, products[i].id, products[i].price, products[i].stock);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int count = 0;
    int option;
    int id;

    while (1) {
        printf("\nEnter option:\n");
        printf("1-Add product\n");
        printf("2-Remove product\n");
        printf("3-View inventory\n");
        printf("4-Exit\n");

        scanf("%d", &option);

        switch (option) {
        case 1:
            addProduct(products, &count);
            break;
        case 2:
            printf("Enter product id to remove: ");
            scanf("%d", &id);
            removeProduct(products, &count, id);
            break;
        case 3:
            viewInventory(products, count);
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }

    return 0;
}