//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[50];
    double price;
    int quantity;
};

void addProduct(struct Product* products, int* count) {
    int id;
    char name[50];
    double price;
    int quantity;

    printf("Enter product id: ");
    scanf("%d", &id);
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%lf", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    struct Product newProduct;
    newProduct.id = id;
    strcpy(newProduct.name, name);
    newProduct.price = price;
    newProduct.quantity = quantity;

    products[*count].id = id;
    strcpy(products[*count].name, name);
    products[*count].price = price;
    products[*count].quantity = quantity;

    (*count)++;
}

void displayProducts(struct Product* products, int count) {
    printf("Product Inventory System\n\n");
    printf("ID | Name | Price | Quantity\n");
    printf("-------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d | %s | %.2lf | %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    struct Product products[10];
    int count = 0;

    printf("Welcome to the Product Inventory System!\n\n");
    while (1) {
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}