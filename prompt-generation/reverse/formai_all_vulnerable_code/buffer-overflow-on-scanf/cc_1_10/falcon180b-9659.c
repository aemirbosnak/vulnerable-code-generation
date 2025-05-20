//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void displayProducts() {
    printf("\nProduct Inventory:\n");
    printf("--------------------\n");
    printf("ID\tName\tDescription\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%.2f\n", i+1, products[i].name, products[i].description, products[i].price);
    }
    printf("--------------------\n");
}

void searchProduct() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("\nProduct found:\n");
            printf("ID: %d\n", i+1);
            printf("Name: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void main() {
    printf("Welcome to the Product Inventory System!\n");
    printf("--------------------\n");
    num_products = 0;
    while (1) {
        printf("\n1. Add product\n2. Display products\n3. Search product\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}