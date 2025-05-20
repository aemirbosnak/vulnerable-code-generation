//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int productCount;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter product price: ");
    scanf("%f", &products[productCount].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[productCount].quantity);
    productCount++;
}

void displayProducts() {
    printf("Product Name\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%s\t%.2f\t%d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

void searchProduct() {
    printf("Enter product name to search: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("Product found:\n");
            printf("Product Name: %s\n", products[i].name);
            printf("Product Price: %.2f\n", products[i].price);
            printf("Product Quantity: %d\n", products[i].quantity);
        }
    }
}

void updateProduct() {
    printf("Enter product name to update: ");
    char updateName[MAX_NAME_LENGTH];
    scanf("%s", updateName);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, updateName) == 0) {
            printf("Product found:\n");
            printf("Enter new product name: ");
            scanf("%s", products[i].name);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
        }
    }
}

void deleteProduct() {
    printf("Enter product name to delete: ");
    char deleteName[MAX_NAME_LENGTH];
    scanf("%s", deleteName);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, deleteName) == 0) {
            printf("Product deleted:\n");
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
        }
    }
}

int main() {
    productCount = 0;
    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        printf("\n1. Add product\n2. Display products\n3. Search product\n4. Update product\n5. Delete product\n6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 3:
            searchProduct();
            break;
        case 4:
            updateProduct();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}