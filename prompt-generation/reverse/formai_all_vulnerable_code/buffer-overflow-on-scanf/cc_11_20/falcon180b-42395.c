//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    while (1) {
        printf("Product Inventory System\n");
        printf("-------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_products >= MAX_PRODUCTS) {
                    printf("Maximum number of products reached.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[num_products].name);
                    printf("Enter product description: ");
                    scanf("%s", products[num_products].description);
                    printf("Enter product price: ");
                    scanf("%f", &products[num_products].price);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    num_products++;
                }
                break;
            case '2':
                if (num_products == 0) {
                    printf("No products to remove.\n");
                } else {
                    int product_id;
                    printf("Enter product ID to remove: ");
                    scanf("%d", &product_id);
                    for (int i = 0; i < num_products; i++) {
                        if (i == product_id) {
                            memmove(&products[i], &products[i+1], sizeof(Product) * (num_products - i - 1));
                            num_products--;
                            break;
                        }
                    }
                }
                break;
            case '3':
                printf("Product ID\tProduct Name\tDescription\tPrice\tQuantity\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%d\t%s\t%s\t%.2f\t%d\n", i+1, products[i].name, products[i].description, products[i].price, products[i].quantity);
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}