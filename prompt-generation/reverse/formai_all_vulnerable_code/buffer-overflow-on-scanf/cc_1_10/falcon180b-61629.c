//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
};

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the product inventory system!\n");

    while (num_products < MAX_PRODUCTS) {
        printf("Do you want to add a product? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);

            printf("Enter product description: ");
            scanf("%s", products[num_products].description);

            printf("Enter product quantity: ");
            scanf("%d", &products[num_products].quantity);

            printf("Enter product price: ");
            scanf("%f", &products[num_products].price);

            num_products++;
        } else if (choice == 'n' || choice == 'N') {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Product inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %s - %d units - $%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    return 0;
}