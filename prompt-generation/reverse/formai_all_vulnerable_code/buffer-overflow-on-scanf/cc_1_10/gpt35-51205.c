//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

int total_products = 0;

struct Product {
    int id;
    char name[30];
    float price;
    int stock_quantity;
} products[MAX_PRODUCTS];

void add_product() {
    struct Product product;
    product.id = total_products + 1;
    printf("Enter product name: ");
    scanf("%s", &product.name);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product stock quantity: ");
    scanf("%d", &product.stock_quantity);
    products[total_products] = product;
    total_products++;
    printf("Product added successfully!\n");
}

void display_products() {
    printf("ID\tName\t\tPrice\tStock\n");
    for (int i = 0; i < total_products; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock_quantity);
    }
}

void search_product() {
    int id;
    printf("Enter product id to search: ");
    scanf("%d", &id);
    for (int i = 0; i < total_products; i++) {
        if (products[i].id == id) {
            printf("ID\tName\t\tPrice\tStock\n");
            printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock_quantity);
            return;
        }
    }
    printf("Product not found with id %d\n", id);
}

void update_product() {
    int id;
    printf("Enter product id to update: ");
    scanf("%d", &id);
    for (int i = 0; i < total_products; i++) {
        if (products[i].id == id) {
            printf("Enter product name: ");
            scanf("%s", &products[i].name);
            printf("Enter product price: ");
            scanf("%f", &products[i].price);
            printf("Enter product stock quantity: ");
            scanf("%d", &products[i].stock_quantity);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found with id %d\n", id);
}

void delete_product() {
    int id;
    printf("Enter product id to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < total_products; i++) {
        if (products[i].id == id) {
            for (int j = i; j < total_products - 1; j++) {
                products[j] = products[j+1];
            }
            total_products--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found with id %d\n", id);
}

int main() {
    int choice;
    do {
        printf("\n\n---- MEDICAL STORE MANAGEMENT SYSTEM ----\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Update product\n");
        printf("5. Delete product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                update_product();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
    return 0;
}