//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[] = {
    {"Brewed Coffee", 10, 2.50},
    {"Cappuccino", 8, 3.00},
    {"Latte", 12, 2.75},
    {"Mocha", 6, 3.25},
    {"Americano", 9, 2.25},
    {"Tea", 15, 1.50}
};

int main() {
    int i, total_items = 0, order_total = 0, item_quantity;
    char item_name[50];

    // Calculate the total number of items
    for (i = 0; i < 6; i++) {
        total_items += items[i].quantity;
    }

    // Display the total number of items
    printf("Total number of items: %d\n", total_items);

    // Get the item name and quantity
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Get the item quantity
    printf("Enter item quantity: ");
    scanf("%d", &item_quantity);

    // Find the item in the inventory
    for (i = 0; i < 6; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            items[i].quantity -= item_quantity;
            order_total += items[i].price * item_quantity;
            break;
        }
    }

    // Display the order total
    printf("Order total: $%.2f\n", order_total);

    return 0;
}