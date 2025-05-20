//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_CODE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char code[MAX_CODE_LEN];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Update product\n");
        printf("3. Delete product\n");
        printf("4. View products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Sorry, maximum number of products reached.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[num_products].name);
                    printf("Enter product code: ");
                    scanf("%s", products[num_products].code);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    printf("Enter product price: ");
                    scanf("%lf", &products[num_products].price);
                    num_products++;
                }
                break;
            case '2':
                printf("Enter product code to update: ");
                scanf("%s", products[num_products-1].code);
                printf("Enter new product name: ");
                scanf("%s", products[num_products-1].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[num_products-1].quantity);
                printf("Enter new product price: ");
                scanf("%lf", &products[num_products-1].price);
                break;
            case '3':
                printf("Enter product code to delete: ");
                scanf("%s", products[num_products-1].code);
                num_products--;
                break;
            case '4':
                printf("Product List:\n");
                for(int i=0; i<num_products; i++) {
                    printf("%s | %s | %d | %.2lf\n", products[i].name, products[i].code, products[i].quantity, products[i].price);
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}