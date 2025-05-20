//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void print_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - Quantity: %d - Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void search_product() {
    printf("Enter product name to search: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Product found:\n");
            printf("%s - Quantity: %d - Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    printf("Product Inventory System\n");
    printf("------------------------\n");
    while (1) {
        printf("\n1. Add product\n2. Print products\n3. Search product\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                print_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}