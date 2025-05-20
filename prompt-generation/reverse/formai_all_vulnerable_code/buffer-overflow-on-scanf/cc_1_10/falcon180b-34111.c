//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. View all products\n");
        printf("3. Exit\n");

        int choice = 0;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_products >= MAX_PRODUCTS) {
                    printf("Maximum number of products reached.\n");
                    break;
                }

                printf("Enter product name: ");
                scanf("%s", products[num_products].name);

                printf("Enter product description: ");
                scanf("%s", products[num_products].description);

                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);

                printf("Enter product price: ");
                scanf("%lf", &products[num_products].price);

                num_products++;
                break;

            case 2:
                printf("\nProduct List:\n");
                for(int i=0; i<num_products; i++) {
                    printf("%d. %s\n", i+1, products[i].name);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}