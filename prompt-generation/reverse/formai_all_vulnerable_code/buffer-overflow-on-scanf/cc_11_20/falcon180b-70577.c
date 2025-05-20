//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50
#define MAX_QUANTITY 100
#define MAX_PRICE 100

struct product {
    char name[MAX_NAME];
    int quantity;
    float price;
};

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Maximum number of products reached.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[num_products].name);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    printf("Enter product price: ");
                    scanf("%f", &products[num_products].price);
                    num_products++;
                }
                break;
            case '2':
                printf("Product Name\tQuantity\tPrice\n");
                for(int i=0; i<num_products; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;
            case '3':
                printf("Enter product name to update: ");
                scanf("%s", products[0].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[0].quantity);
                printf("Enter new product price: ");
                scanf("%f", &products[0].price);
                break;
            case '4':
                printf("Enter product name to delete: ");
                scanf("%s", products[0].name);
                for(int i=0; i<num_products; i++) {
                    if(strcmp(products[i].name, products[0].name) == 0) {
                        for(int j=i; j<num_products-1; j++) {
                            products[j] = products[j+1];
                        }
                        num_products--;
                        break;
                    }
                }
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}