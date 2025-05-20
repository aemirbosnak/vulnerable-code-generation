//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

void addProduct(Product *p, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Error: Maximum allowed products reached.\n");
        return;
    }

    printf("Enter product details:\n");
    printf("ID: ");
    scanf("%d", &p[*count].id);
    printf("Name: ");
    fflush(stdin);
    fgets(p[*count].name, 50, stdin);
    printf("Price: ");
    scanf("%f", &p[*count].price);
    printf("Quantity: ");
    scanf("%d", &p[*count].quantity);

    (*count)++;
}

void printProducts(Product *p, int count) {
    printf("-----------------------------\n");
    printf("| ID | Name      | Price | Qty |\n");
    printf("-----------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %2d | %-9s | $%.2f | %3d |\n", p[i].id, p[i].name, p[i].price, p[i].quantity);
    }

    printf("-----------------------------\n");
}

void searchProduct(Product *p, int count) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\nName: %sPrice: $%.2f\nQuantity: %d\n", p[i].id, p[i].name, p[i].price, p[i].quantity);
            return;
        }
    }

    printf("Product not found.\n");
}

void updateProduct(Product *p, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter new details for product:\n");
            printf("Name: ");
            fflush(stdin);
            fgets(p[i].name, 50, stdin);
            printf("Price: ");
            scanf("%f", &p[i].price);
            printf("Quantity: ");
            scanf("%d", &p[i].quantity);
            printf("Product updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void deleteProduct(Product *p, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (p[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                p[j] = p[j+1];
            }
            (*count)--;
            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    int choice, count = 0;
    Product products[MAX_PRODUCTS];

    while (1) {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add product.\n");
        printf("2. Search product.\n");
        printf("3. Update product.\n");
        printf("4. Delete product.\n");
        printf("5. Print all products.\n");
        printf("6. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                searchProduct(products, count);
                break;
            case 3:
                updateProduct(products, count);
                break;
            case 4:
                deleteProduct(products, &count);
                break;
            case 5:
                printProducts(products, count);
                break;
            case 6:
                printf("Thank you for using PRODUCT INVENTORY SYSTEM.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}