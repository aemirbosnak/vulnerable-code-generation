//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 5, 2.5},
    {"Tea", 3, 3.0},
    {"Juice", 4, 2.0},
    {"Soda", 2, 2.2},
    {"Water", 1, 1.5},
    {"Biscuits", 4, 1.2},
    {"Cookies", 3, 1.8},
    {"Scones", 2, 2.0},
    {"Muffins", 1, 2.7},
    {"Pancakes", 3, 3.5}
};

int main() {
    int i, order_count = 0, total_price = 0;
    char item_name[20];
    int item_quantity;

    // Print menu
    printf("\nWelcome to the Coffee Shop!\n\n");
    printf("Items:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%s - %d - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    // Get user order
    printf("\nEnter item name: ");
    scanf("%s", item_name);

    // Find item and check quantity
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            if (items[i].quantity > 0) {
                printf("Enter quantity: ");
                scanf("%d", &item_quantity);

                // Calculate item price
                float item_price = items[i].price * item_quantity;

                // Add item to order
                order_count++;
                total_price += item_price;
                printf("Item added to order: %s (%d) - $%.2f\n", items[i].name, item_quantity, item_price);
            } else {
                printf("Sorry, item out of stock.\n");
            }
        }
    }

    // Print order summary
    printf("\nOrder Summary:\n");
    printf("Number of items: %d\n", order_count);
    printf("Total price: $%.2f\n", total_price);

    // Calculate tax and total cost
    float tax = 0.08 * total_price;
    float total_cost = total_price + tax;

    // Print tax and total cost
    printf("Tax: $%.2f\n", tax);
    printf("Total cost: $%.2f\n", total_cost);

    return 0;
}