//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LEN];
    int quantity;
};

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_products >= MAX_PRODUCTS) {
                printf("Maximum number of products reached.\n");
            } else {
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                num_products++;
            }
            break;
        case 2:
            if (num_products == 0) {
                printf("No products to remove.\n");
            } else {
                printf("Enter product name to remove: ");
                scanf("%s", products[0].name);
                for (int i = 0; i < num_products - 1; i++) {
                    strcpy(products[i].name, products[i+1].name);
                    products[i].quantity = products[i+1].quantity;
                }
                num_products--;
            }
            break;
        case 3:
            printf("Product Name\t\tQuantity\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s\t\t%d\n", products[i].name, products[i].quantity);
            }
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}