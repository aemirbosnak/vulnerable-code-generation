//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if(num_products >= MAX_PRODUCTS) {
        printf("Warehouse is full!\n");
        return;
    }

    char name[MAX_NAME_LEN];
    int quantity;
    float price;

    printf("Enter name of product: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    products[num_products].price = price;

    num_products++;
}

void remove_product() {
    if(num_products == 0) {
        printf("Warehouse is empty!\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter name of product to remove: ");
    scanf("%s", name);

    int i, j;
    for(i = 0; i < num_products; i++) {
        if(strcmp(products[i].name, name) == 0) {
            for(j = i; j < num_products - 1; j++) {
                strcpy(products[j].name, products[j+1].name);
                products[j].quantity = products[j+1].quantity;
                products[j].price = products[j+1].price;
            }
            num_products--;
            printf("Product removed.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void list_products() {
    if(num_products == 0) {
        printf("Warehouse is empty!\n");
        return;
    }

    printf("Products in warehouse:\n");
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    int i;
    for(i = 0; i < num_products; i++) {
        printf("%-30s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    printf("Warehouse Management System\n\n");

    int choice = 0;

    while(choice != 4) {
        printf("\n1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                list_products();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}