//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    char name[20];
    int categoryID;
} Category;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];

int numProducts = 0;
int numCategories = 0;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter price: ");
    scanf("%f", &products[numProducts].price);
    numProducts++;
}

void addCategory() {
    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    printf("Enter category ID: ");
    scanf("%d", &categories[numCategories].categoryID);
    numCategories++;
}

void displayProducts() {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void displayCategories() {
    printf("Category Name\tCategory ID\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s\t%d\n", categories[i].name, categories[i].categoryID);
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