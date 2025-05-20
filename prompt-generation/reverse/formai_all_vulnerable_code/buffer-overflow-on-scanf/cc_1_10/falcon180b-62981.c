//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} product;

int num_products = 0;
product products[MAX_PRODUCTS];

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
}

void display_products() {
    printf("\nProduct Inventory:\n");
    printf("-------------------------------------------------\n");
    printf("ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2lf\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    printf("-------------------------------------------------\n");

    while (1) {
        printf("\n1. Add product\n2. Display products\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}