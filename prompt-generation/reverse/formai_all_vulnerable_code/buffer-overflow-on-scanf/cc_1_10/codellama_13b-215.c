//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: standalone
// warehouse.c

#include <stdio.h>
#include <stdlib.h>

// Structures

typedef struct product {
    int id;
    char name[50];
    float price;
} product;

typedef struct order {
    int id;
    int product_id;
    int quantity;
    float total_price;
} order;

// Functions

void display_menu() {
    printf("Welcome to the Warehouse Management System\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. Place order\n");
    printf("5. View inventory\n");
    printf("6. View orders\n");
    printf("7. Exit\n");
}

void add_product(product* products, int* num_products) {
    // Get product information
    int id = (*num_products) + 1;
    char name[50];
    float price;
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);

    // Add product to the inventory
    products[*num_products].id = id;
    strcpy(products[*num_products].name, name);
    products[*num_products].price = price;

    // Increment the number of products
    (*num_products)++;
}

void remove_product(product* products, int* num_products) {
    // Get product information
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    // Remove product from the inventory
    for (int i = 0; i < *num_products; i++) {
        if (products[i].id == id) {
            products[i] = products[*num_products - 1];
            (*num_products)--;
            break;
        }
    }
}

void update_product(product* products, int* num_products) {
    // Get product information
    int id;
    char name[50];
    float price;
    printf("Enter product ID: ");
    scanf("%d", &id);
    printf("Enter new product name: ");
    scanf("%s", name);
    printf("Enter new product price: ");
    scanf("%f", &price);

    // Update product information
    for (int i = 0; i < *num_products; i++) {
        if (products[i].id == id) {
            strcpy(products[i].name, name);
            products[i].price = price;
            break;
        }
    }
}

void place_order(order* orders, int* num_orders, product* products, int* num_products) {
    // Get order information
    int id = (*num_orders) + 1;
    int product_id;
    int quantity;
    printf("Enter product ID: ");
    scanf("%d", &product_id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Check if the product exists
    int product_found = 0;
    for (int i = 0; i < *num_products; i++) {
        if (products[i].id == product_id) {
            product_found = 1;
            break;
        }
    }

    // Add order to the list of orders
    if (product_found) {
        orders[*num_orders].id = id;
        orders[*num_orders].product_id = product_id;
        orders[*num_orders].quantity = quantity;
        orders[*num_orders].total_price = products[product_id - 1].price * quantity;
        (*num_orders)++;
    }
}

void view_inventory(product* products, int* num_products) {
    // Print the inventory
    printf("Inventory:\n");
    for (int i = 0; i < *num_products; i++) {
        printf("%d: %s - $%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void view_orders(order* orders, int* num_orders) {
    // Print the orders
    printf("Orders:\n");
    for (int i = 0; i < *num_orders; i++) {
        printf("%d: %d - %d - $%.2f\n", orders[i].id, orders[i].product_id, orders[i].quantity, orders[i].total_price);
    }
}

int main() {
    // Declare variables
    product products[100];
    int num_products = 0;
    order orders[100];
    int num_orders = 0;

    // Main loop
    int choice;
    do {
        // Display menu
        display_menu();

        // Get user input
        scanf("%d", &choice);

        // Execute the chosen option
        switch (choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                update_product(products, &num_products);
                break;
            case 4:
                place_order(orders, &num_orders, products, &num_products);
                break;
            case 5:
                view_inventory(products, &num_products);
                break;
            case 6:
                view_orders(orders, &num_orders);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);

    return 0;
}