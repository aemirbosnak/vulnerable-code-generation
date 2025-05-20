//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product warehouse[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Warehouse is full! Unable to add more products.\n");
        return;
    }

    Product new_product;
    printf("Enter Product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]", new_product.name);
    printf("Enter Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter Price: ");
    scanf("%f", &new_product.price);

    warehouse[product_count] = new_product;
    product_count++;
    printf("Product added successfully!\n");
}

void display_products() {
    if (product_count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }

    printf("\nWarehouse Products:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void update_product() {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", warehouse[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &warehouse[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void delete_product() {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            for (int j = i; j < product_count - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            product_count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void save_to_file() {
    FILE *fp = fopen("warehouse.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&product_count, sizeof(int), 1, fp);
    fwrite(warehouse, sizeof(Product), product_count, fp);
    fclose(fp);
    printf("Product data saved to warehouse.dat.\n");
}

void load_from_file() {
    FILE *fp = fopen("warehouse.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading. Starting with an empty warehouse.\n");
        return;
    }

    fread(&product_count, sizeof(int), 1, fp);
    fread(warehouse, sizeof(Product), product_count, fp);
    fclose(fp);
    printf("Product data loaded from warehouse.dat.\n");
}

int main() {
    int choice;

    // Load existing products from file
    load_from_file();

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Products\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}