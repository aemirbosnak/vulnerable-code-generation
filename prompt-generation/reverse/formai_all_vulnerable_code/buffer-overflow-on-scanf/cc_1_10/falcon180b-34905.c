//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;

    printf("Enter product name: ");
    scanf("%s", name);
    strcpy(products[num_products].name, name);

    printf("Enter product description: ");
    scanf("%s", description);
    strcpy(products[num_products].description, description);

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    products[num_products].quantity = quantity;

    printf("Enter price: ");
    scanf("%lf", &price);
    products[num_products].price = price;

    num_products++;
}

void display_products() {
    for (int i = 0; i < num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            display_products();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}