//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int n = 10; // Number of products
    int i;
    struct product {
        char name[50];
        double price;
        int quantity;
    };
    struct product products[n];

    printf("Welcome to the Product Inventory System!\n");
    for (i=0; i<n; i++) {
        printf("Enter name of product %d: ", i+1);
        fgets(products[i].name, sizeof(products[i].name), stdin);

        printf("Enter price of product %d: ", i+1);
        scanf("%lf", &products[i].price);

        printf("Enter quantity of product %d: ", i+1);
        scanf("%d", &products[i].quantity);

        if (strlen(products[i].name) == 0) {
            printf("Error: Product name cannot be empty!\n");
            continue;
        }

        if (products[i].price < 0) {
            printf("Error: Price cannot be negative!\n");
            continue;
        }

        if (products[i].quantity < 0) {
            printf("Error: Quantity cannot be negative!\n");
            continue;
        }

        printf("Product %d added to inventory with name %s, price %.2f, and quantity %d.\n", i+1, products[i].name, products[i].price, products[i].quantity);
        products[i].quantity++;
    }

    double totalValue = 0;
    for (i=0; i<n; i++) {
        totalValue += products[i].price * products[i].quantity;
    }

    printf("Total value of inventory is $%.2f.\n", totalValue);

    return 0;
}