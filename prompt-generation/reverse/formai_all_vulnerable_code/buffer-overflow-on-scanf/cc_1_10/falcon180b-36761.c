//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

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

void display_products() {
    for (int i = 0; i < num_products; i++) {
        printf("\nProduct %d:\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%0.2f\n\n", products[i].price);
    }
}

void search_product() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_name, products[i].name) == 0) {
            printf("\nProduct %d:\n", i+1);
            printf("Name: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%0.2f\n\n", products[i].price);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Product not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
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
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}