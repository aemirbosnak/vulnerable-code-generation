//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[100];
    int id;
    int quantity;
    int price;
    int category;
} Product;

typedef struct {
    char name[50];
    int id;
} Category;

Category categories[MAX_CATEGORIES];
Product products[MAX_PRODUCTS];

int num_categories = 0;
int num_products = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].id = num_categories + 1;
    num_categories++;
}

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter category ID: ");
    scanf("%d", &products[num_products].category);
    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter price: ");
    scanf("%d", &products[num_products].price);
    num_products++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
}

void display_products() {
    printf("\nProducts:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units - $%d - Category: %d\n", products[i].id, products[i].name, products[i].quantity, products[i].price, products[i].category);
    }
}

int main() {
    printf("Warehouse Management System\n");
    printf("-------------------------\n");

    add_category();
    add_category();
    add_category();
    add_category();
    add_category();

    add_product();
    add_product();
    add_product();

    display_categories();
    display_products();

    return 0;
}