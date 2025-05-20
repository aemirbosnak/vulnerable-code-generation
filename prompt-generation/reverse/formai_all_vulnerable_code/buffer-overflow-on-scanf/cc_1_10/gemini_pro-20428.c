//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_WAREHOUSES 10

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

typedef struct {
    int id;
    char name[50];
    int capacity;
    product products[MAX_PRODUCTS];
} warehouse;

warehouse warehouses[MAX_WAREHOUSES];
int num_warehouses = 0;

void add_warehouse() {
    if (num_warehouses == MAX_WAREHOUSES) {
        printf("Error: Maximum number of warehouses reached.\n");
        return;
    }

    printf("Enter warehouse name: ");
    gets(warehouses[num_warehouses].name);

    printf("Enter warehouse capacity: ");
    scanf("%d", &warehouses[num_warehouses].capacity);

    num_warehouses++;
}

void add_product() {
    int warehouse_id;
    int product_id;

    printf("Enter warehouse ID: ");
    scanf("%d", &warehouse_id);

    if (warehouse_id < 0 || warehouse_id >= num_warehouses) {
        printf("Error: Invalid warehouse ID.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &product_id);

    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (warehouses[warehouse_id].products[i].id == product_id) {
            printf("Error: Product already exists in warehouse.\n");
            return;
        }
    }

    printf("Enter product name: ");
    gets(warehouses[warehouse_id].products[i].name);

    printf("Enter product quantity: ");
    scanf("%d", &warehouses[warehouse_id].products[i].quantity);

    printf("Enter product price: ");
    scanf("%f", &warehouses[warehouse_id].products[i].price);
}

void remove_product() {
    int warehouse_id;
    int product_id;

    printf("Enter warehouse ID: ");
    scanf("%d", &warehouse_id);

    if (warehouse_id < 0 || warehouse_id >= num_warehouses) {
        printf("Error: Invalid warehouse ID.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &product_id);

    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (warehouses[warehouse_id].products[i].id == product_id) {
            memmove(&warehouses[warehouse_id].products[i], &warehouses[warehouse_id].products[i + 1],
                    sizeof(product) * (MAX_PRODUCTS - i - 1));
            break;
        }
    }
}

void search_product() {
    int product_id;

    printf("Enter product ID: ");
    scanf("%d", &product_id);

    int i;
    int j;
    for (i = 0; i < num_warehouses; i++) {
        for (j = 0; j < MAX_PRODUCTS; j++) {
            if (warehouses[i].products[j].id == product_id) {
                printf("Product found in warehouse %s.\n", warehouses[i].name);
                return;
            }
        }
    }

    printf("Product not found.\n");
}

void list_warehouses() {
    int i;

    printf("List of warehouses:\n");
    for (i = 0; i < num_warehouses; i++) {
        printf("%d. %s\n", warehouses[i].id, warehouses[i].name);
    }
}

void list_products() {
    int warehouse_id;

    printf("Enter warehouse ID: ");
    scanf("%d", &warehouse_id);

    if (warehouse_id < 0 || warehouse_id >= num_warehouses) {
        printf("Error: Invalid warehouse ID.\n");
        return;
    }

    int i;

    printf("List of products in warehouse %s:\n", warehouses[warehouse_id].name);
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (warehouses[warehouse_id].products[i].id != 0) {
            printf("%d. %s\n", warehouses[warehouse_id].products[i].id, warehouses[warehouse_id].products[i].name);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add warehouse\n");
        printf("2. Add product\n");
        printf("3. Remove product\n");
        printf("4. Search product\n");
        printf("5. List warehouses\n");
        printf("6. List products\n");
        printf("7. Exit\n");

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
                remove_product();
                break;
            case 4:
                search_product();
                break;
            case 5:
                list_warehouses();
                break;
            case 6:
                list_products();
                break;
            case 7:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}