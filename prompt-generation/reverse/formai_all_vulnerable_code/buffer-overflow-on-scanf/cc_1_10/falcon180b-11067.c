//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
    char category[20];
} Product;

typedef struct {
    char name[20];
    int num_products;
} Category;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];
int num_products = 0, num_categories = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter product category: ");
    scanf("%s", products[num_products].category);
    num_products++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void display_products_by_category(char* category_name) {
    int i, j;
    for(i=0; i<num_products; i++) {
        if(strcmp(products[i].category, category_name) == 0) {
            printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    int choice, category_index;

    printf("Welcome to Sherlock's Warehouse Management System!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add product\n");
        printf("2. Add category\n");
        printf("3. Display products by category\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                add_category();
                break;
            case 3:
                printf("Enter category name: ");
                scanf("%s", categories[category_index].name);
                display_products_by_category(categories[category_index].name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}