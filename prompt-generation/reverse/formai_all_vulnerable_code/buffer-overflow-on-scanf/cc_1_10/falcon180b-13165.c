//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_LENGTH 50

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void display_products() {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void search_product() {
    char search_name[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Product found:\n");
            printf("Product Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    
    return 0;
}