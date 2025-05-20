//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    num_products++;
}

void remove_product(int index) {
    num_products--;
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s (%s) - %d units - $%.2f\n", i+1, products[i].name, products[i].category, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;

    num_products = 0;

    while (1) {
        printf("Product Inventory System\n");
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
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: $");
                scanf("%f", &price);

                add_product();

                strcpy(products[num_products-1].name, name);
                strcpy(products[num_products-1].category, category);
                products[num_products-1].quantity = quantity;
                products[num_products-1].price = price;

                break;
            case 2:
                printf("Enter product index to remove: ");
                scanf("%d", &index);

                remove_product(index-1);

                break;
            case 3:
                display_products();

                break;
            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}