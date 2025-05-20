//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void remove_product() {
    printf("Enter product name to remove: ");
    char name[MAX_PRODUCT_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            num_products--;
            break;
        }
    }
}

void update_product() {
    printf("Enter product name to update: ");
    char name[MAX_PRODUCT_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &products[i].price);

            break;
        }
    }
}

void view_products() {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    srand(time(NULL));
    num_products = 0;

    while (1) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. View products\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            remove_product();
            break;
        case 3:
            update_product();
            break;
        case 4:
            view_products();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}