//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product *products, int *count) {
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    printf("Product added successfully!\n");
    (*count)++;
}

void viewProducts(Product *products, int count) {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product *products, int count) {
    char searchName[50];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
            printf("%-20s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateProduct(Product *products, int count) {
    char updateName[50];
    printf("Enter product name to update: ");
    scanf("%s", updateName);
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, updateName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    int choice, count = 0;
    Product products[100];
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Search product\n");
        printf("4. Update product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                viewProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                updateProduct(products, count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}