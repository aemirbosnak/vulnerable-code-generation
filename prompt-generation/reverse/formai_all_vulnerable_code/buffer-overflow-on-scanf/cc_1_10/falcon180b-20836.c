//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    int num_products;
    Product products[MAX_PRODUCTS];
    char choice;
    int index;
    FILE *fp;

    printf("Enter the number of products: ");
    scanf("%d", &num_products);

    printf("Enter the product details:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Enter the name of the product (%d): ", i+1);
        scanf("%s", products[i].name);
        printf("Enter the description of the product (%d): ", i+1);
        scanf("%s", products[i].description);
        printf("Enter the quantity of the product (%d): ", i+1);
        scanf("%d", &products[i].quantity);
        printf("Enter the price of the product (%d): ", i+1);
        scanf("%f", &products[i].price);
    }

    printf("Choose an option:\n");
    printf("1. Display all products\n");
    printf("2. Search for a product\n");
    printf("3. Exit\n");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            printf("Product Name\tDescription\tQuantity\tPrice\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s\t%s\t%d\t%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
            }
            break;
        case '2':
            printf("Enter the name of the product to search: ");
            scanf("%s", products[0].name);
            index = 0;
            while (index < num_products) {
                if (strcmp(products[index].name, products[0].name) == 0) {
                    printf("Product Name: %s\nProduct Description: %s\nQuantity: %d\nPrice: %.2f\n", products[index].name, products[index].description, products[index].quantity, products[index].price);
                    break;
                }
                index++;
            }
            if (index == num_products) {
                printf("Product not found.\n");
            }
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}