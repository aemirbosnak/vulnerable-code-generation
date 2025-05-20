//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    char name[MAX_NAME_LENGTH];
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Product already exists.\n");
            return;
        }
    }

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    num_products++;

    printf("Product added successfully.\n");
}

void remove_product() {
    char name[MAX_NAME_LENGTH];

    printf("Enter product name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                strcpy(products[j].name, products[j + 1].name);
                products[j].quantity = products[j + 1].quantity;
            }
            num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            remove_product();
            break;
        case 3:
            display_products();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}