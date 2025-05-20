//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: future-proof
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
    int choice, num_products = 0;
    Product products[MAX_PRODUCTS];

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Update product\n");
        printf("3. Delete product\n");
        printf("4. View all products\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_products >= MAX_PRODUCTS) {
                printf("Error: Maximum number of products reached.\n");
            } else {
                printf("Enter product name (max %d characters): ", MAX_NAME_LENGTH);
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: ");
                scanf("%f", &products[num_products].price);
                num_products++;
                printf("Product added successfully.\n");
            }
            break;

        case 2:
            printf("Enter product name to update: ");
            scanf("%s", products[num_products].name);
            printf("Enter new product quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter new product price: ");
            scanf("%f", &products[num_products].price);
            printf("Product updated successfully.\n");
            break;

        case 3:
            printf("Enter product name to delete: ");
            scanf("%s", products[num_products].name);
            num_products--;
            printf("Product deleted successfully.\n");
            break;

        case 4:
            printf("Product List:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
            }
            break;

        case 5:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}