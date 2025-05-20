//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000.00
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double price;
    int quantity;
};

int num_products = 0;
struct product products[MAX_PRODUCTS];

void add_product() {
    num_products++;
}

void remove_product() {
    num_products--;
}

void display_products() {
    printf("Product Name | Category | Description | Price | Quantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s | %-20s | %s | $%.2f | %d\n", products[i].name, products[i].category, products[i].description, products[i].price, products[i].quantity);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double price;
    int quantity;

    do {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product category: ");
                scanf("%s", category);
                printf("Enter product description: ");
                scanf("%s", description);
                printf("Enter product price: $");
                scanf("%lf", &price);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}