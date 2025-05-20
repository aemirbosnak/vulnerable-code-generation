//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* A Product Inventory System in Sherlock Holmes style */

struct Product {
    char name[50];
    int quantity;
    float price;
};

int menu() {
    int choice;
    printf("Welcome to Sherlock Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Search Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addProduct(struct Product products[], int *count) {
    printf("Enter Product Name: ");
    scanf("%s", products[*count].name);
    printf("Enter Product Quantity: ");
    scanf("%d", &products[*count].quantity);
    printf("Enter Product Price: ");
    scanf("%f", &products[*count].price);
    (*count)++;
    printf("Product added successfully!\n");
}

void viewProducts(struct Product products[], int count) {
    printf("***********************************\n");
    printf("Product Name\t Quantity\t Price\n");
    printf("***********************************\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t %d\t\t %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
    printf("***********************************\n");
}

int deleteProduct(struct Product products[], int *count, char name[]) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < (*count) - 1; j++) {
                products[j] = products[j+1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return 1;
        }
    }
    printf("Product not found!\n");
    return 0;
}

void searchProduct(struct Product products[], int count, char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product Name: %s\n", products[i].name);
            printf("Product Quantity: %d\n", products[i].quantity);
            printf("Product Price: %.2f\n", products[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    struct Product products[100];
    int count = 0;
    int choice;
    char name[50];
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                viewProducts(products, count);
                break;
            case 3:
                printf("Enter Product Name to Delete: ");
                scanf("%s", name);
                deleteProduct(products, &count, name);
                break;
            case 4:
                printf("Enter Product Name to Search: ");
                scanf("%s", name);
                searchProduct(products, count, name);
                break;
            case 5:
                printf("Goodbye, dear user!\n");
                exit(0);
            default:
                printf("Invalid input, please try again!\n");
                break;
        }
    }
    return 0;
}