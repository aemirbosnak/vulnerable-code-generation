//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Cannot add more products. Maximum limit reached.\n");
        return;
    }
    Product new_product;
    printf("Enter Product ID: ");
    scanf("%d", &new_product.id);
    getchar(); // Consume newline character left from previous input
    printf("Enter Product Name: ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;  // Remove newline
    printf("Enter Manufacturer: ");
    fgets(new_product.manufacturer, sizeof(new_product.manufacturer), stdin);
    new_product.manufacturer[strcspn(new_product.manufacturer, "\n")] = 0;  // Remove newline
    printf("Enter Price: ");
    scanf("%f", &new_product.price);
    printf("Enter Quantity: ");
    scanf("%d", &new_product.quantity);

    products[product_count] = new_product;
    product_count++;
    printf("Product added successfully!\n");
}

void view_products() {
    if (product_count == 0) {
        printf("No products available.\n");
        return;
    }
    printf("\nID\tName\t\tManufacturer\tPrice\tQuantity\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", 
                products[i].id, 
                products[i].name, 
                products[i].manufacturer, 
                products[i].price, 
                products[i].quantity);
    }
    printf("-----------------------------------------------------------\n");
}

void search_product() {
    int search_id;
    printf("Enter Product ID to search: ");
    scanf("%d", &search_id);
    int found = 0;

    for (int i = 0; i < product_count; i++) {
        if (products[i].id == search_id) {
            printf("Product Found!\n");
            printf("ID: %d\nName: %s\nManufacturer: %s\nPrice: %.2f\nQuantity: %d\n", 
                    products[i].id,
                    products[i].name,
                    products[i].manufacturer,
                    products[i].price,
                    products[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", search_id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n---- Medical Store Management System ----\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}