//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT_NAME_LENGTH 100
#define MAX_PRODUCT_QUANTITY 1000
#define MAX_PRODUCTS 1000

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int numProducts;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);
    numProducts++;
}

void removeProduct() {
    printf("Enter product name to remove: ");
    char name[MAX_PRODUCT_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Removing %s with %d quantity\n", name, products[i].quantity);
            numProducts--;
            break;
        }
    }
}

void updateProductQuantity() {
    printf("Enter product name to update: ");
    char name[MAX_PRODUCT_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &products[i].quantity);
            break;
        }
    }
}

void displayProducts() {
    printf("Product Name\tQuantity\n");
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%s\t\t%d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    numProducts = 0;
    while(1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n2. Remove Product\n3. Update Product Quantity\n4. Display Products\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateProductQuantity();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}