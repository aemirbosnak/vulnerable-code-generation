//FormAI DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

void addProduct(Product products[], int* count) {
    char name[50];
    float price;
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    // Create new product instance
    Product product;
    strcpy(product.name, name);
    product.price = price;
    product.quantity = quantity;

    // Add to products array
    products[*count] = product;
    (*count)++;

    printf("Product added successfully!\n");
}

void listProducts(Product products[], int count) {
    printf("------Product List------\n");

    for (int i = 0; i < count; i++) {
        Product product = products[i];
        printf("Name: %s\n", product.name);
        printf("Price: $%.2f\n", product.price);
        printf("Quantity: %d\n", product.quantity);
        printf("------------------------\n");
    }
}

void searchProduct(Product products[], int count) {
    printf("Enter product name: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        Product product = products[i];
        if (strcmp(product.name, name) == 0) {
            printf("Name: %s\n", product.name);
            printf("Price: $%.2f\n", product.price);
            printf("Quantity: %d\n", product.quantity);
            return;
        }
    }

    printf("Product not found\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;

    while (1) {
        printf("----Product Inventory System----\n");
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                listProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please choose again\n");
        }

        printf("\n");
    }

    return 0;
}