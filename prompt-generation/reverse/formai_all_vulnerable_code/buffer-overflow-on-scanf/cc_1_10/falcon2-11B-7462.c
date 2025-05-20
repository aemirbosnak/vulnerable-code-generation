//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>

int main() {
    int num_products = 0;
    char products[10][20];
    int product_price[10];
    int product_quantity[10];

    printf("Welcome to the Product Inventory System!\n");
    printf("Please enter the number of products you want to add:\n");
    scanf("%d", &num_products);

    for (int i = 0; i < num_products; i++) {
        printf("Enter the name of product %d:\n", i + 1);
        scanf("%s", &products[i]);

        printf("Enter the price of product %d:\n", i + 1);
        scanf("%d", &product_price[i]);

        printf("Enter the quantity of product %d:\n", i + 1);
        scanf("%d", &product_quantity[i]);
    }

    printf("\nHere is the inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Product %d: %s - Price: %d - Quantity: %d\n", i + 1, products[i], product_price[i], product_quantity[i]);
    }

    printf("\nDo you want to search for a product? (y/n): ");
    char search_input;
    scanf("%c", &search_input);

    if (search_input == 'y') {
        printf("\nEnter the name of the product you want to search for: ");
        char product_name[20];
        scanf("%s", &product_name);

        for (int i = 0; i < num_products; i++) {
            if (strcmp(product_name, products[i]) == 0) {
                printf("Product found!\n");
                printf("Product %d: %s - Price: %d - Quantity: %d\n", i + 1, products[i], product_price[i], product_quantity[i]);
            }
        }
    }

    printf("\nDo you want to exit the program? (y/n): ");
    char exit_input;
    scanf("%c", &exit_input);

    if (exit_input == 'y') {
        printf("Goodbye!\n");
        return 0;
    }

    return 0;
}