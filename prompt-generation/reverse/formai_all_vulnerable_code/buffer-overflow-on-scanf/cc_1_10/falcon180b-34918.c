//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_CODE_LEN 10
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char code[MAX_CODE_LEN];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product code: ");
    scanf("%s", products[num_products].code);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    num_products++;
}

void update_product_quantity() {
    printf("Enter product code to update quantity: ");
    char code[MAX_CODE_LEN];
    scanf("%s", code);

    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(code, products[i].code) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product code not found.\n");
        return;
    }

    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);
}

void display_products() {
    printf("Product Name\tProduct Code\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t%d\n", products[i].name, products[i].code, products[i].quantity);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Update product quantity\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                update_product_quantity();
                break;
            case 3:
                display_products();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}