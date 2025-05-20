//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct item {
    char name[20];
    int price;
    int quantity;
} item_t;

// Define a function to calculate the total cost of an item
int calculate_cost(item_t item) {
    return item.price * item.quantity;
}

// Define a function to print the bill
void print_bill(item_t items[], int num_items) {
    printf("------------------------------------------------\n");
    printf("                          Bill\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d x %d = %d\n", items[i].name, items[i].quantity, items[i].price, calculate_cost(items[i]));
    }
    printf("------------------------------------------------\n");
    printf("Total Cost: %d\n", calculate_total_cost(items, num_items));
    printf("------------------------------------------------\n");
}

// Define a function to calculate the total cost of all items
int calculate_total_cost(item_t items[], int num_items) {
    int total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += calculate_cost(items[i]);
    }
    return total_cost;
}

int main() {
    // Create an array of items
    item_t items[] = {
        {"Coffee", 50, 3},
        {"Tea", 40, 2},
        {"Juice", 30, 4}
    };

    // Print the bill
    print_bill(items, 3);

    return 0;
}