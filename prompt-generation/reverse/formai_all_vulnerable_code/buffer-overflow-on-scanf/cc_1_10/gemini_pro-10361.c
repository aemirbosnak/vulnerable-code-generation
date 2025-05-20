//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu[][20] = {"Cappuccino", "Latte", "Espresso", "Americano", "Mocha"};
float prices[] = {2.50, 3.00, 2.00, 2.50, 3.50};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Get the number of items ordered
int get_num_items() {
    int num_items;
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);
    return num_items;
}

// Get the items ordered
void get_items(int num_items, int items[]) {
    printf("Enter the item numbers of the items you would like to order, separated by spaces: ");
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i]);
    }
}

// Calculate the total cost of the order
float calculate_total(int num_items, int items[]) {
    float total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += prices[items[i] - 1];
    }
    return total_cost;
}

// Print the receipt
void print_receipt(int num_items, int items[], float total_cost) {
    printf("\nYour receipt:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%.2f\n", menu[items[i] - 1], prices[items[i] - 1]);
    }
    printf("Total cost: $%.2f\n", total_cost);
}

// Main function
int main() {
    // Get the number of items ordered
    int num_items = get_num_items();

    // Get the items ordered
    int items[MAX_ITEMS];
    get_items(num_items, items);

    // Calculate the total cost of the order
    float total_cost = calculate_total(num_items, items);

    // Print the receipt
    print_receipt(num_items, items, total_cost);

    return 0;
}