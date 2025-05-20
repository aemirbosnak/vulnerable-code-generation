//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void surreal_menu() {
    printf("Surreal Product Inventory System\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. View products\n");
    printf("4. Exit\n");
}

void surreal_add_product() {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product price: ");
    scanf("%s", price);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    strcpy(products[num_products].name, name);
    strcpy(products[num_products].price, price);
    products[num_products].quantity = quantity;

    num_products++;
}

void surreal_remove_product() {
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    if (id >= 0 && id < num_products) {
        num_products--;
        for (int i = id; i < num_products; i++) {
            strcpy(products[i].name, products[i+1].name);
            strcpy(products[i].price, products[i+1].price);
            products[i].quantity = products[i+1].quantity;
        }
    } else {
        printf("Invalid product ID\n");
    }
}

void surreal_view_products() {
    printf("Product ID | Name | Price | Quantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | %d\n", i, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    surreal_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                surreal_add_product();
                break;
            case 2:
                surreal_remove_product();
                break;
            case 3:
                surreal_view_products();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}