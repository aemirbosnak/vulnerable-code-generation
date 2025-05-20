//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct Product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int stock;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    fgets(products[num_products].name, MAX_NAME_LENGTH, stdin);
    products[num_products].name[strcspn(products[num_products].name, "\n")] = 0;

    printf("Enter product description: ");
    fgets(products[num_products].description, MAX_DESCRIPTION_LENGTH, stdin);
    products[num_products].description[strcspn(products[num_products].description, "\n")] = 0;

    printf("Enter product stock: ");
    scanf("%d", &products[num_products].stock);
    getchar(); // consume newline

    num_products++;
    printf("Product added successfully.\n");
}

void list_products() {
    printf("Products:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s: %s (%d in stock)\n", i + 1, products[i].name, products[i].description, products[i].stock);
    }
}

void update_stock() {
    printf("Enter product number to update stock: ");

    int product_num;
    scanf("%d", &product_num);
    getchar(); // consume newline

    if (product_num < 1 || product_num > num_products) {
        printf("Error: Invalid product number.\n");
        return;
    }

    printf("Enter new stock value: ");
    scanf("%d", &products[product_num - 1].stock);
    getchar(); // consume newline

    printf("Stock updated successfully.\n");
}

int main() {
    while (1) {
        printf("Warehouse Management System\n");
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Update stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                list_products();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}