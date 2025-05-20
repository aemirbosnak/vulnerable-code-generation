//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int category;
} Product;

typedef struct {
    int id;
    char name[50];
} Category;

int num_products = 0;
Product products[MAX_PRODUCTS];

int num_categories = 0;
Category categories[MAX_CATEGORIES];

void add_product() {
    num_products++;
    printf("Enter product ID: ");
    scanf("%d", &products[num_products - 1].id);
    printf("Enter product name: ");
    scanf("%s", products[num_products - 1].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products - 1].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products - 1].price);
    printf("Enter product category ID: ");
    scanf("%d", &products[num_products - 1].category);
}

void add_category() {
    num_categories++;
    printf("Enter category ID: ");
    scanf("%d", &categories[num_categories - 1].id);
    printf("Enter category name: ");
    scanf("%s", categories[num_categories - 1].name);
}

void display_products() {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("ID: %d\tName: %s\tQuantity: %d\tPrice: %.2f\tCategory: %d\n", products[i].id, products[i].name, products[i].quantity, products[i].price, products[i].category);
    }
}

void display_categories() {
    printf("\nCategory List:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("ID: %d\tName: %s\n", categories[i].id, categories[i].name);
    }
}

int main() {
    system("clear");
    printf("\nWarehouse Management System\n");
    printf("===========================\n");

    add_category();
    add_category();
    add_product();
    add_product();

    display_categories();
    display_products();

    return 0;
}