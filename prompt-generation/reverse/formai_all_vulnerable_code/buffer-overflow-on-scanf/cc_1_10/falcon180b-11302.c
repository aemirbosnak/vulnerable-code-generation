//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    num_products++;
}

void remove_product() {
    num_products--;
}

void display_products() {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }
}

int main() {
    int choice, i;

    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            printf("Product added successfully!\n");
            break;
        case 2:
            remove_product();
            printf("Product removed successfully!\n");
            break;
        case 3:
            display_products();
            break;
        case 4:
            printf("Thank you for using the Product Inventory System!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}