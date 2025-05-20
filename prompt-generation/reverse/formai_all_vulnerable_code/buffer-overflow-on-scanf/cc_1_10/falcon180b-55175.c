//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 9999.99

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name (max %d characters): ", MAX_NAME_LEN);
    scanf("%s", products[num_products].name);
    printf("Enter product description (max %d characters): ", MAX_DESCRIPTION_LEN);
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
}

void print_product(int index) {
    printf("Product name: %s\n", products[index].name);
    printf("Product description: %s\n", products[index].description);
    printf("Product quantity: %d\n", products[index].quantity);
    printf("Product price: $%.2f\n\n", products[index].price);
}

void view_inventory() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        print_product(i);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add product\n");
        printf("2. View inventory\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}