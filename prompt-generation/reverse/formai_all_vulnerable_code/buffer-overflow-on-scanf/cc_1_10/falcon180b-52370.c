//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_WAREHOUSE_CAPACITY 1000
#define MAX_NUM_PRODUCTS 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_NUM_PRODUCTS];
    int num_products;
} Warehouse;

void initWarehouse(Warehouse *warehouse) {
    warehouse->num_products = 0;
}

void addProduct(Warehouse *warehouse, Product product) {
    if (warehouse->num_products >= MAX_NUM_PRODUCTS) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Product product;
                printf("Enter product name: ");
                scanf("%s", &product.name);

                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);

                printf("Enter product price: ");
                scanf("%f", &product.price);

                addProduct(&warehouse, product);
                break;
            }

            case 2: {
                printf("\nProduct List:\n");
                for (int i = 0; i < warehouse.num_products; i++) {
                    printf("%s - Quantity: %d - Price: %.2f\n",
                            warehouse.products[i].name,
                            warehouse.products[i].quantity,
                            warehouse.products[i].price);
                }
                break;
            }

            case 3: {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}