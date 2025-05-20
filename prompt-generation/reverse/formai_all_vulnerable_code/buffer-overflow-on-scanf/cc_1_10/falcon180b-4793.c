//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    char category[20];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

typedef struct {
    char name[20];
    int start_index;
    int end_index;
} Category;

Category categories[MAX_CATEGORIES];
int num_categories = 0;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product category: ");
    scanf("%s", products[num_products].category);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void addCategory() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);

    printf("Enter start index: ");
    scanf("%d", &categories[num_categories].start_index);

    printf("Enter end index: ");
    scanf("%d", &categories[num_categories].end_index);

    num_categories++;
}

void displayProducts() {
    printf("Product Name\tCategory\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t%d\t%f\n", products[i].name, products[i].category, products[i].quantity, products[i].price);
    }
}

void displayCategories() {
    printf("Category Name\tStart Index\tEnd Index\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\t%d\t%d\n", categories[i].name, categories[i].start_index, categories[i].end_index);
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n2. Add Category\n3. Display Products\n4. Display Categories\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                addCategory();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                displayCategories();
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