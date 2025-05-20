//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the menu items and their prices
#define MENU_ITEM_COUNT 5
struct menu_item {
    char name[50];
    float price;
};
struct menu_item menu[MENU_ITEM_COUNT] = {{"Coffee", 2.50}, {"Tea", 1.50}, {"Cake", 3.50}, {"Sandwich", 4.50}, {"Juice", 2.00}};

int main() {
    // Initialize the billing system
    int customer_count = 0;
    int order_count = 0;
    float total_revenue = 0.0;
    time_t start_time = time(NULL);

    // Loop until the cafe closes
    while (1) {
        // Check the current time
        time_t current_time = time(NULL);
        if (current_time >= start_time + 8 * 60 * 60) { // Cafe closes at 8PM
            break;
        }

        // Wait for a customer to arrive
        printf("Waiting for customer...\n");
        fflush(stdout);
        int customer_id = customer_count++;

        // Take the customer's order
        int order_id = order_count++;
        int item_count = 0;
        float order_total = 0.0;
        printf("Customer %d has arrived.\n", customer_id);
        fflush(stdout);
        while (1) {
            printf("Enter the ID of the item you want to order (0 to quit):\n");
            fflush(stdout);
            int item_id;
            scanf("%d", &item_id);
            if (item_id == 0) {
                break;
            } else if (item_id >= MENU_ITEM_COUNT) {
                printf("Invalid item ID.\n");
            } else {
                menu[item_id].price += 0.25; // Apply a 25% markup
                order_total += menu[item_id].price;
                item_count++;
                printf("You ordered %s for $%.2f.\n", menu[item_id].name, menu[item_id].price);
                fflush(stdout);
            }
        }

        // Print the order summary and collect payment
        printf("Customer %d's order (%d items) totals $%.2f.\n", customer_id, item_count, order_total);
        fflush(stdout);
        printf("Please pay $%.2f.\n", order_total);
        fflush(stdout);

        // Update the revenue and order counts
        total_revenue += order_total;
        order_count++;

        // Wait for the customer to leave
        printf("Customer %d has left.\n", customer_id);
        fflush(stdout);
    }

    // Print the final revenue and close the cafe
    printf("Total revenue for the day: $%.2f\n", total_revenue);
    fflush(stdout);
    return 0;
}