//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char product_name[30];
    int quantity_in_stock;
    float price_per_unit;
} Item;

int main() {
    Item items[] = {{"Bananas", 50, 0.50},
                    {"Apples", 30, 0.75},
                    {"Oranges", 20, 0.60},
                    {"Grapes", 40, 1.50},
                    {"Strawberries", 15, 2.00}};
    const int num_items = sizeof(items)/sizeof(Item);
    int total_quantity = 0;
    float total_value = 0;

    printf("Welcome to the Warehouse Management System!\n\n");
    printf("Our current inventory:\n\n");
    printf("%-15s %-20s %s\n", "Product", "Quantity in Stock", "Price per Unit");
    for (int i = 0; i < num_items; i++) {
        printf("%-15s %-20d $%.2f\n", items[i].product_name, items[i].quantity_in_stock, items[i].price_per_unit);
        total_quantity += items[i].quantity_in_stock;
        total_value += items[i].quantity_in_stock * items[i].price_per_unit;
    }
    printf("\nTotal Quantity in stock: %d\n", total_quantity);
    printf("Total Value of inventory: $%.2f\n", total_value);

    printf("\nEnter a product name to check stock (or 'exit' to quit):\n");
    char product_name[30];
    while (scanf("%s", product_name) == 1 && strcmp(product_name, "exit") != 0) {
        int quantity_in_stock = -1;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(product_name, items[i].product_name) == 0) {
                quantity_in_stock = items[i].quantity_in_stock;
                break;
            }
        }
        if (quantity_in_stock == -1) {
            printf("Product not found!\n");
        } else {
            printf("We have %d '%s' in stock.\n", quantity_in_stock, product_name);
        }
        printf("\nEnter a product name to check stock (or 'exit' to quit):\n");
    }

    printf("\nThank you for using our Warehouse Management System!\n");
    return 0;
}