//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[30];
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 1.50},
    {"Tea", 1.25},
    {"Espresso", 2.00},
    {"Cappuccino", 2.50},
    {"Latte", 2.75}
};

// Define the order structure
struct Order {
    int item_count;
    struct MenuItem items[10];
};

// Get the user's order
void getOrder(struct Order *order) {
    printf("Welcome to the cafe!\n");
    printf("What would you like to order?\n");

    int item_count;
    printf("How many items would you like to order? ");
    scanf("%d", &item_count);

    order->item_count = item_count;

    for (int i = 0; i < item_count; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s", order->items[i].name);

        printf("Price: ");
        scanf("%f", &order->items[i].price);
    }
}

// Calculate the total price of the order
float calculateTotal(struct Order *order) {
    float total = 0;

    for (int i = 0; i < order->item_count; i++) {
        total += order->items[i].price;
    }

    return total;
}

// Print the receipt
void printReceipt(struct Order *order) {
    printf("\nYour order:\n");

    for (int i = 0; i < order->item_count; i++) {
        printf("%s: $%.2f\n", order->items[i].name, order->items[i].price);
    }

    printf("Total: $%.2f\n", calculateTotal(order));
}

// Main function
int main() {
    struct Order order;
    getOrder(&order);
    printReceipt(&order);

    return 0;
}