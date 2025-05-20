//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 5, 3.0},
    {"Tea", 2, 2.5},
    {"Juice", 3, 2.0},
    {"Water", 4, 1.5},
    {"Smoothie", 1, 4.0},
    {"Sandwich", 3, 3.5},
    {"Pancake", 2, 2.0},
    {"Pizza", 1, 4.0},
    {"Pasta", 2, 3.0},
    {"Salad", 3, 2.5}
};

int main() {
    int i, order_num = 1, item_num, total_price = 0;
    char item_name[20];

    printf("Welcome to Caffeinated Dreams!\n");

    // Loop to take customer order
    while (1) {
        printf("Enter item name: ");
        scanf("%s", item_name);

        // Search for item
        for (i = 0; i < MAX_ITEMS; i++) {
            if (strcmp(item_name, items[i].name) == 0) {
                item_num = i;
                break;
            }
        }

        // If item not found, display error
        if (item_num == -1) {
            printf("Error: Item not found.\n");
            continue;
        }

        // Get item quantity
        printf("Enter quantity: ");
        scanf("%d", &items[item_num].quantity);

        // Calculate item total price
        float item_total_price = items[item_num].quantity * items[item_num].price;

        // Add item total price to total price
        total_price += item_total_price;

        // Print item confirmation
        printf("Item added to order: %s (%d) @ $%.2f\n", items[item_num].name, items[item_num].quantity, items[item_num].price);

        // Ask customer if they want to continue ordering
        char continue_order;
        printf("Do you want to continue ordering? (Y/N): ");
        scanf("%c", &continue_order);

        // Break out of loop if customer does not want to continue ordering
        if (continue_order != 'Y') {
            break;
        }
    }

    // Calculate total cost
    float total_cost = total_price + 0.10 * total_price;

    // Print order summary
    printf("Order Summary:\n");
    printf("Order Number: %d\n", order_num);
    printf("Total Items: %d\n", total_price);
    printf("Total Cost: $%.2f\n", total_cost);

    // Prompt customer for payment
    printf("Please pay the total cost of $%.2f.\n", total_cost);

    return 0;
}