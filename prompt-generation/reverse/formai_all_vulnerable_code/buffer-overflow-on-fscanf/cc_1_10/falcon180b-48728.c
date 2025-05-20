//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    FILE *fp;
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error opening products.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %f", products[num_products].name, &products[num_products].quantity, &products[num_products].price)!= EOF) {
        num_products++;
    }

    fclose(fp);

    printf("Product Inventory System\n");
    printf("------------------------\n\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. View products\n");
        printf("5. Exit\n");

        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);
            printf("Enter quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter price: ");
            scanf("%f", &products[num_products].price);
            num_products++;
            break;

        case '2':
            printf("Enter product name to remove: ");
            scanf("%s", products[num_products - 1].name);
            num_products--;
            break;

        case '3':
            printf("Enter product name to update: ");
            scanf("%s", products[num_products - 1].name);
            printf("Enter new quantity: ");
            scanf("%d", &products[num_products - 1].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[num_products - 1].price);
            break;

        case '4':
            printf("Product List:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
            }
            break;

        case '5':
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}