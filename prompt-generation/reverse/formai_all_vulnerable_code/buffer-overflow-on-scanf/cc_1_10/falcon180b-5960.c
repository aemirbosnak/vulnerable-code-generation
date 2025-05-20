//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(Product *product) {
    strcpy(product->name, "");
    strcpy(product->description, "");
    product->quantity = 0;
    product->price = 0;
}

void print_product(Product product) {
    printf("Name: %s\n", product.name);
    printf("Description: %s\n", product.description);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2f\n\n", product.price);
}

void print_all_products() {
    printf("Product Inventory\n\n");
    for (int i = 0; i < num_products; i++) {
        print_product(products[i]);
    }
}

void remove_product(int index) {
    num_products--;
    for (int i = index; i < num_products; i++) {
        products[i] = products[i+1];
    }
    products[num_products].name[0] = '\0';
    products[num_products].description[0] = '\0';
    products[num_products].quantity = 0;
    products[num_products].price = 0;
}

int main() {
    int choice;

    printf("Welcome to the Product Inventory System\n");
    printf("1. Add product\n");
    printf("2. Print products\n");
    printf("3. Remove product\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);
            printf("Enter product description: ");
            scanf("%s", products[num_products].description);
            printf("Enter product quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter product price: ");
            scanf("%f", &products[num_products].price);
            num_products++;
            break;
        case 2:
            print_all_products();
            break;
        case 3:
            printf("Enter product index to remove: ");
            scanf("%d", &choice);
            remove_product(choice);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}