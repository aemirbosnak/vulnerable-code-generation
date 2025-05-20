//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct product {
        int id;
        char name[50];
        int quantity;
    };

    struct warehouse {
        int id;
        char name[50];
        int capacity;
        struct product *products;
    };

    struct order {
        int id;
        char name[50];
        int quantity;
        struct product *product;
    };

    struct inventory {
        struct warehouse *warehouses;
        struct order *orders;
    };

    void print_warehouse(struct warehouse *warehouse) {
        printf("Warehouse ID: %d\n", warehouse->id);
        printf("Name: %s\n", warehouse->name);
        printf("Capacity: %d\n", warehouse->capacity);
        printf("Products: %d\n", warehouse->products);
    }

    void print_order(struct order *order) {
        printf("Order ID: %d\n", order->id);
        printf("Name: %s\n", order->name);
        printf("Quantity: %d\n", order->quantity);
        printf("Product ID: %d\n", order->product->id);
        printf("Product Name: %s\n", order->product->name);
        printf("Product Quantity: %d\n", order->product->quantity);
    }

    void print_inventory(struct inventory *inventory) {
        printf("Inventory:\n");
        for (int i = 0; i < inventory->warehouses->capacity; i++) {
            print_warehouse(&inventory->warehouses[i]);
        }
        printf("Orders:\n");
        for (int i = 0; i < inventory->orders->quantity; i++) {
            print_order(&inventory->orders[i]);
        }
    }

    int main() {
        struct warehouse warehouses[3];
        struct order orders[5];
        struct inventory inventory;

        warehouses[0].id = 1;
        strcpy(warehouses[0].name, "Warehouse 1");
        warehouses[0].capacity = 100;
        warehouses[0].products = (struct product *) malloc(100 * sizeof(struct product));
        warehouses[0].products[0].id = 1;
        strcpy(warehouses[0].products[0].name, "Product 1");
        warehouses[0].products[0].quantity = 50;
        warehouses[0].products[1].id = 2;
        strcpy(warehouses[0].products[1].name, "Product 2");
        warehouses[0].products[1].quantity = 30;

        warehouses[1].id = 2;
        strcpy(warehouses[1].name, "Warehouse 2");
        warehouses[1].capacity = 200;
        warehouses[1].products = (struct product *) malloc(200 * sizeof(struct product));
        warehouses[1].products[0].id = 3;
        strcpy(warehouses[1].products[0].name, "Product 3");
        warehouses[1].products[0].quantity = 100;
        warehouses[1].products[1].id = 4;
        strcpy(warehouses[1].products[1].name, "Product 4");
        warehouses[1].products[1].quantity = 80;

        warehouses[2].id = 3;
        strcpy(warehouses[2].name, "Warehouse 3");
        warehouses[2].capacity = 300;
        warehouses[2].products = (struct product *) malloc(300 * sizeof(struct product));
        warehouses[2].products[0].id = 5;
        strcpy(warehouses[2].products[0].name, "Product 5");
        warehouses[2].products[0].quantity = 150;
        warehouses[2].products[1].id = 6;
        strcpy(warehouses[2].products[1].name, "Product 6");
        warehouses[2].products[1].quantity = 120;

        orders[0].id = 1;
        strcpy(orders[0].name, "Order 1");
        orders[0].quantity = 20;
        orders[0].product = &warehouses[0].products[0];
        orders[1].id = 2;
        strcpy(orders[1].name, "Order 2");
        orders[1].quantity = 30;
        orders[1].product = &warehouses[1].products[0];
        orders[2].id = 3;
        strcpy(orders[2].name, "Order 3");
        orders[2].quantity = 40;
        orders[2].product = &warehouses[2].products[0];
        orders[3].id = 4;
        strcpy(orders[3].name, "Order 4");
        orders[3].quantity = 50;
        orders[3].product = &warehouses[0].products[1];
        orders[4].id = 5;
        strcpy(orders[4].name, "Order 5");
        orders[4].quantity = 60;
        orders[4].product = &warehouses[1].products[1];

        inventory.warehouses = warehouses;
        inventory.orders = orders;

        print_inventory(&inventory);

        return 0;
    }