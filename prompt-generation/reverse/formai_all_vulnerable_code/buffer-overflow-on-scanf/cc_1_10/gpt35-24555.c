//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

// Struct to store item details
typedef struct {
    char name[20];
    int quantity;
    float price;
} item;

// Initialize menu items
item menu[MAX_ITEMS] = {
    {"Coffee", 10, 2.50},
    {"Tea", 15, 1.25},
    {"Sandwich", 5, 5.00},
    {"Pastry", 20, 2.50},
    {"Donut", 30, 1.50}
};

int main() {
    int num_items = sizeof(menu) / sizeof(item);
    int order_qty[num_items];
    float order_total = 0;

    printf("*** Welcome to the Future Cafe! ***\n");
    printf("Here is our menu:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }

    printf("\nPlease enter your order below:\n");

    // Take customer's order
    for (int i = 0; i < num_items; i++) {
        printf("%s - Enter qty: ", menu[i].name);
        scanf("%d", &order_qty[i]);
        order_total += order_qty[i] * menu[i].price;

        // Check if ordered qty is greater than available qty
        if (order_qty[i] > menu[i].quantity) {
            printf("We don't have enough %s in stock. Your order has been adjusted accordingly.\n", menu[i].name);
            order_qty[i] = menu[i].quantity;
            order_total -= (order_qty[i] * menu[i].price);
        }

        // Update available qty
        menu[i].quantity -= order_qty[i];
    }

    // Print invoice
    printf("\n\n*** INVOICE ***\n");

    for (int i = 0; i < num_items; i++) {
        if (order_qty[i] > 0) {
            printf("%s x %d - $%.2f\n", menu[i].name, order_qty[i], (order_qty[i] * menu[i].price));
        }
    }

    // Add tax and calculate total amount
    float tax = order_total * 0.07;
    float total_amount = order_total + tax;
    printf("\nTax (7%%) - $%.2f\n", tax);
    printf("Total Amount - $%.2f\n", total_amount);

    printf("\n\nThank you for ordering from Future Cafe!\n");

    return 0;
}