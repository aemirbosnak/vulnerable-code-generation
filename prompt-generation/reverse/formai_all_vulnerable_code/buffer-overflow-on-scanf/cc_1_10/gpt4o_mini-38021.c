//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSES 10
#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

typedef struct {
    char name[MAX_NAME_LEN];
    Product products[MAX_PRODUCTS];
    int product_count;
} Warehouse;

Warehouse warehouses[MAX_WAREHOUSES];
int warehouse_count = 0;

void add_warehouse() {
    if (warehouse_count >= MAX_WAREHOUSES) {
        printf("Maximum warehouse limit reached.\n");
        return;
    }
    printf("Enter warehouse name: ");
    scanf("%s", warehouses[warehouse_count].name);
    warehouses[warehouse_count].product_count = 0;
    warehouse_count++;
    printf("Warehouse '%s' added successfully.\n", warehouses[warehouse_count - 1].name);
}

void add_product() {
    char warehouse_name[MAX_NAME_LEN];
    printf("Enter warehouse name to add product to: ");
    scanf("%s", warehouse_name);

    for (int i = 0; i < warehouse_count; i++) {
        if (strcmp(warehouses[i].name, warehouse_name) == 0) {
            if (warehouses[i].product_count >= MAX_PRODUCTS) {
                printf("Maximum product limit in warehouse '%s' reached.\n", warehouse_name);
                return;
            }
            Product *new_product = &warehouses[i].products[warehouses[i].product_count];
            printf("Enter product name: ");
            scanf("%s", new_product->name);
            printf("Enter product quantity: ");
            scanf("%d", &new_product->quantity);
            warehouses[i].product_count++;
            printf("Product '%s' added successfully to warehouse '%s'.\n", new_product->name, warehouse_name);
            return;
        }
    }
    printf("Warehouse '%s' not found.\n", warehouse_name);
}

void list_warehouses() {
    if (warehouse_count == 0) {
        printf("No warehouses available.\n");
        return;
    }
    printf("\nWarehouses:\n");
    for (int i = 0; i < warehouse_count; i++) {
        printf("%d. %s\n", i + 1, warehouses[i].name);
    }
}

void list_products() {
    char warehouse_name[MAX_NAME_LEN];
    printf("Enter warehouse name to list products from: ");
    scanf("%s", warehouse_name);

    for (int i = 0; i < warehouse_count; i++) {
        if (strcmp(warehouses[i].name, warehouse_name) == 0) {
            if (warehouses[i].product_count == 0) {
                printf("No products available in warehouse '%s'.\n", warehouse_name);
                return;
            }
            printf("\nProducts in warehouse '%s':\n", warehouse_name);
            for (int j = 0; j < warehouses[i].product_count; j++) {
                printf("Product Name: %s, Quantity: %d\n", warehouses[i].products[j].name, warehouses[i].products[j].quantity);
            }
            return;
        }
    }
    printf("Warehouse '%s' not found.\n", warehouse_name);
}

void update_product_quantity() {
    char warehouse_name[MAX_NAME_LEN];
    char product_name[MAX_NAME_LEN];
    int new_quantity;

    printf("Enter warehouse name: ");
    scanf("%s", warehouse_name);
    printf("Enter product name to update: ");
    scanf("%s", product_name);
    printf("Enter new quantity: ");
    scanf("%d", &new_quantity);

    for (int i = 0; i < warehouse_count; i++) {
        if (strcmp(warehouses[i].name, warehouse_name) == 0) {
            for (int j = 0; j < warehouses[i].product_count; j++) {
                if (strcmp(warehouses[i].products[j].name, product_name) == 0) {
                    warehouses[i].products[j].quantity = new_quantity;
                    printf("Updated quantity of product '%s' in warehouse '%s' to %d.\n", product_name, warehouse_name, new_quantity);
                    return;
                }
            }
            printf("Product '%s' not found in warehouse '%s'.\n", product_name, warehouse_name);
            return;
        }
    }
    printf("Warehouse '%s' not found.\n", warehouse_name);
}

int main() {
    int choice;

    while (1) {
        printf("\nWarehouse Management System Menu:\n");
        printf("1. Add Warehouse\n");
        printf("2. Add Product\n");
        printf("3. List Warehouses\n");
        printf("4. List Products\n");
        printf("5. Update Product Quantity\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_warehouse();
                break;
            case 2:
                add_product();
                break;
            case 3:
                list_warehouses();
                break;
            case 4:
                list_products();
                break;
            case 5:
                update_product_quantity();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}