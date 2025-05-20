//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100
#define MAX_SUPPLIERS 100

typedef struct {
    int id;
    char name[50];
    char category[20];
    float price;
    int quantity;
    char supplier[20];
} Product;

typedef struct {
    int id;
    char name[20];
} Category;

typedef struct {
    int id;
    char name[50];
} Supplier;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];
Supplier suppliers[MAX_SUPPLIERS];

int num_products = 0;
int num_categories = 0;
int num_suppliers = 0;

void add_product(Product product) {
    num_products++;
    strcpy(products[num_products - 1].name, product.name);
    strcpy(products[num_products - 1].category, product.category);
    products[num_products - 1].price = product.price;
    products[num_products - 1].quantity = product.quantity;
    strcpy(products[num_products - 1].supplier, product.supplier);
}

void add_category(Category category) {
    num_categories++;
    strcpy(categories[num_categories - 1].name, category.name);
}

void add_supplier(Supplier supplier) {
    num_suppliers++;
    strcpy(suppliers[num_suppliers - 1].name, supplier.name);
}

int search_product(char* name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice, id;
    char name[50];

    printf("Welcome to the Warehouse Management System!\n");

    while (1) {
        printf("\n");
        printf("1. Add Product\n");
        printf("2. Add Category\n");
        printf("3. Add Supplier\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter category: ");
            scanf("%s", products[num_products].category);
            printf("Enter price: ");
            scanf("%f", &products[num_products].price);
            printf("Enter quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter supplier: ");
            scanf("%s", products[num_products].supplier);
            add_product(products[num_products]);
            num_products++;
            break;

        case 2:
            printf("Enter category name: ");
            scanf("%s", name);
            add_category(categories[num_categories]);
            num_categories++;
            break;

        case 3:
            printf("Enter supplier name: ");
            scanf("%s", name);
            add_supplier(suppliers[num_suppliers]);
            num_suppliers++;
            break;

        case 4:
            printf("Enter product name: ");
            scanf("%s", name);
            id = search_product(name);
            if (id!= -1) {
                printf("Product found with ID %d\n", id);
            } else {
                printf("Product not found.\n");
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}