//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 9999
#define MAX_PRICE 9999.99

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

void add_product() {
    num_products++;
    printf("Enter product name: ");
    scanf("%s", products[num_products-1].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products-1].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products-1].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products-1].price);
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s\n%s\nPrice: $%.2f\nQuantity: %d\n\n", i+1, products[i].name, products[i].description, products[i].price, products[i].quantity);
    }
}

void search_product() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_name, products[i].name) == 0) {
            printf("Product found:\n");
            printf("%s\n", products[i].description);
            printf("Price: $%.2f\nQuantity: %d\n\n", products[i].price, products[i].quantity);
        }
    }
}

int main() {
    printf("Welcome to the Sherlock Holmes' Product Inventory System!\n\n");
    while (1) {
        printf("1. Add product\n2. Display products\n3. Search product\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("Goodbye, Mr. Holmes!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}