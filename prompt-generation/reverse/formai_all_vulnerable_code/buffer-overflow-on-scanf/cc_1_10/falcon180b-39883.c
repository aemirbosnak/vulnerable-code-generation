//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

void addProduct(Product* products, int count, char* name, int quantity) {
    if (count >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }
    strcpy(products[count].name, name);
    products[count].quantity = quantity;
    count++;
}

void removeProduct(Product* products, int* count, char* name) {
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            *count -= 1;
            memmove(&products[i], &products[i + 1], sizeof(Product) * (*count - i));
            return;
        }
    }
    printf("Error: Product not found.\n");
}

void displayProducts(Product* products, int count) {
    printf("Product Name\tQuantity\n");
    printf("--------------------------------------------------\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t%d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    char name[MAX_NAME_LEN];
    int choice, quantity;

    while (1) {
        printf("Product Inventory System\n");
        printf("1. Add Product\n2. Remove Product\n3. Display Products\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addProduct(products, count, name, quantity);
            break;
        case 2:
            printf("Enter product name to remove: ");
            scanf("%s", name);
            removeProduct(products, &count, name);
            break;
        case 3:
            displayProducts(products, count);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}