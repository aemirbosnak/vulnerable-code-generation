//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int product_count;
} Warehouse;

// Function prototypes
void initialize_warehouse(Warehouse *warehouse);
void add_product(Warehouse *warehouse);
void remove_product(Warehouse *warehouse);
void view_products(Warehouse *warehouse);
void configure_parameters(int *max_products, int *max_name_length);

int main() {
    Warehouse warehouse;
    int max_products = MAX_PRODUCTS;
    int max_name_length = MAX_NAME_LENGTH;
    char option;

    configure_parameters(&max_products, &max_name_length);
    initialize_warehouse(&warehouse);

    while (1) {
        printf("\n----- Warehouse Management System -----\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Products\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        option = getchar();
        getchar(); // Consume newline

        switch (option) {
            case '1':
                add_product(&warehouse);
                break;
            case '2':
                remove_product(&warehouse);
                break;
            case '3':
                view_products(&warehouse);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void initialize_warehouse(Warehouse *warehouse) {
    warehouse->product_count = 0;
}

void add_product(Warehouse *warehouse) {
    if (warehouse->product_count >= MAX_PRODUCTS) {
        printf("Warehouse is full, cannot add more products.\n");
        return;
    }

    Product new_product;
    printf("Enter product name: ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // Remove newline

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    getchar(); // Consume newline

    warehouse->products[warehouse->product_count++] = new_product;
    printf("Product %s added successfully.\n", new_product.name);
}

void remove_product(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter product name to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < warehouse->product_count; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            for (int j = i; j < warehouse->product_count - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->product_count--;
            found = 1;
            printf("Product %s removed successfully.\n", name);
            break;
        }
    }

    if (!found) {
        printf("Product %s not found in warehouse.\n", name);
    }
}

void view_products(Warehouse *warehouse) {
    if (warehouse->product_count == 0) {
        printf("No products in the warehouse.\n");
        return;
    }

    printf("\nProducts in Warehouse:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->product_count; i++) {
        Product *p = &warehouse->products[i];
        printf("%-20s %-10d $%-9.2f\n", p->name, p->quantity, p->price);
    }
}

void configure_parameters(int *max_products, int *max_name_length) {
    printf("Enter maximum number of products (default %d): ", MAX_PRODUCTS);
    scanf("%d", max_products);
    printf("Enter maximum name length (default %d): ", MAX_NAME_LENGTH);
    scanf("%d", max_name_length);
    getchar(); // Consume newline
}