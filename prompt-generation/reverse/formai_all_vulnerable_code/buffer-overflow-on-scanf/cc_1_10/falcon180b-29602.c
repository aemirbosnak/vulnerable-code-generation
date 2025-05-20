//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void print_menu() {
    printf("Product Inventory System\n");
    printf("1. Add product\n");
    printf("2. View products\n");
    printf("3. Update product\n");
    printf("4. Delete product\n");
    printf("5. Exit\n");
}

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
    printf("Product added successfully.\n");
}

void view_products() {
    printf("Product ID\tProduct Name\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2f\n", i + 1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

void update_product() {
    printf("Enter product ID: ");
    int id;
    scanf("%d", &id);
    if (id >= 1 && id <= num_products) {
        printf("Enter new product name: ");
        scanf("%s", products[id - 1].name);
        printf("Enter new product description: ");
        scanf("%s", products[id - 1].description);
        printf("Enter new product quantity: ");
        scanf("%d", &products[id - 1].quantity);
        printf("Enter new product price: ");
        scanf("%f", &products[id - 1].price);
        printf("Product updated successfully.\n");
    } else {
        printf("Invalid product ID.\n");
    }
}

void delete_product() {
    printf("Enter product ID: ");
    int id;
    scanf("%d", &id);
    if (id >= 1 && id <= num_products) {
        num_products--;
        printf("Product deleted successfully.\n");
    } else {
        printf("Invalid product ID.\n");
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}