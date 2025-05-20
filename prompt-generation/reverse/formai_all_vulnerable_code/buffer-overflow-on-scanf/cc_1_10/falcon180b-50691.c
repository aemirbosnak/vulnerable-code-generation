//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];

int num_products;

void display_products() {
    printf("Product Name\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
}

void remove_product() {
    printf("Enter product name to remove: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                strcpy(products[j].name, products[j + 1].name);
                strcpy(products[j].description, products[j + 1].description);
                products[j].quantity = products[j + 1].quantity;
                products[j].price = products[j + 1].price;
            }
            num_products--;
            break;
        }
    }
}

void search_product() {
    printf("Enter product name to search: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Product Name: %s\nDescription: %s\nQuantity: %d\nPrice: $.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    printf("Product Inventory System\n");
    printf("------------------------\n");
    printf("1. Display products\n");
    printf("2. Add product\n");
    printf("3. Remove product\n");
    printf("4. Search product\n");
    printf("5. Exit\n");
    int choice;
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_products();
                break;
            case 2:
                add_product();
                break;
            case 3:
                remove_product();
                break;
            case 4:
                search_product();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}