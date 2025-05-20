//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Define global constants
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 50

// Define structures
typedef struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];
} product_t;

typedef struct warehouse {
    product_t products[MAX_PRODUCTS];
    int num_products;
} warehouse_t;

// Function prototypes
void add_product(warehouse_t *warehouse);
void remove_product(warehouse_t *warehouse);
void list_products(warehouse_t warehouse);
void search_product(warehouse_t warehouse);
void print_menu();

// Define main function
int main() {
    warehouse_t warehouse = { {}, 0 };
    int choice;

    while (1) {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&warehouse);
                break;
            case 2:
                remove_product(&warehouse);
                break;
            case 3:
                list_products(warehouse);
                break;
            case 4:
                search_product(warehouse);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Define function to add a product to the warehouse
void add_product(warehouse_t *warehouse) {
    product_t product;

    printf("Enter the name of the product: ");
    scanf("%s", product.name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &product.quantity);

    printf("Enter the location of the product: ");
    scanf("%s", product.location);

    if (warehouse->num_products == MAX_PRODUCTS) {
        printf("The warehouse is full. Cannot add more products.\n");
    } else {
        warehouse->products[warehouse->num_products++] = product;
        printf("Product added to the warehouse successfully.\n");
    }
}

// Define function to remove a product from the warehouse
void remove_product(warehouse_t *warehouse) {
    char name[MAX_NAME_LENGTH];
    int i, index = -1;

    printf("Enter the name of the product to remove: ");
    scanf("%s", name);

    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("The product is not found in the warehouse.\n");
    } else {
        warehouse->products[index] = warehouse->products[--warehouse->num_products];
        printf("Product removed from the warehouse successfully.\n");
    }
}

// Define function to list all products in the warehouse
void list_products(warehouse_t warehouse) {
    int i;

    if (warehouse.num_products == 0) {
        printf("The warehouse is empty.\n");
    } else {
        printf("List of products in the warehouse:\n");
        for (i = 0; i < warehouse.num_products; i++) {
            printf("%s - %d - %s\n", warehouse.products[i].name,
                   warehouse.products[i].quantity, warehouse.products[i].location);
        }
    }
}

// Define function to search for a product in the warehouse
void search_product(warehouse_t warehouse) {
    char name[MAX_NAME_LENGTH];
    int i;

    printf("Enter the name of the product to search: ");
    scanf("%s", name);

    for (i = 0; i < warehouse.num_products; i++) {
        if (strcmp(warehouse.products[i].name, name) == 0) {
            printf("Product found in the warehouse. Quantity: %d, Location: %s\n",
                   warehouse.products[i].quantity, warehouse.products[i].location);
            return;
        }
    }

    printf("The product is not found in the warehouse.\n");
}

// Define function to print the menu
void print_menu() {
    printf("\n");
    printf("Warehouse management system\n");
    printf("---------------------------\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. List all products\n");
    printf("4. Search for a product\n");
    printf("5. Exit\n");
}