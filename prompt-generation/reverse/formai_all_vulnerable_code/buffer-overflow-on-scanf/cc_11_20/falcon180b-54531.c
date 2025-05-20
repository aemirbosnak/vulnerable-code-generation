//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50
#define MAX_CODE 10

struct product {
    char name[MAX_NAME];
    char code[MAX_CODE];
    int quantity;
    double price;
};

int main() {
    int choice, i;
    char option[3];
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the Product Inventory System!\n");
    printf("Please choose an option:\n");
    printf("1. Add product\n");
    printf("2. View product list\n");
    printf("3. Update product\n");
    printf("4. Delete product\n");
    printf("5. Exit\n");

    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product code: ");
                scanf("%s", products[num_products].code);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: ");
                scanf("%lf", &products[num_products].price);
                num_products++;
                break;
            case 2:
                printf("Product List:\n");
                for(i=0; i<num_products; i++) {
                    printf("%s\t%s\t%d\t$%.2lf\n", products[i].name, products[i].code, products[i].quantity, products[i].price);
                }
                break;
            case 3:
                printf("Enter product code to update: ");
                scanf("%s", option);
                for(i=0; i<num_products; i++) {
                    if(strcmp(option, products[i].code) == 0) {
                        printf("Enter new product name: ");
                        scanf("%s", products[i].name);
                        printf("Enter new product quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Enter new product price: ");
                        scanf("%lf", &products[i].price);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter product code to delete: ");
                scanf("%s", option);
                for(i=0; i<num_products; i++) {
                    if(strcmp(option, products[i].code) == 0) {
                        num_products--;
                        break;
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}