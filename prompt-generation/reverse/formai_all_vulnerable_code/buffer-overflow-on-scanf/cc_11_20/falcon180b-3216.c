//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} product_t;

int main() {
    product_t products[MAX_PRODUCTS];
    int num_products = 0;
    int choice = 0;
    char input[100];

    while(1) {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", input);
                strcpy(products[num_products].name, input);
                printf("Enter product price: ");
                scanf("%s", products[num_products].price);
                products[num_products].quantity = 0;
                num_products++;
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", input);
                for(int i=0; i<num_products; i++) {
                    if(strcmp(products[i].name, input) == 0) {
                        printf("Product removed: %s\n", products[i].name);
                        for(int j=i; j<num_products-1; j++) {
                            products[j] = products[j+1];
                        }
                        num_products--;
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter product name to update: ");
                scanf("%s", input);
                for(int i=0; i<num_products; i++) {
                    if(strcmp(products[i].name, input) == 0) {
                        printf("Enter new product name: ");
                        scanf("%s", products[i].name);
                        printf("Enter new product price: ");
                        scanf("%s", products[i].price);
                        break;
                    }
                }
                break;
            case 4:
                printf("Product Name\tPrice\tQuantity\n");
                for(int i=0; i<num_products; i++) {
                    printf("%s\t%s\t%d\n", products[i].name, products[i].price, products[i].quantity);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}