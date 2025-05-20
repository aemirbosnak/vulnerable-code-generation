//FormAI DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
} Category;

void add_product(Product **products, int *n_products, Category categories[], int n_categories) {
    Product new_product;
    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);
    printf("Enter the price of the product: ");
    scanf("%f", &new_product.price);
    printf("Choose a category for the product: \n");
    for (int i = 0; i < n_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
    int category_id;
    scanf("%d", &category_id);
    new_product.id = (*n_products) + 1;
    products[*n_products] = malloc(sizeof(Product));
    *(products[*n_products]) = new_product;
    (*n_products)++;
}

void print_products(Product **products, int n_products) {
    for (int i = 0; i < n_products; i++) {
        printf("%d. %s ($%.2f)\n", products[i]->id, products[i]->name, products[i]->price);
    }
}

int main() {
    Category categories[] = {{1, "Food"}, {2, "Electronics"}, {3, "Clothing"}};
    int n_categories = sizeof(categories) / sizeof(Category);
    Product *products[100];
    int n_products = 0;
    char option;
    do {
        printf("Welcome to the database simulation!\n");
        printf("Choose an option:\n");
        printf("1. Add a new product\n");
        printf("2. View all products\n");
        printf("3. Exit\n");
        printf("> ");
        scanf(" %c", &option);
        switch (option) {
            case '1':
                add_product(products, &n_products, categories, n_categories);
                break;
            case '2':
                print_products(products, n_products);
                break;
            case '3':
                printf("Bye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != '3');
    for (int i = 0; i < n_products; i++) {
        free(products[i]);
    }
    return 0;
}