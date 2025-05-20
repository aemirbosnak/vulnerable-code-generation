//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: careful
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

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];

int num_products = 0;
int num_categories = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter product category: ");
    scanf("%d", &products[num_products].category);
    num_products++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void display_products() {
    printf("Product ID | Product Name | Quantity | Price | Category\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %d | %.2f | %d\n", products[i].id, products[i].name, products[i].quantity, products[i].price, products[i].category);
    }
}

void display_categories() {
    printf("Category ID | Category Name\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d | %s\n", categories[i].id, categories[i].name);
    }
}

int main() {
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n2. Add category\n3. Display products\n4. Display categories\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                add_category();
                break;
            case 3:
                display_products();
                break;
            case 4:
                display_categories();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}