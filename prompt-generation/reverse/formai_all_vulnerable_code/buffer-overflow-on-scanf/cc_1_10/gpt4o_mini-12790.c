//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product warehouse[MAX_PRODUCTS];
int product_count = 0;

void addProduct() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }
    
    Product new_product;
    new_product.id = product_count + 1;

    printf("Enter product name: ");
    scanf("%s", new_product.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    
    warehouse[product_count] = new_product;
    product_count++;
    
    printf("Product '%s' added successfully!\n", new_product.name);
}

void viewProducts() {
    if (product_count == 0) {
        printf("No products found in the warehouse.\n");
        return;
    }

    printf("\nWarehouse Inventory:\n");
    printf("------------------------------------------------------\n");
    printf("| ID | Name                          | Quantity | Price |\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < product_count; i++) {
        printf("| %2d | %-30s | %8d | $%.2f |\n", 
                warehouse[i].id, 
                warehouse[i].name, 
                warehouse[i].quantity, 
                warehouse[i].price);
    }
    printf("------------------------------------------------------\n");
}

void updateStock() {
    int id, quantity;
    printf("Enter product ID to update stock: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > product_count) {
        printf("Invalid product ID!\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    warehouse[id - 1].quantity = quantity;
    printf("Stock updated for product '%s'. New Quantity: %d\n", 
           warehouse[id - 1].name, 
           warehouse[id - 1].quantity);
}

void menu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Stock\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                printf("Exiting the Warehouse Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}