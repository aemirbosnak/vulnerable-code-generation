//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice;
    int num_products = 0;
    struct product *products = NULL;
    while (1) {
        printf("Welcome to the Product Inventory System\n");
        printf("---------------------------------------\n");
        printf("1. Add a product\n");
        printf("2. View inventory\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                products = realloc(products, sizeof(struct product) * (num_products + 1));
                printf("Enter name of product: ");
                scanf("%s", products[num_products].name);
                printf("Enter quantity of product: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter price of product: ");
                scanf("%f", &products[num_products].price);
                num_products++;
                break;
            case 2:
                if (num_products == 0) {
                    printf("No products in inventory.\n");
                } else {
                    printf("%-20s %-20s %-20s\n", "Name", "Quantity", "Price");
                    for (int i = 0; i < num_products; i++) {
                        printf("%-20s %-20d %-20.2f\n", products[i].name, products[i].quantity, products[i].price);
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
                free(products);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    }
}