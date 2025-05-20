//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 10000.00

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Too many products.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("Product Inventory:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

void surrealist_inventory() {
    srand(time(NULL));

    int choice;
    do {
        printf("Surrealist Inventory:\n");
        printf("----------------------\n");
        printf("1. Add a product\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
}

int main() {
    surrealist_inventory();
    return 0;
}