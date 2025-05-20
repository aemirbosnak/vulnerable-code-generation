//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int id;
    float price;
    char category[20];
} Product;

typedef struct {
    char name[20];
    int id;
} Category;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];

int num_products = 0;
int num_categories = 0;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter product category: ");
    scanf("%s", products[num_products].category);

    num_products++;
}

void addCategory() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter category ID: ");
    scanf("%d", &categories[num_categories].id);

    num_categories++;
}

void viewProducts() {
    printf("Product ID | Product Name | Category | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | %.2f\n", products[i].id, products[i].name, products[i].category, products[i].price);
    }
}

void viewCategories() {
    printf("Category ID | Category Name\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d | %s\n", categories[i].id, categories[i].name);
    }
}

int main() {
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Add category\n");
        printf("3. View products\n");
        printf("4. View categories\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                addCategory();
                break;
            case 3:
                viewProducts();
                break;
            case 4:
                viewCategories();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}