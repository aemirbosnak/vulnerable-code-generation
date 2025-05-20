//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_products >= MAX_PRODUCTS) {
                printf("Maximum number of products reached.\n");
            } else {
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: ");
                scanf("%lf", &products[num_products].price);
                num_products++;
            }
            break;
        case '2':
            printf("Product Name\tQuantity\tPrice\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s\t%d\t%.2lf\n", products[i].name, products[i].quantity, products[i].price);
            }
            break;
        case '3':
            printf("Enter product index: ");
            int index;
            scanf("%d", &index);
            if (index >= 0 && index < num_products) {
                printf("Enter new product name: ");
                scanf("%s", products[index].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[index].quantity);
                printf("Enter new product price: ");
                scanf("%lf", &products[index].price);
            } else {
                printf("Invalid product index.\n");
            }
            break;
        case '4':
            printf("Enter product index: ");
            int index2;
            scanf("%d", &index2);
            if (index2 >= 0 && index2 < num_products) {
                num_products--;
                for (int i = index2; i < num_products; i++) {
                    strcpy(products[i].name, products[i+1].name);
                    products[i].quantity = products[i+1].quantity;
                    products[i].price = products[i+1].price;
                }
            } else {
                printf("Invalid product index.\n");
            }
            break;
        case '5':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}