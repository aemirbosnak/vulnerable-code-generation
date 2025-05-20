//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

// Product structure
typedef struct {
    int id;
    char name[50];
    int category;
    int quantity;
    float price;
} Product;

// Category structure
typedef struct {
    int id;
    char name[20];
} Category;

// Function to add a product
void addProduct(Product products[], int *size) {
    printf("Enter product ID: ");
    scanf("%d", &products[*size].id);
    printf("Enter product name: ");
    scanf("%s", products[*size].name);
    printf("Enter product category: ");
    scanf("%d", &products[*size].category);
    printf("Enter product quantity: ");
    scanf("%d", &products[*size].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*size].price);
    (*size)++;
}

// Function to display products
void displayProducts(Product products[], int size) {
    printf("\nProduct List:\n");
    printf("ID\tName\tCategory\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%d\t%.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].price);
    }
}

// Function to add a category
void addCategory(Category categories[], int *size) {
    printf("Enter category ID: ");
    scanf("%d", &categories[*size].id);
    printf("Enter category name: ");
    scanf("%s", categories[*size].name);
    (*size)++;
}

// Function to display categories
void displayCategories(Category categories[], int size) {
    printf("\nCategory List:\n");
    printf("ID\tName\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\n", categories[i].id, categories[i].name);
    }
}

// Main function
int main() {
    Product products[MAX_PRODUCTS];
    int productSize = 0;
    Category categories[MAX_CATEGORIES];
    int categorySize = 0;

    // Add categories
    addCategory(categories, &categorySize);
    addCategory(categories, &categorySize);

    // Add products
    addProduct(products, &productSize);
    addProduct(products, &productSize);
    addProduct(products, &productSize);

    // Display categories
    displayCategories(categories, categorySize);

    // Display products
    displayProducts(products, productSize);

    return 0;
}