//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: active
// Warehouse Management System

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Define the product structure
    typedef struct {
        char name[20];
        int quantity;
        float price;
    } Product;

    // Define the warehouse structure
    typedef struct {
        char name[20];
        Product products[10];
        int total_products;
    } Warehouse;

    // Define the stock management function
    void manage_stock(Warehouse *warehouse) {
        // Print the warehouse name
        printf("Warehouse: %s\n", warehouse->name);

        // Print the products in the warehouse
        for (int i = 0; i < warehouse->total_products; i++) {
            printf("Product %d: %s\n", i + 1, warehouse->products[i].name);
            printf("Quantity: %d\n", warehouse->products[i].quantity);
            printf("Price: %.2f\n", warehouse->products[i].price);
            printf("\n");
        }

        // Ask the user for the product to be added
        printf("Enter the product name: ");
        char product_name[20];
        scanf("%s", product_name);

        // Check if the product already exists
        int product_index = -1;
        for (int i = 0; i < warehouse->total_products; i++) {
            if (strcmp(warehouse->products[i].name, product_name) == 0) {
                product_index = i;
                break;
            }
        }

        // If the product exists, update the quantity
        if (product_index != -1) {
            printf("Enter the quantity: ");
            int quantity;
            scanf("%d", &quantity);
            warehouse->products[product_index].quantity += quantity;
            printf("Product added successfully\n");
        }

        // If the product does not exist, add a new product
        else {
            printf("Enter the quantity: ");
            int quantity;
            scanf("%d", &quantity);
            printf("Enter the price: ");
            float price;
            scanf("%f", &price);
            strcpy(warehouse->products[warehouse->total_products].name, product_name);
            warehouse->products[warehouse->total_products].quantity = quantity;
            warehouse->products[warehouse->total_products].price = price;
            warehouse->total_products++;
            printf("Product added successfully\n");
        }
    }

    // Define the main function
    int main() {
        // Initialize the warehouse
        Warehouse warehouse;
        strcpy(warehouse.name, "Warehouse 1");
        warehouse.total_products = 0;

        // Manage the stock
        manage_stock(&warehouse);

        return 0;
    }