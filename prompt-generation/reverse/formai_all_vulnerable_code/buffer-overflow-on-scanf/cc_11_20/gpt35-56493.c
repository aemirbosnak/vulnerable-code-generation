//FormAI DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[20];
    double price;
    int quantity;
} Product;

int main() {
    int numProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    Product *products = malloc(sizeof(Product) * numProducts);

    for (int i = 0; i < numProducts; i++) {
        printf("Enter product %d details:\n", i+1);
        printf("ID: ");
        scanf("%d", &products[i].id);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%lf", &products[i].price);
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);
    }

    printf("\nProduct database:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    int choice;
    printf("\nEnter 1 to search by product name, 2 to search by price range: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char searchName[20];
        printf("\nEnter the product name to search: ");
        scanf("%s", searchName);

        bool found = false;
        for (int i = 0; i < numProducts; i++) {
            if (strcmp(searchName, products[i].name) == 0) {
                printf("\nProduct found!\n");
                found = true;
                printf("ID\tName\tPrice\tQuantity\n");
                printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            }
        }
        if (!found) {
            printf("\nProduct not found!\n");
        }
    } else if (choice == 2) {
        double minPrice, maxPrice;
        printf("\nEnter the minimum price: ");
        scanf("%lf", &minPrice);
        printf("Enter the maximum price: ");
        scanf("%lf", &maxPrice);

        bool found = false;
        printf("\nProducts in price range %.2lf - %.2lf:\n", minPrice, maxPrice);
        printf("ID\tName\tPrice\tQuantity\n");
        for (int i = 0; i < numProducts; i++) {
            if (products[i].price >= minPrice && products[i].price <= maxPrice) {
                found = true;
                printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            }
        }
        if (!found) {
            printf("\nNo products found in the price range!\n");
        }
    } else {
        printf("\nInvalid choice!\n");
    }

    free(products);

    return 0;
}