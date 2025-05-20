//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int code;
    float price;
    int quantity;
    int reorderLevel;
} Product;

typedef struct {
    char name[20];
    int code;
} Category;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];

int numProducts = 0;
int numCategories = 0;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter product code: ");
    scanf("%d", &products[numProducts].code);
    printf("Enter product price: ");
    scanf("%f", &products[numProducts].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter product reorder level: ");
    scanf("%d", &products[numProducts].reorderLevel);
    numProducts++;
}

void addCategory() {
    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    printf("Enter category code: ");
    scanf("%d", &categories[numCategories].code);
    numCategories++;
}

void displayProducts() {
    printf("\nProduct List:\n");
    printf("---------------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - %d - %.2f - %d\n", i+1, products[i].name, products[i].code, products[i].price, products[i].quantity);
    }
}

void displayCategories() {
    printf("\nCategory List:\n");
    printf("---------------------\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%d. %s - %d\n", i+1, categories[i].name, categories[i].code);
    }
}

int main() {
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("------------------------------\n");
        printf("1. Add Product\n");
        printf("2. Add Category\n");
        printf("3. Display Products\n");
        printf("4. Display Categories\n");
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