//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

int main() {
    int choice;
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    do {
        printf("\nInventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View all products\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);
            printf("Enter quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter price: ");
            scanf("%f", &products[num_products].price);
            num_products++;
            printf("Product added successfully.\n");
            break;

        case 2:
            printf("Enter product name to remove: ");
            scanf("%s", products[num_products-1].name);
            num_products--;
            printf("Product removed successfully.\n");
            break;

        case 3:
            printf("Product list:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
            }
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}