//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (1) {
        printf("Enter option: \n");
        printf("1. Add product\n");
        printf("2. Display all products\n");
        printf("3. Search product by name\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_products >= MAX_PRODUCTS) {
                printf("Sorry, maximum number of products reached.\n");
            } else {
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product description: ");
                scanf("%s", products[num_products].description);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: ");
                scanf("%lf", &products[num_products].price);
                num_products++;
            }
            break;

        case 2:
            printf("Product Inventory:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%d. %s - %s (%d in stock) - $%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
            }
            break;

        case 3:
            printf("Enter product name to search: ");
            char search_name[MAX_NAME_LENGTH];
            scanf("%s", search_name);

            int found = 0;
            for (int i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, search_name) == 0) {
                    printf("Product found:\n");
                    printf("%s - %s (%d in stock) - $%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Product not found.\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}