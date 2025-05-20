//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WAREHOUSE_CAPACITY 100
#define MAX_PRODUCT_NAME_LENGTH 50

typedef struct Product {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

typedef struct Warehouse {
    Product inventory[MAX_WAREHOUSE_CAPACITY];
    int current_capacity;
} Warehouse;

bool add_product(Warehouse *warehouse, Product product) {
    if (warehouse->current_capacity >= MAX_WAREHOUSE_CAPACITY) {
        printf("Warehouse is full\n");
        return false;
    }
    warehouse->inventory[warehouse->current_capacity++] = product;
    printf("%d %s added to warehouse\n", product.quantity, product.name);
    return true;
}

void list_products(Warehouse *warehouse) {
    if (warehouse->current_capacity == 0) {
        printf("Warehouse is empty\n");
        return;
    }
    printf("ID \t NAME \t QUANTITY\n");
    for (int i = 0; i < warehouse->current_capacity; i++) {
        printf("%d \t %s \t %d\n", i+1, warehouse->inventory[i].name, warehouse->inventory[i].quantity);
    }
}

bool remove_product(Warehouse *warehouse, int id) {
    if (id <= 0 || id > warehouse->current_capacity) {
        printf("Invalid product ID\n");
        return false;
    }
    Product product = warehouse->inventory[id-1];
    printf("%d %s removed from warehouse\n", product.quantity, product.name);
    for (int i = id-1; i < warehouse->current_capacity-1; i++) {
        warehouse->inventory[i] = warehouse->inventory[i+1];
    }
    warehouse->current_capacity--;
    return true;
}

int main() {
    Warehouse warehouse;
    warehouse.current_capacity = 0;
    int choice;
    do {
        printf("\n1. Add product\n2. Remove product\n3. List products\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                Product product;
                printf("Enter product name: ");
                scanf("%s", product.name);
                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);
                add_product(&warehouse, product);
                break;
            }
            case 2: {
                int id;
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                remove_product(&warehouse, id);
                break;
            }
            case 3: {
                list_products(&warehouse);
                break;
            }
            case 4: {
                printf("Exiting program\n");
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (choice != 4);

    return 0;
}