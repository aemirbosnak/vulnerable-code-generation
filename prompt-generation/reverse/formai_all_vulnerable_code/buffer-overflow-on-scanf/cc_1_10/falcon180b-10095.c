//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void removeProduct() {
    printf("Enter product name to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Removing %s with %d quantity\n", name, products[i].quantity);
            num_products--;
            break;
        }
    }
}

void updateProduct() {
    printf("Enter product name to update: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            break;
        }
    }
}

void displayProducts() {
    printf("Product Inventory:\n");
    printf("-------------------\n");
    printf("Name\t\tQuantity\n");
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s\t\t%d\n", products[i].name, products[i].quantity);
    }
    printf("-------------------\n");
}

int main() {
    num_products = 0;
    printf("Welcome to the product inventory system\n");
    while (1) {
        printf("1. Add Product\n2. Remove Product\n3. Update Product\n4. Display Products\n5. Exit\n");
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}