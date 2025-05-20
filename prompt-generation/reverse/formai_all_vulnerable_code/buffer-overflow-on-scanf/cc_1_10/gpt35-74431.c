//FormAI DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float price;
    int count;
} Product;

void addProduct(Product products[], int *numProducts) {
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product count: ");
    scanf("%d", &newProduct.count);
    products[*numProducts] = newProduct;
    *numProducts += 1;
    printf("Product added successfully!\n\n");
}

void displayProducts(Product products[], int numProducts) {
    printf("Product Inventory\n");
    printf("-----------------\n");
    for (int i=0; i<numProducts; i++) {
        printf("Name: %s\n", products[i].name);
        printf("ID: %d\n", products[i].id);
        printf("Price: $%.2f\n", products[i].price);
        printf("Count: %d\n", products[i].count);
        printf("-----------------\n");
    }
}

void searchProduct(Product products[], int numProducts) {
    int searchId;
    printf("Enter product ID to search: ");
    scanf("%d", &searchId);
    for (int i=0; i<numProducts; i++) {
        if (products[i].id == searchId) {
            printf("Name: %s\n", products[i].name);
            printf("Price: $%.2f\n", products[i].price);
            printf("Count: %d\n", products[i].count);
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct(Product products[], int *numProducts) {
    int deleteId;
    printf("Enter product ID to delete: ");
    scanf("%d", &deleteId);
    for (int i=0; i<*numProducts; i++) {
        if (products[i].id == deleteId) {
            for (int j=i+1; j<*numProducts; j++) {
                products[j-1] = products[j];
            }
            *numProducts -= 1;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search for product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                searchProduct(products, numProducts);
                break;
            case 4:
                deleteProduct(products, &numProducts);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}