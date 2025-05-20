//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for Products in the Warehouse
typedef struct Product {
    int prod_id;
    char prod_name[30];
    float prod_price;
    int prod_quantity;
} product_t;

// Global variables
product_t warehouse[100]; // Warehouse array can hold maximum 100 products
int num_products = 0; // Counter for number of products currently in warehouse

// Function to add a new product to the warehouse
void add_product() {
    product_t new_product;
    printf("\nEnter product details:\n");
    printf("Product ID: ");
    scanf("%d", &new_product.prod_id);
    printf("Product Name: ");
    scanf("%s", new_product.prod_name);
    printf("Product Price: ");
    scanf("%f", &new_product.prod_price);
    printf("Product Quantity: ");
    scanf("%d", &new_product.prod_quantity);
    warehouse[num_products++] = new_product;
    printf("\nProduct Added!\n\n");
}

// Function to display all products currently in the warehouse
void display_products() {
    printf("\n%-7s%-30s%-15s%-10s\n\n", "ID", "Product Name", "Price", "Quantity");
    for(int i=0; i<num_products; i++) {
        printf("%-7d%-30s%-15.2f%-10d\n", warehouse[i].prod_id, warehouse[i].prod_name, warehouse[i].prod_price, warehouse[i].prod_quantity);
    }
    printf("\n");
}

// Function to search for a product by ID and display its details
void search_product() {
    int prod_id;
    int found = 0;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &prod_id);
    for(int i=0; i<num_products; i++) {
        if(warehouse[i].prod_id == prod_id) {
            printf("\n%-7s%-30s%-15s%-10s\n\n", "ID", "Product Name", "Price", "Quantity");
            printf("%-7d%-30s%-15.2f%-10d\n", warehouse[i].prod_id, warehouse[i].prod_name, warehouse[i].prod_price, warehouse[i].prod_quantity);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("\nProduct not found!\n\n");
}

int main() {
    int choice;

    printf("\n*** Warehouse Management System ***\n\n");

    // Menu-driven program loop
    do {
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("\nExiting program...\n\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, please try again!\n\n");
                break;
        }
    } while(1);

    return 0;
}