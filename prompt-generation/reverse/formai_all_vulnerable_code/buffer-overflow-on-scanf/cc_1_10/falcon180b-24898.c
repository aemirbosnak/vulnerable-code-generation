//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("Inventory Management System\n");
        printf("---------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                num_products++;
                break;
            case '2':
                printf("Enter product name to remove: ");
                scanf("%s", products[num_products - 1].name);
                num_products--;
                break;
            case '3':
                printf("Product list:\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%s - %d\n", products[i].name, products[i].quantity);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}