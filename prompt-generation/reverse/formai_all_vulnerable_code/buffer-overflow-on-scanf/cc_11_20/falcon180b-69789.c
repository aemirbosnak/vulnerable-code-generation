//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

int main() {
    int numProducts = 0;
    Product products[MAX_PRODUCTS];

    while (1) {
        printf("Welcome to the Happy Product Inventory System!\n");
        printf("Please choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. View all products\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numProducts >= MAX_PRODUCTS) {
                printf("Sorry, you have reached the maximum number of products.\n");
            } else {
                printf("Enter the name of the product (up to %d characters): ", MAX_NAME_LENGTH - 1);
                scanf("%s", products[numProducts].name);
                printf("Enter the quantity of the product: ");
                scanf("%d", &products[numProducts].quantity);
                numProducts++;
                printf("Product added successfully!\n");
            }
            break;
        case 2:
            if (numProducts == 0) {
                printf("Sorry, there are no products to remove.\n");
            } else {
                printf("Enter the name of the product you want to remove: ");
                scanf("%s", products[0].name);
                for (int i = 1; i < numProducts; i++) {
                    strcpy(products[i - 1].name, products[i].name);
                    products[i - 1].quantity = products[i].quantity;
                }
                numProducts--;
                printf("Product removed successfully!\n");
            }
            break;
        case 3:
            if (numProducts == 0) {
                printf("Sorry, there are no products to view.\n");
            } else {
                printf("Product Name\tQuantity\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%s\t\t%d\n", products[i].name, products[i].quantity);
                }
            }
            break;
        case 4:
            printf("Thank you for using the Happy Product Inventory System!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}