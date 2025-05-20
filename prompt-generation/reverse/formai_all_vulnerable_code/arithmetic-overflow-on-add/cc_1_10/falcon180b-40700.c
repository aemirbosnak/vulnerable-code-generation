//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int category;
    int quantity;
    float price;
} Product;

typedef struct {
    char name[50];
    int num_products;
} Category;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];
int num_categories;
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", &products[num_products].name);
    printf("Enter product category: ");
    scanf("%d", &products[num_products].category);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", &categories[num_categories].name);
    num_categories++;
}

void display_products() {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void search_product() {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", &name);
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nProduct found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Category: %d\n", products[i].category);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nProduct not found.\n");
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    printf("Please enter the number of categories: ");
    scanf("%d", &num_categories);
    for (int i = 0; i < num_categories; i++) {
        add_category();
    }
    printf("Please enter the number of products: ");
    scanf("%d", &num_products);
    for (int i = 0; i < num_products; i++) {
        add_product();
    }
    int choice;
    do {
        printf("\nProduct Inventory System Menu:\n");
        printf("1. Display all products\n");
        printf("2. Display all categories\n");
        printf("3. Search for a product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_products();
                break;
            case 2:
                display_categories();
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